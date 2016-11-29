#include "character.h"
#pragma once

typedef struct Guard{
	Character character;
	void (*DrawGuard)(struct Character*);
	void (*DieGuard)(struct Character*);
} Guard;

void ConstructStructFuncGuard(Guard* g);