#include "enemy.h"
int a = 0;
bool reverse1;
bool reverse2;
bool reverse3;
bool reverse4;
bool reverse5;
bool reverse6;
double velocity;
void ENEMY_MEET()
{
	if (g_sChar.m_cLocation.X == g_sEnemyOne.m_cLocation.X && g_sChar.m_cLocation.Y == g_sEnemyOne.m_cLocation.Y)
		g_bQuitGame = true;

	if (g_sChar.m_cLocation.X == g_sEnemyTwo.m_cLocation.X && g_sChar.m_cLocation.Y == g_sEnemyTwo.m_cLocation.Y)
		g_bQuitGame = true;

	if (g_sChar.m_cLocation.X == g_sEnemyThree.m_cLocation.X && g_sChar.m_cLocation.Y == g_sEnemyThree.m_cLocation.Y)
		g_bQuitGame = true;

	if (g_sChar.m_cLocation.X == g_sEnemyFour.m_cLocation.X && g_sChar.m_cLocation.Y == g_sEnemyFour.m_cLocation.Y)
		g_bQuitGame = true;

	if (g_sChar.m_cLocation.X == g_sEnemyFive.m_cLocation.X && g_sChar.m_cLocation.Y == g_sEnemyFive.m_cLocation.Y)
		g_bQuitGame = true;

	if (g_sChar.m_cLocation.X == g_sEnemySix.m_cLocation.X && g_sChar.m_cLocation.Y == g_sEnemySix.m_cLocation.Y)
		g_bQuitGame = true;
}

void ENEMY_SPAWN(int i)
{
	switch(i)
	{
	case 0: LOAD_ENEMY_ZERO();
		break;
	case 1: LOAD_ENEMY_ONE();
		break;
	case 2: LOAD_ENEMY_TWO();
		break;
	case 3: LOAD_ENEMY_THREE();
		break;
	case 4: LOAD_ENEMY_FOUR();
		break;
	case 5: LOAD_ENEMY_FIVE();
		break;
	case 6: LOAD_ENEMY_SIX();
		break;
	case 7: LOAD_ENEMY_SEVEN();
		break;
	case 8: LOAD_ENEMY_EIGHT();
		break;
	case 9: LOAD_ENEMY_NINE();
		break;
	case 10: LOAD_ENEMY_TEN();
		break;
	}
}


void LOAD_ENEMY_ZERO()
{
	reverse1 = false;
	reverse2 = false;
	g_sEnemyOne.m_cLocation.X = 21;
	g_sEnemyOne.m_cLocation.Y = 1;
	g_sEnemyTwo.m_cLocation.X = 22;
	g_sEnemyTwo.m_cLocation.Y = 1;
}

void LOAD_ENEMY_ONE()
{
	reverse1 = false;
	reverse2 = false;
	reverse3 = false;
	g_sEnemyOne.m_cLocation.X = 18;
	g_sEnemyOne.m_cLocation.Y = 3;
	g_sEnemyTwo.m_cLocation.X = 18;
	g_sEnemyTwo.m_cLocation.Y = 1;
	g_sEnemyThree.m_cLocation.X = 42;
	g_sEnemyThree.m_cLocation.Y = 5;
}
	
void LOAD_ENEMY_TWO()
{
	reverse1 = false;
	reverse2 = false;
	reverse3 = false;
	g_sEnemyOne.m_cLocation.X = 16;
	g_sEnemyOne.m_cLocation.Y = 6;
	g_sEnemyTwo.m_cLocation.X = 41;
	g_sEnemyTwo.m_cLocation.Y = 1;
	g_sEnemyThree.m_cLocation.X = 29;
	g_sEnemyThree.m_cLocation.Y = 6;
}

void LOAD_ENEMY_THREE()
{
	reverse1 = false;
	reverse2 = false;
	reverse3 = false;
	g_sEnemyOne.m_cLocation.X = 12;
	g_sEnemyOne.m_cLocation.Y = 6;
	g_sEnemyTwo.m_cLocation.X = 47;
	g_sEnemyTwo.m_cLocation.Y = 1;
	g_sEnemyThree.m_cLocation.X = 28;
	g_sEnemyThree.m_cLocation.Y = 1;
}

void LOAD_ENEMY_FOUR()
{
	reverse1 = false;
	reverse2 = false;
	reverse3 = false;
	reverse4 = false;
	g_sEnemyOne.m_cLocation.X = 57;
	g_sEnemyOne.m_cLocation.Y = 1;
	g_sEnemyTwo.m_cLocation.X = 15;
	g_sEnemyTwo.m_cLocation.Y = 3;
	g_sEnemyThree.m_cLocation.X = 35;
	g_sEnemyThree.m_cLocation.Y = 1;
	g_sEnemyFour.m_cLocation.X = 1;
	g_sEnemyFour.m_cLocation.Y = 1;
}

