// This is the main file for the game logic and function
//
//

#include <iostream>
#include <iomanip>
#include <sstream>

#include "game.h"
#include "detectors.h"
#include "Framework\console.h"
#include "main_menu.h"
#include "map.h"
#include "enemy.h"
#include "message.h"
#include "pause.h"
#include "PlayBGM.h"
#include "Framework\timer.h"
#include "Score.h"
#include "EndGame.h"


#include <Windows.h>

#include <string>
#include <fstream>
#include <Windows.h>

using  std::string;
using std::ifstream;

double  g_dElapsedTime;
double  g_dDeltaTime;
bool g_abKeyPressed[K_COUNT];
bool g_Collision;
char MAP_LEVEL[50][150];

// Game specific variables here
int mapLevelno = 11;

SGameChar g_sChar;

EGAMESTATES g_eGameState = S_MENU;
double  g_dBounceTime; // this is to prevent key bouncing, so we won't trigger keypresses more than once


// Console object
Console g_Console(100, 50, "SP1 Framework");

//--------------------------------------------------------------
// Purpose  : Initialisation function
//            Initialize variables, allocate memory, load data from file, etc. 
//            This is called once before entering into your main loop
// Input    : void
// Output   : void
//--------------------------------------------------------------
void init(void)
{
    // Set precision for floating point output
    g_dElapsedTime = 0.0;
    g_dBounceTime = 0.0;

    // sets the initial state for the game

    g_eGameState = S_MENU;
	//TimerInit=true;

    g_sChar.m_bActive = true;
	mapReadlevel();
    // sets the width, height and the font name to use in the console
    g_Console.setConsoleFont(0, 16, L"Consolas");
	Play();
}


//--------------------------------------------------------------
// Purpose  : Reset before exiting the program
//            Do your clean up of memory here
//            This is called once just before the game exits
// Input    : Void
// Output   : void
//--------------------------------------------------------------

void shutdown()
{
    // Reset to white text on black background
    colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

    g_Console.clearBuffer();
	DeleteEngine();
}

//--------------------------------------------------------------
// Purpose  : Getting all the key press states
//            This function checks if any key had been pressed since the last time we checked
//            If a key is pressed, the value for that particular key will be true
//
//            Add more keys to the enum in game.h if you need to detect more keys
//            To get other VK key defines, right click on the VK define (e.g. VK_UP) and choose "Go To Definition" 
//            For Alphanumeric keys, the values are their ascii values (uppercase).
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void getInput(void)
{    
    g_abKeyPressed[K_UP]     = isKeyPressed(VK_UP);
    g_abKeyPressed[K_DOWN]   = isKeyPressed(VK_DOWN);
    g_abKeyPressed[K_LEFT]   = isKeyPressed(VK_LEFT);
    g_abKeyPressed[K_RIGHT]  = isKeyPressed(VK_RIGHT);
    g_abKeyPressed[K_SPACE]  = isKeyPressed(VK_SPACE);
    g_abKeyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
    g_abKeyPressed[K_RETURN] = isKeyPressed(VK_RETURN);
}

//--------------------------------------------------------------
// Purpose  : Update function
//            This is the update function
//            double dt - This is the amount of time in seconds since the previous call was made
//
//            Game logic should be done here.
//            Such as collision checks, determining the position of your game characters, status updates, etc
//            If there are any calls to write to the console here, then you are doing it wrong.
//
//            If your game has multiple states, you should determine the current state, and call the relevant function here.
//
// Input    : dt = deltatime
// Output   : void
//--------------------------------------------------------------
void update(double dt)
{
    // get the delta time
	if(mapLevelno!= 12)
	{
		g_dElapsedTime += dt;
		g_dDeltaTime = dt;
	}
	
    switch (g_eGameState)
    {
        case S_SPLASHSCREEN : splashScreenWait(); // game logic for the splash screen
            break;
        case S_GAME: gameplay(); // gameplay logic when we are in the game
            break;
        case S_MENU: startGame();
            break;
		case S_RELOAD: JumpScare();
			break;
		case S_PAUSE: PauseUpdate();
			break;
		case S_LEVELUP: MessageUpdate();
			break;
		case S_ENDSCREEN: EndScreenUpdate();
			//break;
    } 
}
//--------------------------------------------------------------
// Purpose  : Render function is to update the console screen
//            At this point, you should know exactly what to draw onto the screen.
//            Just draw it!
//            To get an idea of the values for colours, look at console.h and the URL listed there
// Input    : void
// Output   : void
//--------------------------------------------------------------
void render()
{

    clearScreen();      // clears the current screen and draw from scratch 
    switch (g_eGameState)
    {
        case S_SPLASHSCREEN: renderSplashScreen();
            break;
        case S_MENU: readMenu();
            break;
        case S_GAME: renderGame();
            break;
		case S_RELOAD: ScareRender();
			break;
		case S_PAUSE: PauseScreen();
			break;
		case S_LEVELUP: MessageScreen();
			break;
        case S_ENDSCREEN: EndScreen();
            break;
    }
    renderToScreen();   // dump the contents of the buffer to the screen, one frame worth of game
}

