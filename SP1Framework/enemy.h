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

using  std::string;

extern Console g_Console;
extern WORD charColor;
extern int mapLevelno;
extern char MAZE_LEVEL_ZERO[20][150];
extern SGameChar g_sChar;
extern SGameChar g_sEnemyOne;
extern SGameChar g_sEnemyTwo;
extern SGameChar g_sEnemyThree;
extern SGameChar g_sEnemyFour;
extern SGameChar g_sEnemyFive;
extern SGameChar g_sEnemySix;
extern bool pausemovement;
extern bool g_Scare;
extern bool printmap;
extern double g_dElapsedTime;
extern bool g_abKeyPressed[K_COUNT];
extern int ResPos;


void ENEMY_MEET();
void ENEMY_SPAWN(int i);
void ENEMY_ROUTE(int i);
void ENEMY_MOVEMENT(int i);
void ENEMY_PRINT(int i);
void JUMP_SCARE();
void print_Joff();
void LOAD_ENEMY_ZERO();
void LOAD_ENEMY_ONE();
void LOAD_ENEMY_TWO();
void LOAD_ENEMY_THREE();
void LOAD_ENEMY_FOUR();
void LOAD_ENEMY_FIVE();
void LOAD_ENEMY_SIX();
void LOAD_ENEMY_SEVEN();
void LOAD_ENEMY_EIGHT();
void LOAD_ENEMY_NINE();
void LOAD_ENEMY_TEN();
void LOAD_EPATH_ZERO();
void LOAD_EPATH_ONE();
void LOAD_EPATH_TWO();
void LOAD_EPATH_THREE();
void LOAD_EPATH_FOUR();
void LOAD_EPATH_FIVE();
void LOAD_EPATH_SIX();
void LOAD_EPATH_SEVEN();
void LOAD_EPATH_EIGHT();
void LOAD_EPATH_NINE();
void LOAD_EPATH_TEN();
void JumpScare();
void ScareRender();


#endif