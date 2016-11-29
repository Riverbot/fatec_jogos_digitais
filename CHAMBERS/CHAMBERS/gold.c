#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "character.h"
#include "font.h"
#include "global.h"
#include "gold.h"
#pragma once

void CreateGold(Gold* g){
	g->exist = 1;

	g->texture.ImageLoad(&g->texture, "gold32x32.png");

	g->texture.rect.x = ((rand() % 3) * 32);
	g->texture.rect.y = ((rand() % 2) * 32);
	g->texture.rect.w = 32;
	g->texture.rect.h = 32;

	g->position.rect.x = rand() % SCREEN_WIDTH - g->texture.rect.w;
	g->position.rect.y = 0;
	g->position.rect.w = 64;
	g->position.rect.h = 64;

	g->fallSpeed = 5;
}

void UpdateHitBoxGold(HitBox* hb, Position* pos){
	hb->rect.x = pos->rect.x + 25;
	hb->rect.y = pos->rect.y;
	hb->rect.w = pos->rect.w - 50;
	hb->rect.h = pos->rect.h;
}

void BehaviorGold(Gold* g){
	if(g->position.rect.y > SCREEN_HEIGHT - g->position.rect.h){
		g->onGround = 1;
		g->fallSpeed = 0;
	}else{
		g->position.rect.y += g->fallSpeed;
	}

	UpdateHitBoxGold(&g->hitbox, &g->position);

	if(DetectCollision(&g->hitbox, &player.character.hitbox)){
		score.SumScore();
		g->exist = 0;
	}
}

int TickGold = 0;
void DrawGold(Gold* g){
	if(TickGold > GOLD_TICK){
		if (!g->exist){
			CreateGold(g);
		}
		TickGold = 0;
	}

	if(g->exist){
		BehaviorGold(g);
		SDL_RenderCopy(renderer, g->texture.texture, &g->texture.rect, &g->position.rect);
	}

	TickGold++;
}

void ConstructStructFuncGold(Gold* g){
	g->DrawGold = DrawGold;
	g->texture.ImageLoad = ImageLoad;
}