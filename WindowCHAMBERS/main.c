#include <SDL.h>
#include "global.h"
#include "KeyController.h"
#include "AnimationController.h"
#include "MainMenu.h"
#undef main

void EventHandler(){
	KeyController(&player);
	AnimationController(&player.character);
	AnimationController(&guard.character);
}

int gameOver = 0;
int main(){

	Init();
	MainMenu();

	while (!gameOver){
		EventHandler();
		Draw();
		SDL_Delay(16);
	}
}
