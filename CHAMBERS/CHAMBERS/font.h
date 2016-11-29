#include <SDL_ttf.h>
#include "character.h"
#pragma once

typedef struct Font {
	TTF_Font* font;
	Position position;
	Texture texture;
	SDL_Color color;
	void (*FontLoad)(struct Font*, const char*, int );
	void (*DrawOnRender)(struct Font*, const char*, int, int, int, int, SDL_Color);
}Font;

void ConstructStructFuncFont(Font* f);
