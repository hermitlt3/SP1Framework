#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Framework\timer.h"
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <string>
#include <fstream>
#include "map.h"
#include "jofff.h"
#include "detectors.h"

using  std::string;

extern Console g_Console;
extern WORD charColor;
extern int mapLevelno;
extern char MAZE_LEVEL_ZERO[20][150];

extern double g_dElapsedTime;
extern bool g_abKeyPressed[K_COUNT];
extern int ResPos;


void ENEMY_MEET();

void ENEMY_SPAWN_H(int x, int y, int i);
void ENEMY_SPAWN_V(int x, int y, int i);
void JumpScare();
void ScareRender();
void ENEMY_PRINT();
void ENEMY_COLLISION();
void UPMOVE(int i);
void RIGHTMOVE(int i);
#endif