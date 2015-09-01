#ifndef _MAP_H_
#define _MAP_H_

#include "Framework\timer.h"
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <string>
#include <fstream>
#include "enemy.h"
#include "locknkey.h"

using std::string;
using std::ifstream;

extern Console g_Console;
extern WORD charColor;
extern int mapLevelno;
extern char MAP_LEVEL[50][150];
extern SGameChar g_sChar;
extern EGAMESTATES g_eGameState;

/*extern int XenemyX[10];
extern int XenemyY[10];
extern int YenemyX[10];
extern int YenemyY[10];*/

void level(int  i);
void mapReadlevel();
void printMap();
void printCharacter();
void restartmap();
void reloadmap();
void PauseScreen();
void MessageScreen();



#endif