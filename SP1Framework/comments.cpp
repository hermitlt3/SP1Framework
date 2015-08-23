#include "comments.h"
string str;
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
}
void checkEnd()
{
	if(MAP_LEVEL[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == 'E')
	{
		messageshown = true;
		printmap = false;
		if(g_abKeyPressed[K_SPACE])
		{
		  mapLevelno++;
		  mapReadlevel();
		  messageshown = false;
		  printmap = true;
		}
	}
	if(mapLevelno == 12)
		g_bQuitGame = true;
}
void print_comments()
{
	if(messageshown == true)
	{
		for(unsigned int a = 0; a < str.length(); ++a)
		{
			g_Console.writeToBuffer(a+3,10, str[a],0x0B);
		}
	}
}
