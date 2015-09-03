#include "EndGame.h"



ifstream endgame;
string endofend;
extern double TimeKeep;
extern double g_dDeltaTime;
const int EndH = 14;
const int EndW = 79;
char END[EndH][EndW];
double x;
void EndScreen()
{
	x = g_dDeltaTime;
	TimeKeep = x;
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
	endy.str("");
	endy << "The time you took to escape was:" << TimeKeep<<" "<<g_dElapsedTime;
		g_Console.writeToBuffer(30, 19, endy.str(), 0x0B);
}