void LOAD_ENEMY_FIVE()
{
	reverse1 = false;
	reverse2 = false;
	reverse3 = false;
	reverse4 = false;
	g_sEnemyOne.m_cLocation.X = 56;
	g_sEnemyOne.m_cLocation.Y = 5;
	g_sEnemyTwo.m_cLocation.X = 11;
	g_sEnemyTwo.m_cLocation.Y = 9;
	g_sEnemyThree.m_cLocation.X = 34;
	g_sEnemyThree.m_cLocation.Y = 1;
	g_sEnemyFour.m_cLocation.X = 2;
	g_sEnemyFour.m_cLocation.Y = 7;
}

void LOAD_ENEMY_SIX()
{
	reverse1 = false;
	reverse2 = false;
	reverse3 = false;
	reverse4 = false;
	g_sEnemyOne.m_cLocation.X = 6;
	g_sEnemyOne.m_cLocation.Y = 12;
	g_sEnemyTwo.m_cLocation.X = 47;
	g_sEnemyTwo.m_cLocation.Y = 7;
	g_sEnemyThree.m_cLocation.X = 37;
	g_sEnemyThree.m_cLocation.Y = 1;
	g_sEnemyFour.m_cLocation.X = 2;
	g_sEnemyFour.m_cLocation.Y = 8;
}

void LOAD_ENEMY_SEVEN()
{
	reverse1 = false;
	reverse2 = false;
	reverse3 = false;
	reverse4 = false;
	reverse5 = false;
	g_sEnemyOne.m_cLocation.X = 9;
	g_sEnemyOne.m_cLocation.Y = 1;
	g_sEnemyTwo.m_cLocation.X = 47;
	g_sEnemyTwo.m_cLocation.Y = 7;
	g_sEnemyThree.m_cLocation.X = 50;
	g_sEnemyThree.m_cLocation.Y = 14;
	g_sEnemyFour.m_cLocation.X = 8;
	g_sEnemyFour.m_cLocation.Y = 12;
	g_sEnemyFive.m_cLocation.X = 23;
	g_sEnemyFive.m_cLocation.Y = 10;
}

void LOAD_ENEMY_EIGHT()
{
	reverse1 = false;
	reverse2 = false;
	reverse3 = false;
	reverse4 = false;
	reverse5 = false;
	g_sEnemyOne.m_cLocation.X = 1; //X
	g_sEnemyOne.m_cLocation.Y = 1;
	g_sEnemyTwo.m_cLocation.X = 17; //Y
	g_sEnemyTwo.m_cLocation.Y = 16;
	g_sEnemyThree.m_cLocation.X = 50; //Z
	g_sEnemyThree.m_cLocation.Y = 16;
	g_sEnemyFour.m_cLocation.X = 1; //V
	g_sEnemyFour.m_cLocation.Y = 8;
	g_sEnemyFive.m_cLocation.X = 23; //W
	g_sEnemyFive.m_cLocation.Y = 3;
}

void LOAD_ENEMY_NINE()
{
	reverse1 = false;
	reverse2 = false;
	reverse3 = false;
	reverse4 = false;
	reverse5 = false;
	g_sEnemyOne.m_cLocation.X = 5; //X
	g_sEnemyOne.m_cLocation.Y = 1;
	g_sEnemyTwo.m_cLocation.X = 17; //Y
	g_sEnemyTwo.m_cLocation.Y = 12;
	g_sEnemyThree.m_cLocation.X = 50; //Z
	g_sEnemyThree.m_cLocation.Y = 16;
	g_sEnemyFour.m_cLocation.X = 40; //V
	g_sEnemyFour.m_cLocation.Y = 10;
	g_sEnemyFive.m_cLocation.X = 45; //W
	g_sEnemyFive.m_cLocation.Y = 4;
}

void LOAD_ENEMY_TEN()
{
	reverse1 = false;
	reverse2 = false;
	reverse3 = false;
	reverse4 = false;
	reverse5 = false;
	reverse6 = false;
	g_sEnemyOne.m_cLocation.X = 22; //X
	g_sEnemyOne.m_cLocation.Y = 1;
	g_sEnemyTwo.m_cLocation.X = 24; //Y
	g_sEnemyTwo.m_cLocation.Y = 14;
	g_sEnemyThree.m_cLocation.X = 50; //Z
	g_sEnemyThree.m_cLocation.Y = 16;
	g_sEnemyFour.m_cLocation.X = 40; //V
	g_sEnemyFour.m_cLocation.Y = 12;
	g_sEnemyFive.m_cLocation.X = 45; //W
	g_sEnemyFive.m_cLocation.Y = 4;
	g_sEnemySix.m_cLocation.X = 1; //S
	g_sEnemySix.m_cLocation.Y = 11;
}


