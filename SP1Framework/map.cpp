
#include "map.h"
int MapHeight;
int MapWidth;
 string maze;
 ifstream catridge;
 int enemyno = 0;
 int numH = 0;
 int numV = 0;
 bool Reverse_H[50];
 bool Reverse_V[50];
 void level(int & i)
 {
	 switch(i)
	 {
	 case 0: catridge.open("level0.txt"); MapHeight = 7; MapWidth = 60;
		 break;
	 case 1: catridge.open("level1.txt"); MapHeight = 15; MapWidth = 60;
		 break;
	 case 2: catridge.open("level2.txt"); MapHeight = 15; MapWidth = 60;
		 break;
	 case 3: catridge.open("level3.txt"); MapHeight = 15; MapWidth = 60;
		 break;
	 case 4: catridge.open("level4.txt"); MapHeight = 10; MapWidth = 60;
		 break;
	 case 5: catridge.open("level5.txt"); MapHeight = 12; MapWidth = 60;
		 break;
	 case 6: catridge.open("level6.txt"); MapHeight = 14; MapWidth = 60;
		 break;
	 case 7: catridge.open("level7.txt"); MapHeight = 16; MapWidth = 60;
		 break;
	 case 8: catridge.open("level8.txt"); MapHeight = 18; MapWidth = 60;
		 break;
	 case 9: catridge.open("level9.txt"); MapHeight = 18; MapWidth = 65;
		 break;
	 case 10: catridge.open("level10.txt"); MapHeight = 20; MapWidth = 67;
		 break;
	 }
 }

void mapReadlevel()
{
	reloadmap();
}

void reloadmap()
{
	numH = 0;
	numV = 0;
	for(int i = 0; i < 15; ++i)
	{
		Reverse_H[i] = false;
		Reverse_V[i] = false;
	}
	level(mapLevelno);
    for (int i = 0;i < MapHeight;++i)
	{
		getline(catridge,maze);
		for(int j = 0,a  = 0; j < MapWidth, a <maze.length(); ++j,++a)
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
			case 'X': ENEMY_SPAWN_H(j,i,numH); Reverse_H[numH] = false; numH++; MAP_LEVEL[i][j] = ' ';
				break;
			case 'Y': ENEMY_SPAWN_V(j,i,numV); Reverse_V[numV] = false; numV++; MAP_LEVEL[i][j] = ' ';
				break;
			case 'D': /*LOCKDOOR(j,i,numK); */MAP_LEVEL[i][j] = ' ';
				break;
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

