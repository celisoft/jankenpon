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

	SDL_Surface* chen_image = IMG_Load((asset_path + "chen.png").c_str());
	chen_texture = SDL_CreateTextureFromSurface(pRenderer, chen_image);
	if(chen_texture <=0)
	{
		return false;
	}
	SDL_FreeSurface(chen_image);
	chen_rect.w = 373;
	chen_rect.h = 540;
	chen_rect.x = 200;
	chen_rect.y = 0;

	//Init player
	player = Player(asset_path + "hand_sheet.png", asset_path + "fonts/FreeMono.ttf");
	player.load(pRenderer);

	//Init enemy
	enemy = Enemy(asset_path + "hand_sheet.png", asset_path + "fonts/FreeMono.ttf");
	enemy.load(pRenderer);

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
			SDL_RenderCopy(pRenderer, chen_texture, nullptr, &chen_rect);

			box.display(pRenderer);
			break;
		case PHASE_INTRO_1:
			SDL_RenderCopy(pRenderer, chen_texture, nullptr, &chen_rect);

			box.update_text(pRenderer, intro_txt_1);
			box.display(pRenderer);
			break;
		case PHASE_INTRO_2:
			SDL_RenderCopy(pRenderer, chen_texture, nullptr, &chen_rect);

			box.update_text(pRenderer, intro_txt_2);
			box.display(pRenderer);
			break;
		case PHASE_INTRO_3:
			SDL_RenderCopy(pRenderer, chen_texture, nullptr, &chen_rect);
			player.render(pRenderer, false);
			enemy.render(pRenderer, false);

			box.update_text(pRenderer, intro_txt_3);
			box.display(pRenderer);
			break;

		case PHASE_GAME_CHOICE:
			player.render(pRenderer, false);
			enemy.render(pRenderer, false);

			is_result_display = false;
			
			enemy.set_hand();
			
			box.update_text(pRenderer, choice_txt);
			box.display(pRenderer);
			break;
		case PHASE_GAME_RESULT:
			player.render(pRenderer, true);
			enemy.render(pRenderer, true);
			
			if(!is_result_display)
			{
				switch(player.get_hand())
				{
					case ROCK:
						switch(enemy.get_hand())
						{
							case ROCK:
								player.stress_down();
								enemy.stress_down();
								result = "You have made the same choice !";
								break;
							case PAPER:
								player.stress_up();
								result = "The paper covers your rock !";
								break;
							case SCISSORS:
								enemy.stress_up();
								result = "Your rock breaks the CPU scissors !";
								break;
						}
						break;
					case PAPER:
						switch(enemy.get_hand())
						{
							case ROCK:
								enemy.stress_up();
								result = "The paper covers the CPU rock !";
								break;
							case PAPER:
								player.stress_down();
								enemy.stress_down();
								result = "You have made the same choice !";
							break;
							case SCISSORS:
								player.stress_up();
								result = "Scissors cut your paper.";
								break;
						}
						break;
					case SCISSORS:
						switch(enemy.get_hand())
						{
							case ROCK:
								player.stress_up();
								result = "The rock breaks your scissors";
								break;
							case PAPER:
								enemy.stress_up();
								result = "Scissors cut the CPU paper.";
								break;
							case SCISSORS:
								player.stress_down();
								enemy.stress_down();
								result = "You have made the same choice !";
								break;
						}
						break;
				}

				if(player.is_overstressed())
				{
					result = "You are too stressed for playing, you loose !";
				}
				else
				{
					if(enemy.is_overstressed())
					{
						result = "Well done !! The CPU is too stressed to continue !";
					}
				}
				box.update_text(pRenderer, result);
				is_result_display = true;
			}
			box.display(pRenderer);

			break;
		default:
			player.dispose();
			enemy.dispose();
			box.dispose();
			return false;
	}

	return true;
}

//Event dispatcher
void Game::on_event(SDL_Event* pEvent)
{
	if(pEvent->type == SDL_KEYDOWN)
	{
		if(current_phase != PHASE_GAME_CHOICE)
		{
			if(current_phase == PHASE_GAME_RESULT)
			{
				if(player.is_overstressed())
				{
					current_phase = PHASE_GAME_END;
				}
				else
				{
					if(enemy.is_overstressed())
					{
						current_phase = PHASE_GAME_END;
					}
					else
					{
						current_phase = PHASE_GAME_CHOICE;
					}
				}
			}
			else
			{
				if(pEvent->key.keysym.sym == SDLK_SPACE)
				{
					current_phase++;
				}
			}
		}
		else
		{
			switch(pEvent->key.keysym.sym)
			{
				case SDLK_r:
					player.set_hand(ROCK);
					current_phase = PHASE_GAME_RESULT; 
					break;
				case SDLK_p:
					player.set_hand(PAPER);
					current_phase = PHASE_GAME_RESULT;
				       	break;
				case SDLK_s:
					player.set_hand(SCISSORS);
					current_phase = PHASE_GAME_RESULT;
					break;
			}
		}	
	}
	
}