void ENEMY_ROUTE(int i)
{
	if(pausemovement == true)
		return;
	switch(i)
	{
	case 0: LOAD_EPATH_ZERO();
		break;
	case 1: LOAD_EPATH_ONE();
		break;
	case 2: LOAD_EPATH_TWO();
		break;
	case 3: LOAD_EPATH_THREE();
		break;
	case 4: LOAD_EPATH_FOUR();
		break;
	case 5: LOAD_EPATH_FIVE();
		break;
	case 6: LOAD_EPATH_SIX();
		break;
	case 7: LOAD_EPATH_SEVEN();
		break;
	case 8: LOAD_EPATH_EIGHT();
		break;
	case 9: LOAD_EPATH_NINE();
		break;
	case 10: LOAD_EPATH_TEN();
		break;
	}
}


void LOAD_EPATH_ZERO()
{
	if(reverse1 == false)
	{
		if(g_sEnemyOne.m_cLocation.Y!=6)
		{
		g_sEnemyOne.m_cLocation.Y+=1;
		if(g_sEnemyOne.m_cLocation.Y == 6)
			reverse1 = true;
		}
	}
	if(reverse1 == true)
	{
		if(g_sEnemyOne.m_cLocation.Y!=1)
		{
		g_sEnemyOne.m_cLocation.Y-=1;
		if(g_sEnemyOne.m_cLocation.Y == 1)
			reverse1 = false;
		}
	}
	if(reverse2 == false)
	{
		if(g_sEnemyTwo.m_cLocation.X != 40)
		{
		g_sEnemyTwo.m_cLocation.X+=1;
		if(g_sEnemyTwo.m_cLocation.X == 40)
			reverse2 = true;
		}
	}
	if(reverse2 == true)
	{
		if(g_sEnemyTwo.m_cLocation.X != 22)
		{
		g_sEnemyTwo.m_cLocation.X-=1;
		if(g_sEnemyTwo.m_cLocation.X == 22)
			reverse2 = false;
		}
	}
}

void LOAD_EPATH_ONE()
{
	if(reverse1 == false)
	{
		if(g_sEnemyOne.m_cLocation.X!=24)
		{
			g_sEnemyOne.m_cLocation.X+=1;
			if(g_sEnemyOne.m_cLocation.X == 24)
				reverse1 = true;
		}	
	}
	if(reverse1 == true)
	{
		if(g_sEnemyOne.m_cLocation.X!=18)
		{
		g_sEnemyOne.m_cLocation.X-=1;
		if(g_sEnemyOne.m_cLocation.X == 18)
			reverse1 = false;
		}
	}
	if(reverse2 == false)
	{
		if(g_sEnemyTwo.m_cLocation.X != 40)
		{
			g_sEnemyTwo.m_cLocation.X+=1;
			if(g_sEnemyTwo.m_cLocation.X == 40)
				reverse2 = true;
		}
	}
	if(reverse2 == true)
	{
		if(g_sEnemyTwo.m_cLocation.X != 18)
		{
			g_sEnemyTwo.m_cLocation.X-=1;
			if(g_sEnemyTwo.m_cLocation.X == 18)
				reverse2 = false;
		}
	}
	if(reverse3 == false)
	{
		if(g_sEnemyThree.m_cLocation.X != 50)
		{
			g_sEnemyThree.m_cLocation.X+=1;
			if(g_sEnemyThree.m_cLocation.X == 50)
				reverse3 = true;
		}
	}
	if(reverse3 == true)
	{
		if(g_sEnemyThree.m_cLocation.X != 43)
		{
			g_sEnemyThree.m_cLocation.X-=1;
			if(g_sEnemyThree.m_cLocation.X == 43)
				reverse3 = false;
		}
	}
}
	
void LOAD_EPATH_TWO()
{
	if(reverse1 == false)
		{
			if(g_sEnemyOne.m_cLocation.X!=29)
			{
			g_sEnemyOne.m_cLocation.X+=1;
			if(g_sEnemyOne.m_cLocation.X == 29)
				reverse1 = true;
			}
		}
		if(reverse1 == true)
		{
			if(g_sEnemyOne.m_cLocation.X!=16)
			{
			g_sEnemyOne.m_cLocation.X-=1;
			if(g_sEnemyOne.m_cLocation.X == 16)
				reverse1 = false;
			}
		}
		if(reverse2 == false)
		{
			if(g_sEnemyTwo.m_cLocation.Y != 7)
			{
			g_sEnemyTwo.m_cLocation.Y+=1;
			if(g_sEnemyTwo.m_cLocation.Y == 7)
				reverse2 = true;
			}
		}
		if(reverse2 == true)
		{
			if(g_sEnemyTwo.m_cLocation.Y != 1)
			{
			g_sEnemyTwo.m_cLocation.Y-=1;
			if(g_sEnemyTwo.m_cLocation.Y == 1)
				reverse2 = false;
			}
		}
		if(reverse3 == false)
		{
			if(g_sEnemyThree.m_cLocation.Y != 0)
			{
			g_sEnemyThree.m_cLocation.Y-=1;
			if(g_sEnemyThree.m_cLocation.Y == 0)
				reverse3 = true;
			}
		}
		if(reverse3 == true)
		{
			if(g_sEnemyThree.m_cLocation.Y != 6)
			{
			g_sEnemyThree.m_cLocation.Y+=1;
			if(g_sEnemyThree.m_cLocation.Y == 6)
				reverse3 = false;
			}
		}
	}

