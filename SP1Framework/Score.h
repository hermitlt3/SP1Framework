#pragma once
#ifndef _SCORE_H
#define _SCORE_H


#include "game.h"
#include "Framework\timer.h"
#include "enemy.h"
#include <string>
#include <sstream>
#include <fstream>
#include "Framework/console.h"

using std::string;
using std::ofstream;

extern string ScoreTime;
extern bool ScoreStart;
extern string Name;

void ScorePrint();
void ScoreDetect();
void ScoreKeep();
void ScoreName();
void NamePut();


#endif