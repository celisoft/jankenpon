#include "game.h"

//Init paths
void Game::init_paths()
{
	char* path = SDL_GetBasePath();
	if(path == nullptr)
	{
		base_path = SDL_strdup("./");
		asset_path = base_path + "assets/";
	}
	else
	{
		base_path = SDL_strdup(path);
		asset_path = base_path + "assets/";
		SDL_free(path);
	}
}

bool Game::load(SDL_Renderer* pRenderer)
{
	//Loading BG
	bg_image = IMG_Load((asset_path + "background.png").c_str());
	bg_texture = SDL_CreateTextureFromSurface(pRenderer, bg_image);
	if(bg_texture <= 0)
	{
		return false;
	}
	SDL_FreeSurface(bg_image);

	//Init player
	player = Player(asset_path + "hand_sheet.png", asset_path + "fonts/FreeMono.ttf");
	player.load(pRenderer);

	//Init enemy
	enemy = Enemy(asset_path + "hand_sheet.png", asset_path + "fonts/FreeMono.ttf");
	enemy.load(pRenderer);

	//TODO remove
	box = Box(asset_path + "fonts/FreeMono.ttf", 798, 128, 0, 471, intro_txt_0);

	return true;	
}

//Display the current level
bool Game::display(SDL_Renderer* pRenderer)
{
	SDL_RenderCopy(pRenderer, bg_texture, &bg_rect, &bg_rect);

	switch(current_phase)
	{
		case PHASE_INTRO_0:
			box.display(pRenderer);
			break;
		case PHASE_INTRO_1:
			box.update_text(pRenderer, intro_txt_1);
			box.display(pRenderer);
			break;
		case PHASE_INTRO_2:
			box.update_text(pRenderer, intro_txt_2);
			box.display(pRenderer);
			break;
		case PHASE_GAME_CHOICE:
			box.update_text(pRenderer, choice_txt);
			box.display(pRenderer);
			break;
		case PHASE_GAME_RESULT:
			player.render(pRenderer);
			enemy.render(pRenderer);
			break;
	}

	return true;
}

//Event dispatcher
void Game::on_event(SDL_Event* pEvent)
{
	if(current_phase != PHASE_GAME_CHOICE)
	{
		if(pEvent->type == SDL_KEYDOWN)
		{
			if(pEvent->key.keysym.sym == SDLK_SPACE)
			{
				current_phase++;
			}
		}	
	}
	else
	{
		
	}
	
}