void LOAD_EPATH_THREE()
{
	if(reverse1 == false)
		{
			if(g_sEnemyOne.m_cLocation.X!=23)
			{
			g_sEnemyOne.m_cLocation.X+=1;
			if(g_sEnemyOne.m_cLocation.X == 23)
				reverse1 = true;
			}
		}
		if(reverse1 == true)
		{
			if(g_sEnemyOne.m_cLocation.X!=12)
			{
			g_sEnemyOne.m_cLocation.X-=1;
			if(g_sEnemyOne.m_cLocation.X == 12)
				reverse1 = false;
			}
		}
		if(reverse2 == false)
		{
			if(g_sEnemyTwo.m_cLocation.X != 57)
			{
			g_sEnemyTwo.m_cLocation.X+=1;
			if(g_sEnemyTwo.m_cLocation.X == 55)
				reverse2 = true;
			}
		}
		if(reverse2 == true)
		{
			if(g_sEnemyTwo.m_cLocation.X != 47)
			{
			g_sEnemyTwo.m_cLocation.X-=1;
			if(g_sEnemyTwo.m_cLocation.X == 47)
				reverse2 = false;
			}
		}
		if(reverse3 == false)
		{
			if(g_sEnemyThree.m_cLocation.Y != 7)
			{
			g_sEnemyThree.m_cLocation.Y+=1;
			if(g_sEnemyThree.m_cLocation.Y == 7)
				reverse3 = true;
			}
		}
		if(reverse3 == true)
		{
			if(g_sEnemyThree.m_cLocation.Y != 1)
			{
			g_sEnemyThree.m_cLocation.Y-=1;
			if(g_sEnemyThree.m_cLocation.Y == 1)
				reverse3 = false;
			}
		}
}

void LOAD_EPATH_FOUR()
{
	if(reverse1 == false)
		{
			if(g_sEnemyOne.m_cLocation.Y!=9)
			{
			g_sEnemyOne.m_cLocation.Y+=1;
			if(g_sEnemyOne.m_cLocation.Y == 9)
				reverse1 = true;
			}
		}
		if(reverse1 == true)
		{
			if(g_sEnemyOne.m_cLocation.Y!=1)
			{
			g_sEnemyOne.m_cLocation.Y-=1;
			if(g_sEnemyOne.m_cLocation.Y == 1)
				reverse1 = false;
			}
		}
		if(reverse2 == false)
		{
			if(g_sEnemyTwo.m_cLocation.X != 28)
			{
			g_sEnemyTwo.m_cLocation.X+=1;
			if(g_sEnemyTwo.m_cLocation.X == 28)
				reverse2 = true;
			}
		}
		if(reverse2 == true)
		{
			if(g_sEnemyTwo.m_cLocation.X != 17)
			{
			g_sEnemyTwo.m_cLocation.X-=1;
			if(g_sEnemyTwo.m_cLocation.X == 17)
				reverse2 = false;
			}
		}
		if(reverse3 == false)
		{
			if(g_sEnemyThree.m_cLocation.X != 58)
			{
			g_sEnemyThree.m_cLocation.X+=1;
			if(g_sEnemyThree.m_cLocation.X == 58)
				reverse3 = true;
			}
		}
		if(reverse3 == true)
		{
			if(g_sEnemyThree.m_cLocation.X != 35)
			{
			g_sEnemyThree.m_cLocation.X-=1;
			if(g_sEnemyThree.m_cLocation.X == 35)
				reverse3 = false;
			}
		}
		if(reverse4 == false)
		{
			if(g_sEnemyFour.m_cLocation.X!=36)
			{
			g_sEnemyFour.m_cLocation.X+=1;
			if(g_sEnemyFour.m_cLocation.X == 36)
				reverse4 = true;
			}
		}
		if(reverse4 == true)
		{
			if(g_sEnemyFour.m_cLocation.X!=1)
			{
			g_sEnemyFour.m_cLocation.X-=1;
			if(g_sEnemyFour.m_cLocation.X == 1)
				reverse4 = false;
			}
		}
}

