#include "message.h"
#include "Score.h"


string str;

void update_comments(int i)
{
	switch(i)
	{
	case 0: str = "Remember the times...";
		break;
	case 1: str = "... On the swing? ";
		break;
	case 2: str = "It was fun... wasn't it? ";
		break;
	case 3: str = "We were only kids... so young... and you already killed someone.";
		break;
	case 4: str = "Do you remember? That someone...";
		break;
	case 5: str = "was me... ";
		break;
	case 6: str = "How long has it been since u last killed... me?";
		break;
	case 7: str = "The guilt must have been haunting you...";
		break;
	case 8: str = "It's okay... ";
		break;
	case 9: str = "I'm not angry...";
		break;
	case 10: str = "It wasn't your fault... ";
		break;
	case 11: str = "Goodbye, friend.";
		break;
	}
}

void MessageUpdate()
{
	if(g_abKeyPressed[K_SPACE])
	{
		g_eGameState = S_GAME;
		mapLevelno++;
		mapReadlevel();
	}
    if(mapLevelno == 12)
    {
        g_eGameState = S_ENDSCREEN;
    }
	if(mapLevelno == 13)
	{
		g_eGameState = S_GAMEEND;
	}
}

void MessageScreen()
{
    COORD c = g_Console.getConsoleSize();
	string instructions = "Press SPACE to Continue";
    
    for(unsigned int a = 0 ; a < str.length();++a)
	{
        g_Console.writeToBuffer(a+39,21, str[a],0x0C);
    }
    
	for(unsigned int b = 0; b < instructions.length(); ++b)
	{
		g_Console.writeToBuffer(b+39, 26, instructions[b], 0x0B);
	}
}
