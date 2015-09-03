#include "EndGame.h"



ifstream endgame;
string endofend;
extern double TimeKeep;
extern double g_dDeltaTime;
const int EndH = 15;
const int EndW = 79;
char END[EndH][EndW];
void EndScreenUpdate()
{
	if(g_abKeyPressed[K_RETURN])
		g_eGameState = S_GAMEEND;
}

void EndScreen()
{
    endgame.open("EndGameScreen.txt");
    if(endgame.is_open())
    {
		for(int height = 0; height <  EndH; height++)
		{  
			getline(endgame,endofend);
			unsigned int a = 0;
			for(int width = 0; width < EndW, a < endofend.length(); width++, a++)
			{
				END[height][width] = endofend[a];
			}
		}
	}
	endgame.close();
	for(int height = 0; height < EndH; height++)
	{  
		for(int width = 0; width < EndW; width++)
		{
			g_Console.writeToBuffer(10+width, 2+height, END[height][width], 0x0C);
		}
	}
	
	string laststatement1 = "Congratulations, you finished the maze.";
	for(unsigned int i = 0; i < laststatement1.length(); ++i)
		g_Console.writeToBuffer(30+i, 18, laststatement1[i], 0x0B);
	std::ostringstream endy;
	std::ostringstream endz;
	endy.str("");
	endy << "The time you took to escape was:" <<g_dElapsedTime << " seconds";
		g_Console.writeToBuffer(30, 19, endy.str(), 0x0B);
	endz.str("");
	endz << "Press ENTER to continue.";
	    g_Console.writeToBuffer(40, 21, endz.str(), 0x0B);
}