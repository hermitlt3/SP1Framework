    
#include "jofff.h"
#include "Framework\console.h"

extern int joffH = 44;
extern int joffW = 80;
char JOFF_LEVEL[50][150];

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
			for (int j = 0, a = 0; j < joffH, a < jtk.length(); ++j, ++a)
			{
				JOFF_LEVEL[i][j] = jtk[a];
			}
				
		}
    }
	  swaggy.close();
	  joffPrint();
}

void joffPrint()
{
	for (int i = 0; i < joffH; ++i)
	{
		for (int j = 0; j < joffW; ++j)
		{				
			g_Console.writeToBuffer(j, i, JOFF_LEVEL[i][j], 0xFC);
		}
	}
	string S_RESUME = "Press SPACE to restart level";
	for(int i = 0; i < S_RESUME.length(); ++i)
		g_Console.writeToBuffer(24+i, 47,  S_RESUME[i], 0x0C);
}
