#ifndef _MAIN_MENU_H
#define _MAIN_MENU_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "game.h"
#include "Framework\console.h"

using std::string;
using std::ifstream;

extern Console g_Console;

void readMenu();
void renderSplashScreen();

#endif// _MAIN_MENU_H