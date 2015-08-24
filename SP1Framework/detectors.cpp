#include "detectors.h"

void checkCollisionUp(SHORT X, SHORT Y)
{
	if(MAP_LEVEL[Y-1][X] == (char)219 || MAP_LEVEL[Y-1][X] == '\\' || MAP_LEVEL[Y-1][X] == '_')
		g_Collision = true;
	else
		g_Collision = false;
}
void checkCollisionDown(SHORT X, SHORT Y)
{
	if(MAP_LEVEL[Y+1][X] == (char)219 || MAP_LEVEL[Y+1][X] == '\\' || MAP_LEVEL[Y+1][X] == '_')
		g_Collision = true;
	else
		g_Collision = false;
}
void checkCollisionLeft(SHORT X, SHORT Y)
{
	if(MAP_LEVEL[Y][X-1] == (char)219 || MAP_LEVEL[Y][X-1] == '\\' || MAP_LEVEL[Y][X-1] == '_')
		g_Collision = true;
	else
		g_Collision = false;
}
void checkCollisionRight(SHORT X, SHORT Y)
{
	if(MAP_LEVEL[Y][X+1] == (char)219 || MAP_LEVEL[Y][X+1] == '\\' || MAP_LEVEL[Y][X+1] == '_')
		g_Collision = true;
	else
		g_Collision = false;
}
void checkDoor(SHORT X, SHORT Y)
{
	 if (g_sChar.m_bActive)
    {
        if(MAP_LEVEL[Y][X-1] == '\\' )
			MAP_LEVEL[Y][X-1] = ' ';
		if(MAP_LEVEL[Y][X+1] == '\\')
			MAP_LEVEL[Y][X+1] = ' ';
		 if(MAP_LEVEL[Y+1][X] == '_' )
			MAP_LEVEL[Y+1][X] = ' ';
		if(MAP_LEVEL[Y-1][X] == '_')
			MAP_LEVEL[Y-1][X] = ' ';
		g_sChar.m_bActive = false;
    }
}
void checkPause()
{
	if(g_abKeyPressed[K_SPACE] && pausemovement == false)
		pausemovement = true;
}