void LOAD_EPATH_FIVE()
{
	if(reverse1 == false)
		{
			if(g_sEnemyOne.m_cLocation.X!=59)
			{
			g_sEnemyOne.m_cLocation.X+=1;
			if(g_sEnemyOne.m_cLocation.X == 59)
				reverse1 = true;
			}
		}
		if(reverse1 == true)
		{
			if(g_sEnemyOne.m_cLocation.X!=56)
			{
			g_sEnemyOne.m_cLocation.X-=1;
			if(g_sEnemyOne.m_cLocation.X == 56)
				reverse1 = false;
			}
		}
		if(reverse2 == false)
		{
			if(g_sEnemyTwo.m_cLocation.X != 27)
			{
			g_sEnemyTwo.m_cLocation.X+=1;
			if(g_sEnemyTwo.m_cLocation.X == 27)
				reverse2 = true;
			}
		}
		if(reverse2 == true)
		{
			if(g_sEnemyTwo.m_cLocation.X != 11)
			{
			g_sEnemyTwo.m_cLocation.X-=1;
			if(g_sEnemyTwo.m_cLocation.X == 11)
				reverse2 = false;
			}
		}
		if(reverse3 == false)
		{
			if(g_sEnemyThree.m_cLocation.Y != 11)
			{
			g_sEnemyThree.m_cLocation.Y+=1;
			if(g_sEnemyThree.m_cLocation.Y == 11)
				reverse3 = true;
			}
		}
		if(reverse3 == true)
		{
			if(g_sEnemyThree.m_cLocation.Y != 1)
			{
			g_sEnemyThree.m_cLocation.Y-=1;
			if(g_sEnemyThree.m_cLocation.Y == 1)
				reverse3 = false;
			}
		}
		if(reverse4 == false)
		{
			if(g_sEnemyFour.m_cLocation.X!=22)
			{
			g_sEnemyFour.m_cLocation.X+=1;
			if(g_sEnemyFour.m_cLocation.X == 22)
				reverse4 = true;
			}
		}
		if(reverse4 == true)
		{
			if(g_sEnemyFour.m_cLocation.X!=2)
			{
			g_sEnemyFour.m_cLocation.X-=1;
			if(g_sEnemyFour.m_cLocation.X == 2)
				reverse4 = false;
			}
		}
}

void LOAD_EPATH_SIX()
{
	if(reverse1 == false)
		{
			if(g_sEnemyOne.m_cLocation.X!=33)
			{
			g_sEnemyOne.m_cLocation.X+=1;
			if(g_sEnemyOne.m_cLocation.X == 33)
				reverse1 = true;
			}
		}
		if(reverse1 == true)
		{
			if(g_sEnemyOne.m_cLocation.X!=6)
			{
			g_sEnemyOne.m_cLocation.X-=1;
			if(g_sEnemyOne.m_cLocation.X == 6)
				reverse1 = false;
			}
		}
		if(reverse2 == false)
		{
			if(g_sEnemyTwo.m_cLocation.X != 54)
			{
			g_sEnemyTwo.m_cLocation.X+=1;
			if(g_sEnemyTwo.m_cLocation.X == 54)
				reverse2 = true;
			}
		}
		if(reverse2 == true)
		{
			if(g_sEnemyTwo.m_cLocation.X != 47)
			{
			g_sEnemyTwo.m_cLocation.X-=1;
			if(g_sEnemyTwo.m_cLocation.X == 47)
				reverse2 = false;
			}
		}
		if(reverse3 == false)
		{
			if(g_sEnemyThree.m_cLocation.Y != 13)
			{
			g_sEnemyThree.m_cLocation.Y+=1;
			if(g_sEnemyThree.m_cLocation.Y == 13)
				reverse3 = true;
			}
		}
		if(reverse3 == true)
		{
			if(g_sEnemyThree.m_cLocation.Y != 1)
			{
			g_sEnemyThree.m_cLocation.Y-=1;
			if(g_sEnemyThree.m_cLocation.Y == 1)
				reverse3 = false;
			}
		}
		if(reverse4 == false)
		{
			if(g_sEnemyFour.m_cLocation.Y!=0)
			{
			g_sEnemyFour.m_cLocation.Y-=1;
			if(g_sEnemyFour.m_cLocation.Y == 0)
				reverse4 = true;
			}
		}
		if(reverse4 == true)
		{
			if(g_sEnemyFour.m_cLocation.Y!=8)
			{
			g_sEnemyFour.m_cLocation.Y+=1;
			if(g_sEnemyFour.m_cLocation.Y == 8)
				reverse4 = false;
			}
		}
}

