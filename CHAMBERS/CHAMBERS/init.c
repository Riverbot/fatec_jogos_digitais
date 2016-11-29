#include <SDL_image.h>
#include "global.h"

void Init() {
	int i = 0;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "FAILED TO INITIALIZE", ("Error Message: %s", SDL_GetError()), NULL);
		exit(0);
	}

	if (IMG_Init(IMG_INIT_PNG) == 0) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "FAILED TO INITIALIZE IMAGE", ("Error Message: %s", SDL_GetError()), NULL);
		exit(0);
	}

	if (TTF_Init()) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "FAILED TO INITIALIZE FONT", ("Error Message: %s", SDL_GetError()), NULL);
		exit(0);
	}

	window = SDL_CreateWindow("CHAMBERS v0.1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);

	ConstructStructFuncPlayer(&player);
	ConstructStructFuncGuard(&guard);
	ConstructStructFuncFont(&FontScore);
	ConstructStructFuncFont(&FontPontuation);
	ConstructStructFuncFont(&FontTitle);
	ConstructStructFuncFont(&FontNewGame);
	ConstructStructFuncFont(&FontCredit);
	ConstructStructFuncFont(&FontExit);

	ConstructStructFuncScore(&score);
	for (i = 0; i < GOLD_LENGTH; i++) {
		ConstructStructFuncGold(&gold[i]);
	}

	FontScore.FontLoad(&FontScore, "font/Super-Mario-World.ttf", 10);
	FontPontuation.FontLoad(&FontPontuation, "font/Super-Mario-World.ttf", 10);
	FontTitle.FontLoad(&FontTitle, "font/Super-Mario-World.ttf", 10);
	FontNewGame.FontLoad(&FontNewGame, "font/Super-Mario-World.ttf", 10);
	FontCredit.FontLoad(&FontCredit, "font/Super-Mario-World.ttf", 10);
	FontExit.FontLoad(&FontExit, "font/Super-Mario-World.ttf", 10);

	srand(time(NULL));
}
