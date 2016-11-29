#include "character.h"
#pragma once

typedef struct Player{
	Character character;
	void (*DrawPlayer)(struct Character*);
	void (*OnHit)(struct Character*);
	void (*Walk)(struct Character*, float);
	void (*Jump)(struct Character*, float);
} Player;

void ConstructStructFuncPlayer(Player* player);