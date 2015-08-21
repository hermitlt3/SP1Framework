
#include "map.h"
extern int MapHeight;
extern int MapWidth;
 string maze;
 ifstream catridge;
 void level(int & i)
 {
	 if ( i == 0 )
	 {
		MapHeight = 7;
		MapWidth = 60;
		g_sChar.m_cLocation.X = 2; 
		g_sChar.m_cLocation.Y = 3;
		catridge.open("level0.txt");
	 }
	 if ( i == 1 )
	 {
		 MapHeight = 7;
		 MapWidth = 60;
         g_sChar.m_cLocation.X = 2; 
		 g_sChar.m_cLocation.Y = 1;
		 catridge.open("level1.txt");
	 }
	 if ( i == 2 )
	 {
		 MapHeight = 8;
		 MapWidth = 60;
         g_sChar.m_cLocation.X = 2; 
		 g_sChar.m_cLocation.Y = 1;
		 catridge.open("level2.txt");
	 }
	 if ( i == 3 )
	 {
		 MapHeight = 8;
		 MapWidth = 60;
         g_sChar.m_cLocation.X = 8; 
		 g_sChar.m_cLocation.Y = 5;
		 catridge.open("level3.txt");
	 }
	 if ( i == 4 )
	 {
		 MapHeight = 10;
		 MapWidth = 60;
         g_sChar.m_cLocation.X = 2; 
		 g_sChar.m_cLocation.Y = 8;
		 catridge.open("level4.txt");
	 }
	 if ( i == 5 )
	 {
		 MapHeight = 12;
		 MapWidth = 60;
         g_sChar.m_cLocation.X = 2; 
		 g_sChar.m_cLocation.Y = 10;
		 catridge.open("level5.txt");
	 }
	 if ( i == 6 )
	 {
		 MapHeight = 14;
		 MapWidth = 60;
         g_sChar.m_cLocation.X = 11; 
		 g_sChar.m_cLocation.Y = 1;
		 catridge.open("level6.txt");
	 }
	 if ( i == 7 )
	 {
		 MapHeight = 16;
		 MapWidth = 60;
         g_sChar.m_cLocation.X = 2; 
		 g_sChar.m_cLocation.Y = 1;
		 catridge.open("level7.txt");
	 }
	 if ( i == 8 )
	 {
		 MapHeight = 18;
		 MapWidth = 60;
         g_sChar.m_cLocation.X = 46; 
		 g_sChar.m_cLocation.Y = 16;
		 catridge.open("level8.txt");
	 }
	 if ( i == 9 )
	 {
		 MapHeight = 18;
		 MapWidth = 65;
         g_sChar.m_cLocation.X = 2; 
		 g_sChar.m_cLocation.Y = 1;
		 catridge.open("level9.txt");
	 }
	 if ( i == 10 )
	 {
		 MapHeight = 20;
		 MapWidth = 67;
         g_sChar.m_cLocation.X = 5; 
		 g_sChar.m_cLocation.Y = 1;
		 catridge.open("level10.txt");
	 }
 }
void mapReadlevel()
{
 MapHeight = 0;
 MapWidth = 0;
 g_sChar.m_cLocation.X = 0; 
 g_sChar.m_cLocation.Y = 0;
 level(mapLevelno);
 for (int i = 0;i < MapHeight;++i)
	{
		getline(catridge,maze);
		for(int j = 0,a  = 0; j < MapWidth, a <maze.length(); ++j,++a)
	  {
		  switch(maze[a])
		  {
		  case'#': MAZE_LEVEL_ZERO[i][j] =  219;
			  break;
		  case' ': MAZE_LEVEL_ZERO[i][j] = ' ';
			  break;
		  case'E':  MAZE_LEVEL_ZERO[i][j] = 'E';
			  break;	 
		  case 'N' :  MAZE_LEVEL_ZERO[i][j] = 'N';
			  break;
		  case '_': MAZE_LEVEL_ZERO[i][j] = '_';
			  break;
		  case '\\': MAZE_LEVEL_ZERO[i][j] = '\\';
			  break;
		  }
		}
	}
 catridge.close();
}
	

	
void checkEnd()
{
	if(MAZE_LEVEL_ZERO[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == 'E')
	{
		mapLevelno++;
		mapReadlevel();
	}
}