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
                case 'Û':MENU[currH][currW] = char(219);
                    break;
                case '²':MENU[currH][currW] = char(178);
                    break;
                case 'Ü':MENU[currH][currW] = char(220);
                    break;
                case ' ':MENU[currH][currW] = char(32);
                    break;
                case '±':MENU[currH][currW] = char(177);
                    break;
                case 'ß':MENU[currH][currW] = char(223);
                    break;
                case '°':MENU[currH][currW] = char(176);
                    break;
                case 'P':MENU[currH][currW] = char(80);
                    break;
                case 'r':MENU[currH][currW] = char(114);
                    break;
                case 'e':MENU[currH][currW] = char(101);
                    break;
                case 's':MENU[currH][currW] = char(115);
                    break;
                case 'E':MENU[currH][currW] = char(69);
                    break;
                case 'N':MENU[currH][currW] = char(78);
                    break;
                case 'T':MENU[currH][currW] = char(84);
                    break;
                case 'R':MENU[currH][currW] = char(82);
                    break;
                case 't':MENU[currH][currW] = char(116);
                    break;
                case 'o':MENU[currH][currW] = char(111);
                    break;
                case 'c':MENU[currH][currW] = char(99);
                    break;
                case 'n':MENU[currH][currW] = char(110);
                    break;
                case 'i':MENU[currH][currW] = char(105);
                    break;
                case 'u':MENU[currH][currW] = char(117);
                    break;
                case '<':MENU[currH][currW] = char(60);
                    break;
                case '>':MENU[currH][currW] = char(62);
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

void renderSplashScreen()  // renders the splash screen
{
    COORD c = g_Console.getConsoleSize();
    c.Y /= 3;
    c.X = c.X / 2 - 9;
    g_Console.writeToBuffer(c, "Arrow Keys to move", 0x0C);
    c.Y += 1;
    c.X = g_Console.getConsoleSize().X / 2 - 13;
    g_Console.writeToBuffer(c, "Press <Space> to interact", 0x0C);
    c.Y += 1;
    c.X = g_Console.getConsoleSize().X / 2 - 10;
    g_Console.writeToBuffer(c, "Press 'Esc' to pause", 0x0C);
    c.Y += 5;
    c.X = g_Console.getConsoleSize().X / 2 - 21;
    g_Console.writeToBuffer(c, "Press <Space> now to continue to the game", 0x0B);

}
