// This is the main file for the game logic and function
//
//
#include "game.h"
#include "detectors.h"
#include "Framework\console.h"
#include "main_menu.h"
#include <iostream>
#include <iomanip>
#include <sstream>

#include "map.h"
#include "enemy.h"
#include "comments.h"



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
bool pausemovement = false;
bool messageshown = false;
bool printmap = true;
bool g_Scare = false;
char MAP_LEVEL[50][150];
int MapHeight;
int MapWidth;

string line;
string linemenu;
ifstream myfile;
ifstream mymenu;
const int MenuH = 16;
const int MenuW = 58;
char MENU[MenuH][MenuW];
char MAZE_LEVEL_ZERO[20][150]; 

void mapReadlevelzero()
{
 MapHeight = 7;
 MapWidth = 60;
 string maze;
 ifstream catridge;
 catridge.open("level0.txt");
 for (int i = 0;i < MapHeight;++i)
	{
		getline(catridge,maze);
		for(int j = 0,a  = 0; j < MapWidth, a <maze.length(); ++j,++a)
	  {
		  switch(maze[a])
		  {
		  case'#': MAZE_LEVEL_ZERO[i][j] =  219;
			  break;
		  case' ': MAZE_LEVEL_ZERO[i][j] = ' ';
			  break;
		  case'E': MAZE_LEVEL_ZERO[i][j] = 'E';
			  break;
		  }
		}
	}
}
void mapReadlevelone()
{
 MapHeight = 7;
 MapWidth = 60;
 string maze;
 ifstream catridge;
 catridge.open("level1.txt");
 for (int i = 0;i < MapHeight;++i)
	{
		getline(catridge,maze);
		for(int j = 0,a  = 0; j < MapWidth, a <maze.length(); ++j,++a)
	  {
		  switch(maze[a])
		  {
		  case'#': MAZE_LEVEL_ZERO[i][j] = 219;
			  break;
		  case' ': MAZE_LEVEL_ZERO[i][j] = ' ';
			  break;
		  case'N': MAZE_LEVEL_ZERO[i][j] = 'N';
			  break;
			  case'E': MAZE_LEVEL_ZERO[i][j] = 'E';
			  break;
		  }
		}
	}
}



// Game specific variables here
int mapLevelno = 0;
SGameChar   g_sChar;
SGameChar g_sEnemyOne;
SGameChar g_sEnemyTwo;
SGameChar g_sEnemyThree;
SGameChar g_sEnemyFour;
SGameChar g_sEnemyFive;
SGameChar g_sEnemySix;

EGAMESTATES g_eGameState = S_SPLASHSCREEN;
double  g_dBounceTime; // this is to prevent key bouncing, so we won't trigger keypresses more than once


// Console object
Console g_Console(80, 50, "SP1 Framework");

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

    //g_eGameState = S_SPLASHSCREEN;

    g_eGameState = S_MENU;


    g_sChar.m_cLocation.X = 3;
    g_sChar.m_cLocation.Y = 4;

    g_sChar.m_bActive = true;
	mapReadlevel();
    // sets the width, height and the font name to use in the console
    g_Console.setConsoleFont(0, 16, L"Consolas");
}



void checkCollisionUp()
{
	if(MAZE_LEVEL_ZERO[g_sChar.m_cLocation.Y-1][g_sChar.m_cLocation.X] == (char)219 )
		g_Collision = true;
	else
		g_Collision = false;
}
void checkCollisionDown()
{
	if(MAZE_LEVEL_ZERO[g_sChar.m_cLocation.Y+1][g_sChar.m_cLocation.X] == (char)219)
		g_Collision = true;
	else
		g_Collision = false;
}
void checkCollisionLeft()
{
	if(MAZE_LEVEL_ZERO[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X-1] == (char)219)
		g_Collision = true;
	else
		g_Collision = false;
}
void checkCollisionRight()
{
	if(MAZE_LEVEL_ZERO[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X+1] == (char)219)
		g_Collision = true;
	else
		g_Collision = false;
}


 
// g_Console.writeToBuffer(g_cWalls, '#',0xA2);
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
    g_dElapsedTime += dt;
    g_dDeltaTime = dt;
	update_comments(mapLevelno);
	ENEMY_MOVEMENT(mapLevelno);
	ENEMY_MEET();
	JumpScare();
    switch (g_eGameState)
    {
        case S_SPLASHSCREEN : splashScreenWait(); // game logic for the splash screen
            break;
        case S_GAME: gameplay(); // gameplay logic when we are in the game
            break;
        case S_MENU: startGame();
            break;
    } 
	checkEnd();
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
    }
    renderFramerate();  // renders debug information, frame rate, elapsed time, etc
    renderToScreen();   // dump the contents of the buffer to the screen, one frame worth of game
}

void splashScreenWait()    // waits for time to pass in splash screen
{
    if (g_dElapsedTime > 2.0) // wait for 3 seconds to switch to game mode, else do nothing
        g_eGameState = S_GAME;
}

void gameplay()            // gameplay logic
{
    processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
    moveCharacter();    // moves the character, collision detection, physics, etc
                        // sound can be played here too.
}

