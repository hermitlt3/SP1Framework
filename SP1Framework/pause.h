#ifndef _PAUSE_H_
#define _PAUSE_H_

#include "Framework\timer.h"
#include "game.h"
#include "Framework\console.h"
#include "map.h"
#include <iostream>
#include <string>

using std::string;

extern Console g_Console;
extern bool g_abKeyPressed[K_COUNT];
extern SGameChar g_sChar;
extern double g_dElapsedTime;

void checkPause();
void PauseUpdate();
void PauseScreen();

#endif