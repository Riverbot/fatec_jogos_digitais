#include "global.h"

void Draw() {
	int i = 0;

	SDL_RenderClear(renderer);

	player.DrawPlayer(&player.character);
	guard.DrawGuard(&guard.character);

	for (i = 0; i < GOLD_LENGTH; i++) {
		gold[i].DrawGold(&gold[i]);
	}

	FontScore.color.a = 255;
	FontScore.color.r = 200;
	FontScore.color.g = 10;
	FontScore.color.b = 100;

	FontScore.DrawOnRender(&FontScore, "S C O R E", 0, 0, 200, 50, FontScore.color);
	FontPontuation.DrawOnRender(&FontScore, score.txtScore, 250, 0, 200, 50, FontScore.color);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
	SDL_RenderDrawRect(renderer, &player.character.hitbox.rect);
	SDL_RenderDrawRect(renderer, &guard.character.hitbox.rect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
	SDL_RenderDrawRect(renderer, &player.character.hurtbox.rect);
	SDL_RenderDrawRect(renderer, &guard.character.hurtbox.rect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderPresent(renderer);
}