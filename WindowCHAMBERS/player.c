#include <stdlib.h>
#include "global.h"
#include "player.h"

void CreatePlayer(Character* g){
	g->exist = 1;
	g->lives = 3;

	g->texture.ImageLoad(&g->texture, "rogue16x32.png");

	g->texture.rect.x = 0;
	g->texture.rect.y = 0;
	g->texture.rect.w = 32;
	g->texture.rect.h = 32;

	g->position.rect.x = 0;
	g->position.rect.y = 0;
	g->position.rect.w = 96;
	g->position.rect.h = 96;
}

int i;
void PlayerBehavior(Character* c){
	c->att.jumpStr += 0.5;
	c->position.rect.y += c->att.jumpStr;

	if(!c->lives){
		c->att.flip = 2;

		if(c->position.rect.y > SCREEN_HEIGHT){
			c->exist = 0;
		}
    }else if (DetectCollision(&c->hitbox, &guard.character.hurtbox) && !c->att.onGround){
        if (guard.character.lives > 0){
            guard.DieGuard(&guard.character);
        }
        c->att.jumpStr = -5;
    }

	if (c->position.rect.y > 500) {
			c->position.rect.y = 500;
			c->att.onGround = 1;
	}
}

void UpdatePos(Character* c){
	PlayerBehavior(c);
	c->position.rect.x += c->att.walkSpd;
	UpdateHitBoxChars(c, 25, 64, 46, 32);
	UpdateHurtBoxChars(c, 25, 0, 46, 64);
}

void RenderPlayer(Character* g){
	SDL_RenderCopyEx(renderer, g->texture.texture, &g->texture.rect, &g->position.rect, 0, &g->att.pivot, g->att.flip);
}

void DrawPlayer(Character* g){
	if (!g->exist){
		CreatePlayer(g);
	}else if(g->exist){
		UpdatePos(g);
		RenderPlayer(g);
	}
}

void Walk(Character* c, float speed){
	c->att.walkSpd = speed;
}

void Jump(Character* c, float speed){
	c->att.jumpStr = speed;
}

void OnHit(struct Character* c){
	c->lives--;
}

void ConstructStructFuncPlayer(Player* player){
	player->DrawPlayer = DrawPlayer;
	player->Walk = Walk;
	player->Jump = Jump;
	player->OnHit = OnHit;
	player->character.texture.ImageLoad = ImageLoad;
}
