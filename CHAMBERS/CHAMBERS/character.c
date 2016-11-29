#include <SDL.h>
#include <SDL_image.h>
#include "character.h"
#include "global.h"

void ImageLoad(Texture* t, const char* imgPath){
	t->surface = IMG_Load(imgPath);
	t->texture = SDL_CreateTextureFromSurface(renderer, t->surface);
}

int DetectCollision(HitBox* a, HitBox* b){
	if(a->rect.x < b->rect.x + b->rect.w
		&& a->rect.x + a->rect.w > b->rect.x
		&& a->rect.y < b->rect.y + b->rect.h
		&& a->rect.y + a->rect.h > b->rect.y){
			return 1;
	}
	return 0;
}

void UpdateHitBoxChars(Character* c, int x, int y, int w, int h){
	c->hitbox.rect.x = c->position.rect.x + x;
	c->hitbox.rect.y = c->position.rect.y + y;
	c->hitbox.rect.w = w;
	c->hitbox.rect.h = h;
}

void UpdateHurtBoxChars(Character* c, int x, int y, int w, int h){
	c->hurtbox.rect.x = c->position.rect.x + x;
	c->hurtbox.rect.y = c->position.rect.y + y;
	c->hurtbox.rect.w = w;
	c->hurtbox.rect.h = h;
}