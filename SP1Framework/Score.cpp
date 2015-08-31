#include "Score.h"

void ScoreDetect()
{
	if(ScoreStart == true)
	{
		std::stringstream Score;
		Score << g_dElapsedTime;
		ScoreTime = Score.str();
		ScorePrint();
	}
}

void ScorePrint()
{
	ofstream ScoreFile;
	ScoreFile.open("HighScores.txt");
	ScoreFile <<"Name" << ScoreTime << "\n";
	ScoreFile.close();
}