#ifndef _MAP_H_
#define _MAP_H_

#include "Framework\timer.h"
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <string>
#include <fstream>

using  std::string;
using std::ifstream;

extern Console g_Console;
extern WORD charColor;
extern int mapLevelno;
extern char MAZE_LEVEL_ZERO[20][150];
extern SGameChar g_sChar;
void level(int & i);
void mapReadlevel();
void charSpawn();
void renderLevel();
void checkEnd();


#endif