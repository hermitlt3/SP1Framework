#include "Score.h"

string ScoreTime;
bool ScoreStart;

void ScoreDetect()
{
		std::stringstream Score;
		Score << g_dElapsedTime;
		ScoreTime = Score.str();
		ScorePrint();
}

void ScorePrint()
{
	ofstream ScoreFile;
	ScoreFile.open("HighScores.txt");
	ScoreFile <<"Name" << ScoreTime << "\n";
	ScoreFile.close();
}