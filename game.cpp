#include "game.h"

//Init paths
void Game::init_paths()
{
	char* path = SDL_GetBasePath();
	if(path == nullptr)
	{
		base_path = SDL_strdup("./");
	}
	else
	{
		base_path = SDL_strdup(path);
		SDL_free(path);
	}
}

bool Game::load(SDL_Renderer* pRenderer)
{
	SDL_Surface* lHandSurface = IMG_Load((base_path + "assets/hand_sheet.png").c_str());
	SDL_FreeSurface(lHandSurface);

	return true;	
}

//Display the current level
bool Game::display(SDL_Renderer* pRenderer)
{

	return true;
}

//Event dispatcher
void Game::on_event(SDL_Event* pEvent)
{

}