void LOAD_EPATH_SEVEN()
{
	if(reverse1 == false)
		{
			if(g_sEnemyOne.m_cLocation.X!= 21)
			{
			g_sEnemyOne.m_cLocation.X+=1;
			if(g_sEnemyOne.m_cLocation.X == 21)
				reverse1 = true;
			}
		}
		if(reverse1 == true)
		{
			if(g_sEnemyOne.m_cLocation.X!=9)
			{
			g_sEnemyOne.m_cLocation.X-=1;
			if(g_sEnemyOne.m_cLocation.X == 9)
				reverse1 = false;
			}
		}
		if(reverse2 == false)
		{
			if(g_sEnemyTwo.m_cLocation.X != 53)
			{
			g_sEnemyTwo.m_cLocation.X+=1;
			if(g_sEnemyTwo.m_cLocation.X == 53)
				reverse2 = true;
			}
		}
		if(reverse2 == true)
		{
			if(g_sEnemyTwo.m_cLocation.X != 45)
			{
			g_sEnemyTwo.m_cLocation.X-=1;
			if(g_sEnemyTwo.m_cLocation.X == 45)
				reverse2 = false;
			}
		}
		if(reverse3 == false)
		{
			if(g_sEnemyThree.m_cLocation.X != 59)
			{
			g_sEnemyThree.m_cLocation.X+=1;
			if(g_sEnemyThree.m_cLocation.X == 59)
				reverse3 = true;
			}
		}
		if(reverse3 == true)
		{
			if(g_sEnemyThree.m_cLocation.X != 50)
			{
			g_sEnemyThree.m_cLocation.X-=1;
			if(g_sEnemyThree.m_cLocation.X == 50)
				reverse3 = false;
			}
		}
		if(reverse4 == false)
		{
			if(g_sEnemyFour.m_cLocation.X!=17)
			{
			g_sEnemyFour.m_cLocation.X+=1;
			if(g_sEnemyFour.m_cLocation.X == 17)
				reverse4 = true;
			}
		}
		if(reverse4 == true)
		{
			if(g_sEnemyFour.m_cLocation.X!=7)
			{
			g_sEnemyFour.m_cLocation.X-=1;
			if(g_sEnemyFour.m_cLocation.X == 7)
				reverse4 = false;
			}
		}
		if(reverse5 == false)
		{
			if(g_sEnemyFive.m_cLocation.X!=39)
			{
			g_sEnemyFive.m_cLocation.X+=1;
			if(g_sEnemyFive.m_cLocation.X == 39)
				reverse5 = true;
			}
		}
		if(reverse5 == true)
		{
			if(g_sEnemyFive.m_cLocation.X!=23)
			{
			g_sEnemyFive.m_cLocation.X-=1;
			if(g_sEnemyFive.m_cLocation.X == 23)
				reverse5 = false;
			}
		}

}

void LOAD_EPATH_EIGHT()
{
	if(reverse1 == false)
		{
			if(g_sEnemyOne.m_cLocation.X!= 13)
			{
			g_sEnemyOne.m_cLocation.X+=1;
			if(g_sEnemyOne.m_cLocation.X == 13)
				reverse1 = true;
			}
		}
		if(reverse1 == true)
		{
			if(g_sEnemyOne.m_cLocation.X!=1)
			{
			g_sEnemyOne.m_cLocation.X-=1;
			if(g_sEnemyOne.m_cLocation.X == 1)
				reverse1 = false;
			}
		}
		if(reverse2 == false)
		{
			if(g_sEnemyTwo.m_cLocation.X != 29)
			{
			g_sEnemyTwo.m_cLocation.X+=1;
			if(g_sEnemyTwo.m_cLocation.X == 29)
				reverse2 = true;
			}
		}
		if(reverse2 == true)
		{
			if(g_sEnemyTwo.m_cLocation.X != 17)
			{
			g_sEnemyTwo.m_cLocation.X-=1;
			if(g_sEnemyTwo.m_cLocation.X == 17)
				reverse2 = false;
			}
		}
		if(reverse3 == false)
		{
			if(g_sEnemyThree.m_cLocation.X != 59)
			{
			g_sEnemyThree.m_cLocation.X+=1;
			if(g_sEnemyThree.m_cLocation.X == 59)
				reverse3 = true;
			}
		}
		if(reverse3 == true)
		{
			if(g_sEnemyThree.m_cLocation.X != 49)
			{
			g_sEnemyThree.m_cLocation.X-=1;
			if(g_sEnemyThree.m_cLocation.X == 49)
				reverse3 = false;
			}
		}
		if(reverse4 == false)
		{
			if(g_sEnemyFour.m_cLocation.X!=17)
			{
			g_sEnemyFour.m_cLocation.X+=1;
			if(g_sEnemyFour.m_cLocation.X == 17)
				reverse4 = true;
			}
		}
		if(reverse4 == true)
		{
			if(g_sEnemyFour.m_cLocation.X!=1)
			{
			g_sEnemyFour.m_cLocation.X-=1;
			if(g_sEnemyFour.m_cLocation.X == 1)
				reverse4 = false;
			}
		}
		if(reverse5 == false)
		{
			if(g_sEnemyFive.m_cLocation.X!=33)
			{
			g_sEnemyFive.m_cLocation.X+=1;
			if(g_sEnemyFive.m_cLocation.X == 33)
				reverse5 = true;
			}
		}
		if(reverse5 == true)
		{
			if(g_sEnemyFive.m_cLocation.X!=22)
			{
			g_sEnemyFive.m_cLocation.X-=1;
			if(g_sEnemyFive.m_cLocation.X == 22)
				reverse5 = false;
			}
		}

}

