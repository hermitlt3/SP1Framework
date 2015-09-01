#include "main_menu.h"

ifstream myfile;
string line;
const int MenuH = 13;
const int MenuW = 58;
char MENU[MenuH][MenuW];

void readMenu()
{
    myfile.open("fPagee.nfo");
    if(myfile.is_open())
    {
        for(int currH = 0; currH < MenuH; currH++)
        {
            getline(myfile,line);
            for(int currW = 0,a = 0; currW < MenuW; currW++, a++)
            {
                switch(line[a])
                {
                case 'Û':MENU[currH][currW] = 219;
                    break;
                case '²':MENU[currH][currW] = 178;
                    break;
                case 'Ü':MENU[currH][currW] = 220;
                    break;
                case ' ':MENU[currH][currW] = 32;
                    break;
                case '±':MENU[currH][currW] = 177;
                    break;
                case 'ß':MENU[currH][currW] = 223;
                    break;
                case '°':MENU[currH][currW] = 176;
                    break;
                case 'P':MENU[currH][currW] = 80;
                    break;
                case 'r':MENU[currH][currW] = 114;
                    break;
                case 'e':MENU[currH][currW] = 101;
                    break;
                case 's':MENU[currH][currW] = 115;
                    break;
                case 'E':MENU[currH][currW] = 69;
                    break;
                case 'N':MENU[currH][currW] = 78;
                    break;
                case 'T':MENU[currH][currW] = 84;
                    break;
                case 'R':MENU[currH][currW] = 82;
                    break;
                case 't':MENU[currH][currW] = 116;
                    break;
                case 'o':MENU[currH][currW] = 111;
                    break;
                case 'c':MENU[currH][currW] = 99;
                    break;
                case 'n':MENU[currH][currW] = 110;
                    break;
                case 'i':MENU[currH][currW] = 105;
                    break;
                case 'u':MENU[currH][currW] = 117;
                    break;
                case '<':MENU[currH][currW] = 60;
                    break;
                case '>':MENU[currH][currW] = 62;
                    break;
                }
            }
        }
        myfile.close();
    }
    for(int height = 0, meow1 = 2; height <  MenuH; height++, meow1++)
    {   for(int width = 0, mew1 = 21; width < MenuW; width++, mew1++)
        {
            g_Console.writeToBuffer(mew1, meow1, MENU[height][width], 0x0C);
        }
    }
}