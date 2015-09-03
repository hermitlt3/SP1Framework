#include "Score.h"
#include <ios>

using std::ios_base;
string ScoreTime;
bool ScoreStart;
bool printer = true;
std::stringstream Score;
void ScoreDetect()
{		
		Score << g_dElapsedTime;
		ScoreTime = Score.str();
		ScorePrint();
}

void ScorePrint()
{
	if(printer==true)
	{
		ofstream ScoreFile;
		ScoreFile.open("HighScores.txt",ios_base::app);
			ScoreFile <<"\n";
			ScoreFile <<"Name ";
			for(int a=0;a<=5;a++)
			{		
				ScoreFile << ScoreTime[a];
			}
		ScoreFile.close();
		printer=false;
	}
}