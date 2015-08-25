    
#include "jofff.h"
#include "Framework\console.h"
// joff is 80x44

void joff();
void joffPrint();

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
}
