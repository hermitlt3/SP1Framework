    
#include "jofff.h"
#include "Framework\console.h"
// joff is 80x44

void joff();
void joffPrint();

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
	if(k==1)
	{
		Sleep(200);
		for (int i = 0; i < joffH; ++i)
		{
			for (int j = 0, k=1; j < joffW; ++j)
			{	
				g_Console.writeToBuffer(j, i, JOFF_LEVEL[i][j], 0xFC);			
			}
		}
		k=2;
	}
	else if(k==2)
	{
		Sleep(200);
		for (int i = 0; i < joffH; ++i)
		{
			for (int j = 0, k=1; j < joffW; ++j)
			{	
				g_Console.writeToBuffer(j, i, JOFF_LEVEL[i][j], 0x0C);			
			}
		}
		k=1;
	}
}
