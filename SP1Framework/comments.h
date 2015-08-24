#ifndef _COMMENTS_H_
#define _COMMENTS_H_

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
extern bool messageshown;
extern bool printmap;
extern double g_dElapsedTime;

void continuemsg();
void print_comments();
void update_comments(int i);


#endif