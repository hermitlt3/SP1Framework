
#include "map.h"
int MapHeight;
int MapWidth;
 string maze;
 ifstream catridge;

 void level(int & i)
 {
	 if ( i == 0 )
	 {
		MapHeight = 7;
		MapWidth = 60;
		catridge.open("level0.txt");
	 }
	 if ( i == 1 )
	 {
		 MapHeight = 7;
		 MapWidth = 60;
		 catridge.open("level1.txt");
	 }
	 if ( i == 2 )
	 {
		 MapHeight = 8;
		 MapWidth = 60;
		 catridge.open("level2.txt");
	 }
	 if ( i == 3 )
	 {
		 MapHeight = 8;
		 MapWidth = 60;
		 catridge.open("level3.txt");
	 }
	 if ( i == 4 )
	 {
		 MapHeight = 10;
		 MapWidth = 60;
		 catridge.open("level4.txt");
	 }
	 if ( i == 5 )
	 {
		 MapHeight = 12;
		 MapWidth = 60;
		 catridge.open("level5.txt");
	 }
	 if ( i == 6 )
	 {
		 MapHeight = 14;
		 MapWidth = 60;
		 catridge.open("level6.txt");
	 }
	 if ( i == 7 )
	 {
		 MapHeight = 16;
		 MapWidth = 60;
		 catridge.open("level7.txt");
	 }
	 if ( i == 8 )
	 {
		 MapHeight = 18;
		 MapWidth = 60;
		 catridge.open("level8.txt");
	 }
	 if ( i == 9 )
	 {
		 MapHeight = 18;
		 MapWidth = 65;
		 catridge.open("level9.txt");
	 }
	 if ( i == 10 )
	 {
		 MapHeight = 20;
		 MapWidth = 67;
		 catridge.open("level10.txt");
	 }
	  if ( i == 11 )
	 {
		 MapHeight = 7;
		 MapWidth = 120;
		 catridge.open("finallevel.txt");
	 }
 }

void mapReadlevel()
{
/* MapHeight = 0;
 MapWidth = 0;
 g_sChar.m_cLocation.X = 0; 
 g_sChar.m_cLocation.Y = 0;*/
 reloadmap();
}

void reloadmap()
{

	level(mapLevelno);
    ENEMY_SPAWN(mapLevelno);
    for (int i = 0;i < MapHeight;++i)
	{
		getline(catridge,maze);
		for(int j = 0,a  = 0, enemyC=0; j < MapWidth, a <maze.length(); ++j,++a)
	    {
		    switch(maze[a])
		    {
		    case '#': MAP_LEVEL[i][j] =  219;
			    break;
		    case ' ': MAP_LEVEL[i][j] = ' ';
			    break;
		    case 'E': MAP_LEVEL[i][j] = 'E';
			    break;	 
		    case 'N': MAP_LEVEL[i][j] = 'N';
			    break;
		    case '_': MAP_LEVEL[i][j] = '_';
			    break;
		    case '\\': MAP_LEVEL[i][j] = '\\';
			    break;
		    case 'P' : g_sChar.m_cLocation.X = j; g_sChar.m_cLocation.Y = i; MAP_LEVEL[i][j] = ' ';
			    break;
		  /*case 'x':XenemyX[enemyC]=MapWidth,
				   XenemyY[enemyC]=MapHeight,
				   enemyC +=1;
			  break;
		  case 'y': YenemyX[enemyC]=MapWidth,
					YenemyY[enemyC]=MapHeight,
					enemyC +=1;
			  break;*/
		    }
		}
	}
    catridge.close();
}

void printMap()
{
		 for(int i = 0; i < MapHeight; ++i)
	    {
		    for(int j = 0; j < MapWidth; ++j)
		    {	
				g_Console.writeToBuffer(j,i, MAP_LEVEL[i][j],0x0F);
			}
		}
}

void printCharacter()
{
		g_Console.writeToBuffer(g_sChar.m_cLocation, '0', 0x0C);
}

void restartmap()
{
	if(g_abKeyPressed[K_SPACE])
	{
		reloadmap();
		g_eGameState = S_GAME;
	}
}

