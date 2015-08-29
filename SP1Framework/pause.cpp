#include "pause.h"

void checkPause()
{
	if(g_abKeyPressed[K_ESCAPE])
		g_eGameState = S_PAUSE;
}

void PauseUpdate()
{
	if(g_abKeyPressed[K_RETURN])
		g_eGameState = S_GAME;
	if(g_abKeyPressed[K_UP])
		g_eGameState = S_MENU;
    if(g_abKeyPressed[K_DOWN])
        g_bQuitGame = true;
}

void PauseScreen()
{
	string pause = "Press ENTER to continue playing";
	string exit = "Press UP ARROW KEY to exit to main menu";
    string quit = "Press DOWN ARROW KEY to exit the game";
	for(unsigned int i = 0; i < pause.length(); ++i)
		g_Console.writeToBuffer(2+i, 2, pause[i], 0x0C);
	for(unsigned int i = 0; i < exit.length(); ++i)
		g_Console.writeToBuffer(2+i, 4, exit[i], 0x0C);
    for(unsigned int i = 0; i < quit.length(); ++i)
        g_Console.writeToBuffer(2+i, 6, quit[i], 0x0C);
}

