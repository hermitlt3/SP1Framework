#ifndef _DETECTORS_H_
#define _DETECTORS_H_

#include<iostream>
#include "Framework\console.h"
#include "Framework\timer.h"
#include "game.h"
#include "map.h"
extern char MAP_LEVEL[50][150];
extern SGameChar g_sChar;
extern bool g_Collision;
extern bool pausemovement;
extern bool g_abKeyPressed[K_COUNT];

void checkCollisionUp(SHORT X, SHORT Y);
void checkCollisionDown(SHORT X, SHORT Y);
void checkCollisionLeft(SHORT X, SHORT Y);
void checkCollisionRight(SHORT X, SHORT Y);
void checkDoor(SHORT X, SHORT Y);
void checkPause();

#endif
