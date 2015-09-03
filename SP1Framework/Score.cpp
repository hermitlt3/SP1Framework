#include "Score.h"
#include <ios>

string Name;
using std::ios_base;
string ScoreTime;
bool ScoreStart;
bool printer = true;
bool Scorekeeper = false;
std::stringstream Score;
void ScoreDetect()
{		
		Score << g_dElapsedTime;
		ScoreTime = Score.str();
		ScoreName();
		if(Scorekeeper == true)
		{
			ScoreKeep();
			
		}
}

void ScoreKeep()
{
	if(printer==true)
	{
		ofstream ScoreFile;
		ScoreFile.open("HighScores.txt",ios_base::app);
			ScoreFile <<"\n";
			ScoreFile <<Name;
			for(int a=0;a<=5;a++)
			{		
				ScoreFile << ScoreTime[a];
			}
		ScoreFile.close();
		printer=false;
	}
}

void ScoreName()
{
		g_Console.writeToBuffer(35, 15, "Please input your name. Press enter to confirm");
		NamePut();

}
void NamePut()
{
	for(int count =0;count < 16;)
	{
		if( GetAsyncKeyState( 'A' ) & 0x8000 )
		{
			Name[count]='A';
			count += 1;
		}
		if( GetAsyncKeyState( 'B') & 0x8000 )
		{
			Name[count]='B';
			count += 1;
		}
		if( GetAsyncKeyState( 'C') & 0x8000 )
		{
			Name[count]='C';
			count += 1;
		}
		if( GetAsyncKeyState( 'D') & 0x8000 )
		{
			Name[count]='D';
			count += 1;
		}
		if( GetAsyncKeyState( 'E') & 0x8000 )
		{
			Name[count]='E';
			count += 1;
		}
		if( GetAsyncKeyState( 'F') & 0x8000 )
		{
			Name[count]='F';
			count += 1;
		}
		if( GetAsyncKeyState( 'G') & 0x8000 )
		{
			Name[count]='G';
			count += 1;
		}
		if( GetAsyncKeyState( 'H' ) & 0x8000 )
		{
			Name[count]='H';
			count += 1;
		}
		if( GetAsyncKeyState( 'I') & 0x8000 )
		{
			Name[count]='I';
			count += 1;
		}
		if( GetAsyncKeyState( 'J' ) & 0x8000 )
		{
			Name[count]='J';
			count += 1;
		}
		if( GetAsyncKeyState( 'K' ) & 0x8000 )
		{
			Name[count]='K';
			count += 1;
		}
		if( GetAsyncKeyState( 'L') & 0x8000 )
		{
			Name[count]='L';
			count += 1;
		}
		if( GetAsyncKeyState( 'M' ) & 0x8000 )
		{
			Name[count]='M';
			count += 1;
		}
		if( GetAsyncKeyState( 'N' ) & 0x8000 )
		{
			Name[count]='N';
			count += 1;
		}
		if( GetAsyncKeyState( 'O') & 0x8000 )
		{
			Name[count]='O';
			count += 1;
		}
		if( GetAsyncKeyState( 'P' ) & 0x8000 )
		{
			Name[count]='P';
			count += 1;
		}
		if( GetAsyncKeyState( 'Q' ) & 0x8000 )
		{
			Name[count]='Q';
			count += 1;
		}
		if( GetAsyncKeyState( 'R' ) & 0x8000 )
		{
			Name[count]='R';
			count += 1;
		}
		if( GetAsyncKeyState( 'S' ) & 0x8000 )
		{
			Name[count]='S';
			count += 1;
		}
		if( GetAsyncKeyState( 'T' ) & 0x8000 )
		{
			Name[count]='T';
			count += 1;
		}
		if( GetAsyncKeyState( 'U' ) & 0x8000 )
		{
			Name[count]='U';
			count += 1;
		}
		if( GetAsyncKeyState( 'V' ) & 0x8000 )
		{
			Name[count]='V';
			count += 1;
		}
		if( GetAsyncKeyState( 'W' ) & 0x8000 )
		{
			Name[count]='W';
			count += 1;
		}
		if( GetAsyncKeyState( 'X' ) & 0x8000 )
		{
			Name[count]='X';
			count += 1;
		}
		if( GetAsyncKeyState( 'Y' ) & 0x8000 )
		{
			Name[count]='Y';
			count += 1;
		}
		if( GetAsyncKeyState( 'Z' ) & 0x8000 )
		{
			Name[count]='Z';
			count += 1;
		}
		if( GetAsyncKeyState( VK_SHIFT ) & 0x8000 )
		{
			Scorekeeper=true;
		}
		if( GetAsyncKeyState( 8 ) & 0x8000 )
		{
			count -= 1;
		}

		
	}
}