#include <SDL.h>
#include "character.h"
#pragma once

typedef struct Gold{
	int exist;
	int onGround;
	float fallSpeed;
	Position position;
	Texture texture;
	HitBox hitbox;
	void (*DrawGold)(struct Gold*);
} Gold;

void ConstructStructFuncGold(Gold* g);
