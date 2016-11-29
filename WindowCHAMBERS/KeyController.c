#include "global.h"
#include "player.h"

void KeyController(Player* player){
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			SDL_Quit();
			exit(0);
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_d:
				player->Walk(&player->character, 5);
				player->character.att.flip = 0;
				break;
			case SDLK_a:
				player->Walk(&player->character, -5);
				player->character.att.flip = 1;
				break;
			case SDLK_f:
				if (player->character.att.onGround) {
					player->character.att.attack = 1;
				}
				break;
			case SDLK_SPACE:
 				if (player->character.att.onGround){
					player->Jump(&player->character, -15);
					player->character.att.onGround = 0;
				}
				break;
			}
			break;

		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
			case SDLK_d:
				player->Walk(&player->character, 0);
				break;
			case SDLK_a:
				player->Walk(&player->character, 0);
				break;
			case SDLK_SPACE:
				if (player->character.att.jumpStr < -5) {
					player->Jump(&player->character, -5);
				}
				break;
			}
			break;
		}
	}
}