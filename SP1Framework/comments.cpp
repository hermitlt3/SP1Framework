#include "comments.h"
string str;
string instructions = "Press SPACE to Continue";
double delay;

/*void continuemsg()
{
	if(g_abKeyPressed[K_SPACE])
	{
		if (delay > g_dElapsedTime)
			return;
		delay = g_dElapsedTime + 0.250;
	}
}*/
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
		str = "It was fun... wasn't it? ";
	}
}
void checkEnd()
{
	if(MAP_LEVEL[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == 'E')
	{
		messageshown = true;
		printmap = false;
		pausemovement = true;
		if(g_abKeyPressed[K_SPACE])
		{
		  mapLevelno++;
		  mapReadlevel();
		  messageshown = false;
		  pausemovement = false;
		  printmap = true;
		}
	}
	if(mapLevelno == 12)
		g_bQuitGame = true;
}
void message_print()
{
	for(unsigned int b = 0; b < instructions.length(); ++b)
		{
			g_Console.writeToBuffer(b+12, 15, instructions[b], 0x0B);
		}
}
void print_comments()
{
	if(messageshown == true)
	{
		for(unsigned int a = 0 ; a < str.length();++a)
		{
			g_Console.writeToBuffer(a+3,10, str[a],0x0C);
		}
		message_print();
	}
}
