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
	player = Player(asset_path + "hand_sheet.png");
	player.load(pRenderer);

	//Init enemy
	enemy = Enemy(asset_path + "hand_sheet.png");
	enemy.load(pRenderer);

	//TODO remove
	box = Box(asset_path + "fonts/FreeMono.ttf", 798, 128, 0, 471, intro_txt);

	return true;	
}

//Display the current level
bool Game::display(SDL_Renderer* pRenderer)
{
	SDL_RenderCopy(pRenderer, bg_texture, &bg_rect, &bg_rect);
	player.render(pRenderer);
	enemy.render(pRenderer);
	box.display(pRenderer);
	return true;
}

//Event dispatcher
void Game::on_event(SDL_Event* pEvent)
{

}
