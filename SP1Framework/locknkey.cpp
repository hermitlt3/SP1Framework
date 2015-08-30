#include "locknkey.h"
extern int numK;
extern int numD;
extern bool Unlocked[10];
struct KEY
{
	COORD KEYS[10];
};
KEY KEY_S;

struct DOOR
{
	COORD DOORS[10];
};
DOOR DOOR_S;

void LOCKDOOR(int x, int y, int z)
{
	DOOR_S.DOORS[z].X = x;
	DOOR_S.DOORS[z].Y = y;
}

//if gets key, coordinates of door will become ' '

void UNLOCKKEY(int x, int y, int z)
{
	KEY_S.KEYS[z].X = x;
	KEY_S.KEYS[z].Y = y;
}
void UNLOCK_UPDATE()
{
	for(int i = 0; i < numK; ++i)
	{
		if(Unlocked[i] == true)
		{
			MAP_LEVEL[DOOR_S.DOORS[i].Y][DOOR_S.DOORS[i].X] = ' '; 
		}
	}
}
void KEY_RENDER()
{
	for(int i = 0; i < numK; ++i)
	{
		if(Unlocked[i] == false)
		{
			g_Console.writeToBuffer(KEY_S.KEYS[i].X,KEY_S.KEYS[i].Y,'K',0x0B);
		}
	}
}
void UNLOCKEDDOOR(int i, SHORT X, SHORT Y)
{
	switch(i)
	{
	case 0: DOORZERO(X,Y);
		break;
/*	case 1: DOORONE(X,Y);
		break;
	case 2: DOORTWO(X,Y);
		break;
	case 3: DOORTHREE(X,Y);
		break;
	case 4: DOORFOUR(X,Y);
		break;*/
	}
}

void RENDER_KD()
{
	for(int i = 0; i < numD; ++i)
	{
		if(Unlocked[i] == false)
			g_Console.writeToBuffer(DOOR_S.DOORS[i].X,DOOR_S.DOORS[i].Y,219,0x0B);
	}
}

void DOORZERO(SHORT X, SHORT Y)
{
	if(X == KEY_S.KEYS[0].X && Y == KEY_S.KEYS[0].Y)
	{
		MAP_LEVEL[Y][X] = ' ';
		Unlocked[0] = true;
	}
}