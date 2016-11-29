#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include "global.h"
#include "gold.h"
#include "font.h"

void FontLoad(Font* f, const char* fontPath, int ptsize){
	f->font = TTF_OpenFont(fontPath, ptsize);
}

void DrawFont(Font* f){
	SDL_RenderCopy(renderer, f->texture.texture, &f->texture.rect, &f->position.rect);
}

void DrawOnRender(Font* f, const char* text, int x, int y, int w, int h, SDL_Color color){
	f->texture.surface = TTF_RenderText_Solid(f->font, text, color);
	f->texture.texture = SDL_CreateTextureFromSurface(renderer, f->texture.surface);

	f->texture.rect.w = w;
	f->texture.rect.h = h;

	f->position.rect.x = x;
	f->position.rect.y = y;
	f->position.rect.w = w;
	f->position.rect.h = h;

	DrawFont(f);
}

void ConstructStructFuncFont(Font* f){
	f->DrawOnRender = DrawOnRender;
	f->FontLoad     = FontLoad;
}