#include "Score.h"

string ScoreTime;
bool ScoreStart;
bool hi = false;
std::stringstream Score;
void ScoreDetect()
{		
		Score << g_dElapsedTime;
		ScoreTime = Score.str();
		ScorePrint();
}

void ScorePrint()
{
	int count=0;
	ofstream ScoreFile;
	ScoreFile.open("HighScores.txt");
	for(int e=0;e<=count;e++)
	{
		ScoreFile <<"\n";
	}
	ScoreFile <<"Name ";
	for(int a=0;a<=5;a++)
	{		
		ScoreFile << ScoreTime[a];
	}
	ScoreFile <<"\n";
	ScoreFile.close();
	count+=1;
}