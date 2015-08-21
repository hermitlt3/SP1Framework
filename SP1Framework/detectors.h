#ifndef _DETECTORS_H_
#define _DETECTORS_H_

#include<iostream>
#include "Framework\console.h"
#include "Framework\timer.h"
#include "game.h"
extern char MAZE_LEVEL_ZERO[20][150];
extern SGameChar g_sChar;
extern bool g_Collision;

void checkCollisionUp(SHORT X, SHORT Y);
void checkCollisionDown(SHORT X, SHORT Y);
void checkCollisionLeft(SHORT X, SHORT Y);
void checkCollisionRight(SHORT X, SHORT Y);
/*void levelSelect()
{
	levelNum=0;
	for (;levelNum<=10;)
	{
		levelEnd=false;
		switch(levelNum)
		{
		case 0: mapReadlevelzero();
			break;
		case 1: mapReadlevelone();
		break;
		}
		//add detector function here
	//	checkEnd();
		if(levelEnd==true)
		{
			levelNum+=1;
		}
	}
}*/

#endif