void moveCharacter()
{
    bool bSomethingHappened = false;
	if (pausemovement == true)
		return;
    if (g_dBounceTime > g_dElapsedTime)
        return;
    // Updating the location of the character based on the key press
    // providing a beep sound whenver we shift the character

    if (g_abKeyPressed[K_UP] && g_sChar.m_cLocation.Y > 0)
	{
		 //Beep(1440, 30);
		bSomethingHappened = true;
		checkCollisionUp(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y);
		if(g_Collision == false)
		    g_sChar.m_cLocation.Y--;
    }
    if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X > 0)
    {
        //Beep(1440, 30);
		bSomethingHappened = true;
		checkCollisionLeft(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y);
		if(g_Collision == false)
		     g_sChar.m_cLocation.X--; 
    }
    if (g_abKeyPressed[K_DOWN] && g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1)
    {
        //Beep(1440, 30);
		bSomethingHappened = true;
		checkCollisionDown(g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y);
		if(g_Collision == false)
		    g_sChar.m_cLocation.Y++; 
    }
    if (g_abKeyPressed[K_RIGHT] && g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1)
    {
        //Beep(1440, 30);
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
        g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
    }
}

void processUserInput()
{
    // quits the game if player hits the escape key
    if (g_abKeyPressed[K_ESCAPE])
        g_bQuitGame = true;    
}

void clearScreen()
{
    // Clears the buffer with this colour attribute
    g_Console.clearBuffer(0x0F);
}

void renderSplashScreen()  // renders the splash screen
{
    COORD c = g_Console.getConsoleSize();
    c.Y /= 3;
    c.X = c.X / 2 - 9;
    g_Console.writeToBuffer(c, "A game in 3 seconds", 0x03);
    c.Y += 1;
    c.X = g_Console.getConsoleSize().X / 2 - 20;
    g_Console.writeToBuffer(c, "Press <Space> to change character colour", 0x09);
    c.Y += 1;
    c.X = g_Console.getConsoleSize().X / 2 - 9;
    g_Console.writeToBuffer(c, "Press 'Esc' to quit", 0x09);
}

void renderGame()
{
    renderMap();        // renders the map to the buffer first
    renderCharacter();  // renders the character into the buffer
}

void renderMap()
{
   
    // clear previous screen
	printMap();
    colour(0x0F);
    cls();

    //render the game
}

void renderCharacter()
{
    // Draw the location of the character

    WORD charColor = 0x0C;
	printCharacter();
	ENEMY_PRINT(mapLevelno);
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
   /*ss.str("");
    ss << g_dElapsedTime << "secs";
    c.X = 0;
    c.Y = 0;
    g_Console.writeToBuffer(c, ss.str(), 0x59)*/
}
void renderToScreen()
{
    // Writes the buffer to the console, hence you will see what you have written
	print_comments();
	ScareRender();
   g_Console.flushBufferToConsole();

}

void readMenu()
{
    myfile.open("fPagee.nfo");
    if(myfile.is_open())
    {
        for(int currH = 0; currH < MenuH; currH++)
        {
            getline(myfile,line);
            for(int currW = 0,a = 0; currW < MenuW; currW++, a++)
            {
                switch(line[a])
                {
                case 'Û':MENU[currH][currW] = 219;
                    break;
                case '²':MENU[currH][currW] = 178;
                    break;
                case 'Ü':MENU[currH][currW] = 220;
                    break;
                case ' ':MENU[currH][currW] = 32;
                    break;
                case '±':MENU[currH][currW] = 177;
                    break;
                case 'ß':MENU[currH][currW] = 223;
                    break;
                case '°':MENU[currH][currW] = 176;
                    break;
                case 'C':MENU[currH][currW] = 67;
                    break;
                case 'h':MENU[currH][currW] = 104;
                    break;
                case 'o':MENU[currH][currW] = 111;
                    break;
                case 's':MENU[currH][currW] = 115;
                    break;
                case 'e':MENU[currH][currW] = 101;
                    break;
                case 'a':MENU[currH][currW] = 97;
                    break;
                case 'd':MENU[currH][currW] = 100;
                    break;
                case 'i':MENU[currH][currW] = 105;
                    break;
                case 'c':MENU[currH][currW] = 99;
                    break;
                case 'u':MENU[currH][currW] = 117;
                    break;
                case 'l':MENU[currH][currW] = 108;
                    break;
                case 't':MENU[currH][currW] = 116;
                    break;
                case 'y':MENU[currH][currW] = 121;
                    break;
                case ')':MENU[currH][currW] = 41;
                    break;
                case 'E':MENU[currH][currW] = 69;
                    break;
                case 'N':MENU[currH][currW] = 78;
                    break;
                case 'H':MENU[currH][currW] = 72;
                    break;
                case 'r':MENU[currH][currW] = 114;
                    break;
                case 'm':MENU[currH][currW] = 109;
                    break;
                case 'b':MENU[currH][currW] = 98;
                    break;
                case 'f':MENU[currH][currW] = 102;
                    break;
                case '1':MENU[currH][currW] = 49;
                    break;
                case '2':MENU[currH][currW] = 50;
                    break;
                case '3':MENU[currH][currW] = 51;
                    break;
                }
            }
        }
        myfile.close();
    }
    for(int height = 0, meow1 = 2; height <  MenuH; height++, meow1++)
    {   for(int width = 0, mew1 = 10; width < MenuW; width++, mew1++)
        {
            g_Console.writeToBuffer(mew1, meow1, MENU[height][width], 0x0C);
        }
    }
}

//void 

void startGame()
{
    if (g_abKeyPressed[K_RETURN])
    {
        g_eGameState = S_GAME;
    }
    processUserInput();
}
