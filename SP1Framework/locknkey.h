#ifndef _LOCKNKEY_H_
#define _LOCKNKEY_H_

#include "game.h"
#include "map.h"
#include "Framework\console.h"
#include <time.h>  
void LOCKDOOR(int x, int y, int z);
void UNLOCKEDDOOR(int i, SHORT X, SHORT Y);
void DOORZERO(SHORT X, SHORT Y);
void DOORONE(SHORT X, SHORT Y);
void DOORTWO(SHORT X, SHORT Y);
void UNLOCKKEY(int x, int y, int z);
void UNLOCK_UPDATE();
void RENDER_KD();
void KEY_RENDER();

#endif