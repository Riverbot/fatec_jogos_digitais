#include <SDL.h>
#pragma once

typedef struct Position{
	SDL_Rect rect;
}Position;

typedef struct HitBox{	
	SDL_Rect rect;
} HitBox;

typedef struct Attributes{
	int attack;
	int onGround;
	int flip;
	float walkSpd;
	float jumpStr;
	SDL_Point pivot;
}Attributes;

typedef struct Texture{
	SDL_Surface* surface;
	SDL_Texture* texture;
	SDL_Rect rect;
	void (*ImageLoad)(struct Texture*, const char*);
}Texture;

typedef struct Character{
	int exist;
	int lives;
	Attributes att;
	Texture texture;
	HitBox hitbox;
	HitBox hurtbox;
	Position position;
} Character;

void ImageLoad(Texture* t, const char* imgPath);
void UpdateHitBoxChars(Character* c, int x, int y, int w, int h);
void UpdateHurtBoxChars(Character* c, int x, int y, int w, int h);
int DetectCollision(HitBox* a, HitBox* b);