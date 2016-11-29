#include <stdlib.h>
#include "global.h"
#include "guard.h"

void CreateGuard(Character* g){
	g->exist = 1;
	g->lives = 1;
	g->texture.ImageLoad(&g->texture, "guard16x32.png");

	g->texture.rect.x = 0;
	g->texture.rect.y = 0;
	g->texture.rect.w = 32;
	g->texture.rect.h = 32;

	if(rand() % 2 == 0){
		g->position.rect.x = -100;
	}else{
		g->position.rect.x = SCREEN_WIDTH + 100;
	}

	g->position.rect.w = 96;
	g->position.rect.h = 96;
	g->position.rect.y = 500;

	g->hurtbox.rect.w = 46;
	g->hurtbox.rect.h = 32;

	g->att.walkSpd = 2;
}

void DieGuard(Character* g){
	g->lives = 0;
	g->att.jumpStr = -5;
	g->hurtbox.rect.w = 0;
	g->hurtbox.rect.h = 0;
	g->hurtbox.rect.x = 0;
	g->hurtbox.rect.y = 0;
}

void GuardBehavior(Character* g, Character* p){

	g->att.jumpStr += 0.5;
	g->position.rect.y += g->att.jumpStr;

	if(!g->lives){
		g->att.flip = 2;

		if(g->position.rect.y > SCREEN_HEIGHT){
			g->exist = 0;
		}
	}else{

		if (g->position.rect.y > 500) {
			g->position.rect.y = 500;
			g->att.onGround = 1;
		}

		if (!DetectCollision(&g->hitbox, &p->hitbox)){
			if (g->position.rect.x < p->position.rect.x){
				g->position.rect.x += g->att.walkSpd;
				g->att.flip = 0;
			}else{
				g->position.rect.x -= g->att.walkSpd;
				g->att.flip = 1;
			}
		}else if (DetectCollision(&g->hitbox, &p->hitbox) && player.character.att.onGround){
			player.OnHit(&player.character);
			g->att.attack = 1;
			g->att.walkSpd = 0;
		}

		if(!g->att.attack){
			g->att.walkSpd = 2;
		}
	}
}

void RenderGuard(Character* g){
	SDL_RenderCopyEx(renderer, g->texture.texture, &g->texture.rect, &g->position.rect, 0, &g->att.pivot, g->att.flip);
}

void DropDead(Character* g){
	g->att.flip = 2;
}

void DrawGuard(Character* g){
	if (!g->exist){
		CreateGuard(g);
	}else if(g->exist){
		GuardBehavior(g, &player.character);
		UpdateHitBoxChars(g, 25, 32, 46, 64);
		UpdateHurtBoxChars(g, 25, 0, 46, 32);
		RenderGuard(g);
	}
}

void ConstructStructFuncGuard(Guard* g){
	g->DrawGuard = DrawGuard;
	g->DieGuard = DieGuard;
	g->character.texture.ImageLoad = ImageLoad;
}
