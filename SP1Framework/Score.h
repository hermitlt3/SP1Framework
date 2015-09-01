#pragma once
#ifndef _SCORE_H
#define _SCORE_H


#include "game.h"
#include "Framework\timer.h"
#include "enemy.h"
#include <string>
#include <sstream>
#include <fstream>

using std::string;
using std::ofstream;

extern string ScoreTime;
extern bool ScoreStart;

void ScorePrint();
void ScoreDetect();


#endif