void LOAD_EPATH_NINE()
{
	if(reverse1 == false)
		{
			if(g_sEnemyOne.m_cLocation.X!= 18)
			{
			g_sEnemyOne.m_cLocation.X+=1;
			if(g_sEnemyOne.m_cLocation.X == 18)
				reverse1 = true;
			}
		}
		if(reverse1 == true)
		{
			if(g_sEnemyOne.m_cLocation.X!=7)
			{
			g_sEnemyOne.m_cLocation.X-=1;
			if(g_sEnemyOne.m_cLocation.X == 7)
				reverse1 = false;
			}
		}
		if(reverse2 == false)
		{
			if(g_sEnemyTwo.m_cLocation.X != 27)
			{
			g_sEnemyTwo.m_cLocation.X+=1;
			if(g_sEnemyTwo.m_cLocation.X == 27)
				reverse2 = true;
			}
		}
		if(reverse2 == true)
		{
			if(g_sEnemyTwo.m_cLocation.X != 17)
			{
			g_sEnemyTwo.m_cLocation.X-=1;
			if(g_sEnemyTwo.m_cLocation.X == 17)
				reverse2 = false;
			}
		}
		if(reverse3 == false)
		{
			if(g_sEnemyThree.m_cLocation.X != 57)
			{
			g_sEnemyThree.m_cLocation.X+=1;
			if(g_sEnemyThree.m_cLocation.X == 57)
				reverse3 = true;
			}
		}
		if(reverse3 == true)
		{
			if(g_sEnemyThree.m_cLocation.X != 45)
			{
			g_sEnemyThree.m_cLocation.X-=1;
			if(g_sEnemyThree.m_cLocation.X == 45)
				reverse3 = false;
			}
		}
		if(reverse4 == false)
		{
			if(g_sEnemyFour.m_cLocation.X!=52)
			{
			g_sEnemyFour.m_cLocation.X+=1;
			if(g_sEnemyFour.m_cLocation.X == 52)
				reverse4 = true;
			}
		}
		if(reverse4 == true)
		{
			if(g_sEnemyFour.m_cLocation.X!=38)
			{
			g_sEnemyFour.m_cLocation.X-=1;
			if(g_sEnemyFour.m_cLocation.X == 38)
				reverse4 = false;
			}
		}
		if(reverse5 == false)
		{
			if(g_sEnemyFive.m_cLocation.X!=57)
			{
			g_sEnemyFive.m_cLocation.X+=1;
			if(g_sEnemyFive.m_cLocation.X == 57)
				reverse5 = true;
			}
		}
		if(reverse5 == true)
		{
			if(g_sEnemyFive.m_cLocation.X!=45)
			{
			g_sEnemyFive.m_cLocation.X-=1;
			if(g_sEnemyFive.m_cLocation.X == 45)
				reverse5 = false;
			}
		}

}

