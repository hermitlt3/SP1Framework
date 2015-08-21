#include "detectors.h"

void checkCollisionUp(SHORT X, SHORT Y)
{
	if(MAZE_LEVEL_ZERO[Y-1][X] == (char)219 )
		g_Collision = true;
	else
		g_Collision = false;
}
void checkCollisionDown(SHORT X, SHORT Y)
{
	if(MAZE_LEVEL_ZERO[Y+1][X] == (char)219)
		g_Collision = true;
	else
		g_Collision = false;
}
void checkCollisionLeft(SHORT X, SHORT Y)
{
	if(MAZE_LEVEL_ZERO[Y][X-1] == (char)219)
		g_Collision = true;
	else
		g_Collision = false;
}
void checkCollisionRight(SHORT X, SHORT Y)
{
	if(MAZE_LEVEL_ZERO[Y][X+1] == (char)219)
		g_Collision = true;
	else
		g_Collision = false;
}