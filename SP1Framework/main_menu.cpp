#include "main_menu.h"
#include "Framework\console.h"
#include "game.h"

string line;
ifstream myfile;

void menu()
{
    fPage();
}

void fPage()
{
        myfile.open("fPagee.nfo");
        if(myfile.is_open())
        {
            for(int i = 0; getline(myfile,line);)
            {
                colour(0xFC);
                cout << '\t' << " " << line << '\n';
            }
            myfile.close();
            colour(0x1F);
        }
        startMenu();
}

void sPage()
{
    myfile.open("fPage1.nfo");
        if(myfile.is_open())
        {
            for(int i = 0; getline(myfile,line);)
            {
                colour(0xFC);
                cout << '\t' << " " << line << '\n';
            }
            myfile.close();
        }
}