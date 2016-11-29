#include <SDL.h>
#include "character.h"
#include "player.h"
#include "guard.h"
#include "font.h"
#include "score.h"
#include "gold.h"

#pragma once

//Screen 
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 640

#define BLACK 0, 0, 0, 255

#define GOLD_LENGTH 10
#define GOLD_TICK 500

typedef enum { 
	NEWGAME, 
	OPTIONS, 
	CREDITS, 
	EXIT 
} MenuFlag;

SDL_Renderer * renderer;
SDL_Window   * window;

SDL_Event      event;

Player         player;
Guard	       guard;

Font           FontScore;
Font           FontPontuation;
Font           FontTitle;
Font           FontNewGame;
Font           FontCredit;
Font           FontExit;
Score		   score;
Gold           gold[GOLD_LENGTH];