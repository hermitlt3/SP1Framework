#include "EndGame.h"

ifstream endgame;
string endofend;
const int EndH = 14;
const int EndW = 79;

void EndScreen()
{
    endgame.open("EndScreen.txt");
    if(endgame.is_open())
    {
        getline(endgame,endofend);
    }


}