#include "enemy.h"

double velocity;
extern int numH;
extern int numV;
extern bool Reverse_H[50];
extern bool Reverse_V[50];


void JumpScare()
{
	if (g_abKeyPressed[K_SPACE])
	{
			restartmap();
	}
}

void ScareRender()
{
		joff();
}

struct ENEMIES
{
	COORD ENEMY[50];
};

ENEMIES H_ENEMY;
ENEMIES V_ENEMY;

void ENEMY_SPAWN_H(int x, int y, int i)
{
	H_ENEMY.ENEMY[i].X = x;
	H_ENEMY.ENEMY[i].Y = y;
}

void ENEMY_SPAWN_V(int x, int y, int i)
{
	V_ENEMY.ENEMY[i].X = x;
	V_ENEMY.ENEMY[i].Y = y;
}

void UPMOVE(int i)
{
	if(Reverse_V[i]== false)
	{
		checkCollisionUp(V_ENEMY.ENEMY[i].X, V_ENEMY.ENEMY[i].Y);
		if(g_Collision == true)
			Reverse_V[i] = true;
		else
			V_ENEMY.ENEMY[i].Y--;
	}
	if(Reverse_V[i] == true)
	{
		checkCollisionDown(V_ENEMY.ENEMY[i].X, V_ENEMY.ENEMY[i].Y);
		if(g_Collision == true)
			Reverse_V[i] = false;
		else
			V_ENEMY.ENEMY[i].Y++;
	}
}

void RIGHTMOVE(int i)
{
	if(Reverse_H[i]== false)
	{
		checkCollisionLeft(H_ENEMY.ENEMY[i].X, H_ENEMY.ENEMY[i].Y);
		if(g_Collision == true)
			Reverse_H[i] = true;
		else
			H_ENEMY.ENEMY[i].X--;
	}
	if(Reverse_H[i] == true)
	{
		checkCollisionRight(H_ENEMY.ENEMY[i].X, H_ENEMY.ENEMY[i].Y);
		if(g_Collision == true)
			Reverse_H[i] = false;
		else
			H_ENEMY.ENEMY[i].X++;
	}
}

void ENEMY_COLLISION()
{
	if (velocity > g_dElapsedTime)
		return;
	velocity = g_dElapsedTime + 0.125;
	for(int i = 0; i < numV; ++i)
		UPMOVE(i);
	for(int i = 0; i < numH; ++i)
		RIGHTMOVE(i);
}

void ENEMY_PRINT()
{
	for(int i = 0; i < numH; ++i)
		g_Console.writeToBuffer(H_ENEMY.ENEMY[i].X, H_ENEMY.ENEMY[i].Y, 'X', 0x0C);
	for(int i = 0; i < numV; ++i)
		g_Console.writeToBuffer(V_ENEMY.ENEMY[i].X, V_ENEMY.ENEMY[i].Y, 'Y', 0x0C);
}

void ENEMY_MEET()
{
	for(int i = 0; i < numH; ++i)
	{
		if(H_ENEMY.ENEMY[i].X == g_sChar.m_cLocation.X && H_ENEMY.ENEMY[i].Y == g_sChar.m_cLocation.Y)
			g_eGameState = S_RELOAD;
	}
	for(int j = 0;  j < numV; ++j)
	{
		if(V_ENEMY.ENEMY[j].X == g_sChar.m_cLocation.X && V_ENEMY.ENEMY[j].Y == g_sChar.m_cLocation.Y)
			g_eGameState = S_RELOAD;
	}
}

