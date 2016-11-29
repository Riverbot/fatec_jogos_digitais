#include "character.h"

int spacing = 32;
float fps = 5;

void IdleAnimation(Character* c) {
	c->texture.rect.x += spacing;
	c->texture.rect.y = 1;

	if(c->texture.rect.x > 288){
		c->texture.rect.x = 0;
	}
}
void WalkAnimation(Character* c) {
	c->texture.rect.x += spacing;
	c->texture.rect.y = 64;

	if (c->texture.rect.x > 288) {
		c->texture.rect.x = 0;
	}
}
void AttackAnimation(Character* c) {
	c->texture.rect.x += spacing;
	c->texture.rect.y = 96;

	if (c->texture.rect.x > 288) {
		c->texture.rect.x = 0;
		c->att.attack = 0;
	}
}
void DeathAnimation(Character* c){
    c->texture.rect.x += spacing;
	c->texture.rect.y = 128;

	if (c->texture.rect.x > 288) {
		c->texture.rect.x = 0;
		c->att.attack = 0;
	}
}

void AnimationController(Character* c) {
    if (c->lives <= 0){
		if (fps == 0) {
			DeathAnimation(c);
			fps = 5;
		}
		fps -= 1;
    }else if (c->att.walkSpd == 0 && c->att.attack == 0){
		if (fps == 0) {
			IdleAnimation(c);
			fps = 5;
		}
		fps -= 1;
	}else if (c->att.walkSpd > 0) {
		if (fps == 0) {
			WalkAnimation(c);
			fps = 5;
		}
		fps -= 1;
	}else if(c->att.walkSpd < 0){
		if (fps == 0) {
			WalkAnimation(c);
			fps = 5;
		}
		fps -= 1;
	}else if (c->att.attack) {
		if (fps == 0) {
			AttackAnimation(c);
			fps = 5;
		}
		fps -= 1;
	}
}
