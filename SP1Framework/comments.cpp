#include "comments.h"

string str;

void update_comments(int i)
{
	if(i == 0)
	{
		str = "Remember the times...";
	}
	if(i == 1)
	{
		str = "... On the swing? ";
	}
	if(i == 2)
	{
		str = "It was fun... wasn't it? ";
	}
	if(i == 3)
	{
		str = "We were only kids... so young... and you already killed someone.";
	}
	if(i == 4)
	{
		str = "Do you remember? That someone...";
	}
	if(i == 5)
	{
		str = "was me... ";
	}
	if(i == 6)
	{
		str = "How long has it been since u last killed... me?";
	}
	if(i == 7)
	{
		str = "The guilt must have been haunting you...";
	}
	if(i == 8)
	{
		str = "It's okay... ";
	}
	if(i == 9)
	{
		str = "I'm not angry...";
	}
	if(i == 10)
	{
		str = "It wasn't your fault... ";
	}
	if(i == 11)
	{
		str = "Goodbye friend. ";
	}
}



void MessageUpdate()
{
	if(g_abKeyPressed[K_SPACE])
	{
		g_eGameState = S_GAME;
		  mapLevelno++;
		  mapReadlevel();
	}
	if(mapLevelno == 12)
		g_bQuitGame = true;
}

void MessageScreen()
{
	string instructions = "Press SPACE to Continue";
		for(unsigned int a = 0 ; a < str.length();++a)
		{
			g_Console.writeToBuffer(a+3,10, str[a],0x0C);
		}
		for(unsigned int b = 0; b < instructions.length(); ++b)
		{
			g_Console.writeToBuffer(b+12, 15, instructions[b], 0x0B);
		}
}

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
}

void PauseScreen()
{
	string pause = "Press ENTER to continue playing";
	string exit = "Press UP ARROW KEY to exit to main menu";
	for(unsigned int i = 0; i < pause.length(); ++i)
		g_Console.writeToBuffer(2+i, 2, pause[i], 0x0C);
	for(unsigned int i = 0; i < exit.length(); ++i)
		g_Console.writeToBuffer(2+i, 4, exit[i], 0x0C);
}

