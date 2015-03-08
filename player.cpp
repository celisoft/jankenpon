#include "player.h"

//Initialize texture
bool Player::load(SDL_Renderer* pRenderer)
{
	player_image = IMG_Load(spritesheet_path.c_str());
	player_texture = SDL_CreateTextureFromSurface(pRenderer, player_image);
	if(player_texture <= 0)
	{
		return false;
	}
	SDL_FreeSurface(player_image);
	return true;
}

//Render the texture through given renderer
void Player::render(SDL_Renderer* pRenderer)
{
	SDL_RenderCopy(pRenderer, player_texture, &sprite_rect, &player_rect);
}