void LOAD_EPATH_TEN()
{
	if(reverse1 == false)
		{
			if(g_sEnemyOne.m_cLocation.Y!= 15)
			{
			g_sEnemyOne.m_cLocation.Y+=1;
			if(g_sEnemyOne.m_cLocation.Y == 15)
				reverse1 = true;
			}
		}
		if(reverse1 == true)
		{
			if(g_sEnemyOne.m_cLocation.Y!=1)
			{
			g_sEnemyOne.m_cLocation.Y-=1;
			if(g_sEnemyOne.m_cLocation.Y == 1)
				reverse1 = false;
			}
		}
		if(reverse2 == false)
		{
			if(g_sEnemyTwo.m_cLocation.Y != 15)
			{
			g_sEnemyTwo.m_cLocation.Y+=1;
			if(g_sEnemyTwo.m_cLocation.Y == 15)
				reverse2 = true;
			}
		}
		if(reverse2 == true)
		{
			if(g_sEnemyTwo.m_cLocation.Y != 1)
			{
			g_sEnemyTwo.m_cLocation.Y-=1;
			if(g_sEnemyTwo.m_cLocation.Y == 1)
				reverse2 = false;
			}
		}
		if(reverse3 == false)
		{
			if(g_sEnemyThree.m_cLocation.X != 55)
			{
			g_sEnemyThree.m_cLocation.X+=1;
			if(g_sEnemyThree.m_cLocation.X == 55)
				reverse3 = true;
			}
		}
		if(reverse3 == true)
		{
			if(g_sEnemyThree.m_cLocation.X != 46)
			{
			g_sEnemyThree.m_cLocation.X-=1;
			if(g_sEnemyThree.m_cLocation.X == 46)
				reverse3 = false;
			}
		}
		if(reverse4 == false)
		{
			if(g_sEnemyFour.m_cLocation.X!=52)
			{
			g_sEnemyFour.m_cLocation.X+=1;
			if(g_sEnemyFour.m_cLocation.X == 52)
				reverse4 = true;
			}
		}
		if(reverse4 == true)
		{
			if(g_sEnemyFour.m_cLocation.X!=38)
			{
			g_sEnemyFour.m_cLocation.X-=1;
			if(g_sEnemyFour.m_cLocation.X == 38)
				reverse4 = false;
			}
		}
		if(reverse5 == false)
		{
			if(g_sEnemyFive.m_cLocation.X!=64)
			{
			g_sEnemyFive.m_cLocation.X+=1;
			if(g_sEnemyFive.m_cLocation.X == 64)
				reverse5 = true;
			}
		}
		if(reverse5 == true)
		{
			if(g_sEnemyFive.m_cLocation.X!=34)
			{
			g_sEnemyFive.m_cLocation.X-=1;
			if(g_sEnemyFive.m_cLocation.X == 34)
				reverse5 = false;
			}
		}
		if(reverse6 == false)
		{
			if(g_sEnemySix.m_cLocation.X!=21)
			{
			g_sEnemySix.m_cLocation.X+=1;
			if(g_sEnemySix.m_cLocation.X == 21)
				reverse6 = true;
			}
		}
		if(reverse6 == true)
		{
			if(g_sEnemySix.m_cLocation.X!=1)
			{
			g_sEnemySix.m_cLocation.X-=1;
			if(g_sEnemySix.m_cLocation.X == 1)
				reverse6 = false;
			}
		}
}


void ENEMY_MOVEMENT(int i)
{
	if (velocity > g_dElapsedTime)
	return;
	velocity = g_dElapsedTime + 0.125;
	ENEMY_ROUTE(i);
}

void ENEMY_PRINT(int i)
{
	if(printmap == false)
		return;
	else if(printmap == true)
	{
	if(i == 0)
	{
			g_Console.writeToBuffer(g_sEnemyOne.m_cLocation, 'X', 0x0B);
			g_Console.writeToBuffer(g_sEnemyTwo.m_cLocation, 'Y', 0x0B);
	}
	if(i == 1|| i ==2 || i == 3)
	{
			g_Console.writeToBuffer(g_sEnemyOne.m_cLocation, 'X', 0x0B);
			g_Console.writeToBuffer(g_sEnemyTwo.m_cLocation, 'Y', 0x0B);
			g_Console.writeToBuffer(g_sEnemyThree.m_cLocation, 'Z', 0x0B);
	}
	if(i == 4 || i == 5 || i == 6)
	{
		g_Console.writeToBuffer(g_sEnemyOne.m_cLocation, 'X', 0x0B);
		g_Console.writeToBuffer(g_sEnemyTwo.m_cLocation, 'Y', 0x0B);
		g_Console.writeToBuffer(g_sEnemyThree.m_cLocation, 'Z', 0x0B);
		g_Console.writeToBuffer(g_sEnemyFour.m_cLocation, 'V', 0x0B);
	}
	if(i == 7 || i == 8 || i == 9)
	{
		g_Console.writeToBuffer(g_sEnemyOne.m_cLocation, 'X', 0x0B);
		g_Console.writeToBuffer(g_sEnemyTwo.m_cLocation, 'Y', 0x0B);
		g_Console.writeToBuffer(g_sEnemyThree.m_cLocation, 'Z', 0x0B);
		g_Console.writeToBuffer(g_sEnemyFour.m_cLocation, 'V', 0x0B);
		g_Console.writeToBuffer(g_sEnemyFive.m_cLocation, 'W', 0x0B);
	}
	if(i == 10)
	{
		g_Console.writeToBuffer(g_sEnemyOne.m_cLocation, 'X', 0x0B);
		g_Console.writeToBuffer(g_sEnemyTwo.m_cLocation, 'Y', 0x0B);
		g_Console.writeToBuffer(g_sEnemyThree.m_cLocation, 'Z', 0x0B);
		g_Console.writeToBuffer(g_sEnemyFour.m_cLocation, 'V', 0x0B);
		g_Console.writeToBuffer(g_sEnemyFive.m_cLocation, 'W', 0x0B);
		g_Console.writeToBuffer(g_sEnemySix.m_cLocation, 'S', 0x0B);
	}
	}
}