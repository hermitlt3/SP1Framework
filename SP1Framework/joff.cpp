    
#include "jofff.h"
#include "Framework\console.h"
#include "game.h"
#include "PlayBGM.h"

extern int joffH = 44;
extern int joffW = 80;
char JOFF_LEVEL[50][150];
int k=1;


void joff()
{
	string jtk;
	ifstream swaggy;

   swaggy.open("joff3.nfo");
      if(swaggy.is_open())
    {
		for (int i = 0;i < joffH;++i)
		{
			getline(swaggy, jtk);
			unsigned int a = 0;
			for (int j = 0; j < joffH, a < jtk.length(); ++j, ++a)
			{
				JOFF_LEVEL[i][j] = jtk[a];
			}
		}
    }
	  swaggy.close();	
	  joffPrint();
	  Play2();
}


void joffPrint()
{
	if(k==1)
	{
		Sleep(200);
		for (int i = 0; i < joffH; ++i)
		{
			for (int j = 10, p = 0, k=1; p < joffW; ++j, p++)
			{	
				g_Console.writeToBuffer(j, i, JOFF_LEVEL[i][p], 0xFC);			
			}
		}
		k=2;
	}
	else if(k==2)
	{
		Sleep(200);
		for (int i = 0; i < joffH; ++i)
		{
			for (int j = 10, p = 0, k=1; p < joffW; ++j, p++)
			{	
				g_Console.writeToBuffer(j, i, JOFF_LEVEL[i][p], 0x0C);			
			}
		}
		k=1;
	}
	string S_RESUME = "Press SPACE to restart level";
	for(unsigned int i = 0; i < S_RESUME.length(); ++i)
		g_Console.writeToBuffer(36+i, 47,  S_RESUME[i], 0x0C);
}