void splashScreenWait()    // waits for time to pass in splash screen
{
    if (g_abKeyPressed[K_SPACE]) // wait for 5 seconds to switch to game mode, else do nothing
	{
        g_eGameState = S_GAME;
	}
}


void gameplay()            // gameplay logic
{
    processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
    moveCharacter();    // moves the character, collision detection, physics, etc
	checkEnd();
	checkPause();
	ENEMY_COLLISION();
	ENEMY_MEET();
	UNLOCKEDDOOR(mapLevelno, g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y);
	UNLOCK_UPDATE();// sound can be played here too. 
	update_comments(mapLevelno);
}

void moveCharacter()
{
    bool bSomethingHappened = false;
    if (g_dBounceTime > g_dElapsedTime)
        return;
    // Updating the location of the character based on the key press

    if (g_abKeyPressed[K_UP] && g_sChar.m_cLocation.Y > 0)
	{
		bSomethingHappened = true;
		checkCollisionUp(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y);
		if(g_Collision == false)
		    g_sChar.m_cLocation.Y--;
    }
    if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X > 0)
    {
		bSomethingHappened = true;
		checkCollisionLeft(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y);
		if(g_Collision == false)
		     g_sChar.m_cLocation.X--; 
    }
    if (g_abKeyPressed[K_DOWN] && g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1)
    {
		bSomethingHappened = true;
		checkCollisionDown(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y);
		if(g_Collision == false)
		    g_sChar.m_cLocation.Y++; 
    }
    if (g_abKeyPressed[K_RIGHT] && g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1)
    {
		bSomethingHappened = true;
		checkCollisionRight(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y);
		if(g_Collision == false)
		    g_sChar.m_cLocation.X++;
    }
    if (g_abKeyPressed[K_SPACE])
    {
        g_sChar.m_bActive = !g_sChar.m_bActive;
        bSomethingHappened = true;
    }
	checkDoor(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y);
	
    if (bSomethingHappened)
    {
        // set the bounce time to some time in the future to prevent accidental triggers
        g_dBounceTime = g_dElapsedTime + 0.000; // 125ms should be enough
    }
}

void processUserInput()
{
    // quits the game if player hits the escape key
}

void clearScreen()
{
    // Clears the buffer with this colour attribute
    g_Console.clearBuffer(0x0F);
}


void renderGame()
{
    renderMap();        // renders the map to the buffer first
    renderCharacter();  // renders the character into the buffer
	renderFramerate();
}

void renderMap()
{
   
    clearScreen();// clear previous screen
	printMap(); //prints the map
	RENDER_KD(); //for the locked doors
	KEY_RENDER(); //for the keys
    colour(0x0F);
    cls();
    //render the game
}

void renderCharacter()
{
    // Draw the location of the character

    WORD charColor = 0x0C;
	printCharacter();
	ENEMY_PRINT();
}

void renderFramerate()
{
    COORD c;
    // displays the framerate
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(3);
    ss << 1.0 / g_dDeltaTime << "fps";
    c.X = g_Console.getConsoleSize().X - 9;
    c.Y = 0;
    g_Console.writeToBuffer(c, ss.str());

    // displays the elapsed time
    ss.str("");
    ss << g_dElapsedTime << "secs have passed";
    c.X = 0;
    c.Y = 0;
    g_Console.writeToBuffer(c, ss.str(), 0x0F);
}
void renderToScreen()
{
    // Writes the buffer to the console, hence you will see what you have written
   g_Console.flushBufferToConsole();

}


void startGame()
{
    if (g_abKeyPressed[K_RETURN])
    {
		 g_eGameState = S_SPLASHSCREEN;
       
    }
}
