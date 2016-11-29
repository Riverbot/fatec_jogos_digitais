#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "global.h"

int ColisionClick(SDL_Rect a, SDL_MouseMotionEvent m) {
	if (m.x > a.x && m.x < a.x + a.w
		&& m.y > a.y && m.y < a.y + a.h) {
		return 1;
	}
	return 0;
}

SDL_Color ColorYELLOW = { 255, 255, 0 };
SDL_Color ColorRED = { 255, 0, 0 };
SDL_Color ColorWHITE = { 100, 100, 100 };

int OnExit() {

	SDL_RenderClear(renderer);

	while (1) {

		FontTitle.DrawOnRender(&FontTitle, "Do you really like to exit?", 100, 200, 800, 100, ColorWHITE);
		FontCredit.DrawOnRender(&FontCredit, "YES", 100, 300, 100, 100, ColorWHITE);
		FontExit.DrawOnRender(&FontExit, "NO", 300, 300, 100, 100, ColorWHITE);

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				exit(0);
				break;

			case SDL_MOUSEBUTTONDOWN:
				if (ColisionClick(FontCredit.position.rect, event.motion)) { exit(0); }
				else if (ColisionClick(FontExit.position.rect, event.motion)) { return 1; }
			}
		}

		SDL_RenderPresent(renderer);
	}
}

int Credits() {
	int y;
	int acel = 1;
	y = SCREEN_HEIGHT;
	
	while (1) {
	
		SDL_RenderClear(renderer);
		
		if(y > 200){
			y -= acel;
		}
		FontTitle.DrawOnRender(&FontTitle, "Developer HENRIQUE OLIVEIRA", 100, y, 800, 100, ColorWHITE);
		FontCredit.DrawOnRender(&FontCredit, "Teacher ANTONIO", 100, y+100, 800, 100, ColorWHITE);
		
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				exit(0);
				break;

			case SDL_KEYDOWN:
				return 1;
				break;
			}
		}

		SDL_RenderPresent(renderer);
	}
}

int MainMenu() {
	while (1) {
		SDL_RenderClear(renderer);

		FontTitle.DrawOnRender(&FontTitle, "Gold Rush", 130, 100, 800, 200, ColorYELLOW);
		FontNewGame.DrawOnRender(&FontNewGame, "New Game", 200, 300, 250, 100, ColorWHITE);
		FontCredit.DrawOnRender(&FontCredit, "Credits", 200, 400, 250, 100, ColorWHITE);
		FontExit.DrawOnRender(&FontExit, "Exit", 200, 500, 250, 100, ColorWHITE);

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				exit(0);
				break;

			case SDL_MOUSEBUTTONDOWN:
				if (ColisionClick(FontNewGame.position.rect, event.motion)) { return 1; }
				else if (ColisionClick(FontCredit.position.rect, event.motion)) { Credits(); }
				else if (ColisionClick(FontExit.position.rect, event.motion)) { OnExit(); }
			}
		}

		SDL_RenderPresent(renderer);
	}
	return 0;
}