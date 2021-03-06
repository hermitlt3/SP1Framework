#ifndef _MESSAGE_H_
#define _MESSAGE_H_
#pragma once

#include "Framework\timer.h"
#include "game.h"
#include "Framework\console.h"
#include "map.h"
#include <iostream>
#include <string>
#include "pause.h"

using std::string;

extern Console g_Console;
extern bool g_abKeyPressed[K_COUNT];
extern SGameChar g_sChar;
extern double g_dElapsedTime;

void continuemsg();
void MessageUpdate();
void MessageScreen();
void update_comments(int i);

#endif