#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"
#include <windows.h>
#include <mmsystem.h>
#include "../include/irrKlang.h"
extern CStopWatch g_swTimer;
extern bool g_bQuitGame;
extern double  g_dElapsedTime;

using namespace irrklang;

#pragma comment(lib, "../lib/Win32-visualStudio/irrKlang.lib") // link with irrKlang.dll
// Enumeration to store the control keys that the game will have
enum EKEYS
{
    K_UP,
    K_DOWN,
    K_LEFT,
    K_RIGHT,
    K_ESCAPE,
    K_SPACE,
    K_COUNT,
    K_RETURN
};

// Enumeration for the different screen states
enum EGAMESTATES
{
    S_MENU, // i did this
    S_SPLASHSCREEN,
    S_GAME,
	S_RELOAD,
	S_PAUSE,
	S_LEVELUP,
	S_GAMEEND,
    S_COUNT
};

// struct for the game character
struct SGameChar
{
    COORD m_cLocation;
    bool  m_bActive;
};

void splashScreenWait();    // waits for time to pass in splash screen
void gameplay();            // gameplay logic
void moveCharacter();       // moves the character, collision detection, physics, etc
void processUserInput();    // checks if you should change states or do something else with the game, e.g. pause, exit
void clearScreen();         // clears the current screen and draw from scratch 
void renderGame();          // renders the game stuff
void renderMap();           // renders the map to the buffer first
void renderCharacter();     // renders the character into the buffer
void renderToScreen();      // dump the contenttt                     s of the buffer to the screen, one frame worth of game
void init();                // initialize your variables, allocate memory, etc
void getInput();            // get input from player
void update(double dt);     // update the game and the state of the game
void renderFramerate();
void render();              // renders the current state of the game to the console
void shutdown();            // do clean up, free memory
void startGame();
void renderFramerate();


#endif // _GAME_H