#include "enemy.h"

//Initialize texture
bool Enemy::load(SDL_Renderer* pRenderer)
{
	enemy_image = IMG_Load(spritesheet_path.c_str());
	enemy_texture = SDL_CreateTextureFromSurface(pRenderer, enemy_image);
	if(enemy_texture <= 0)
	{
		return false;
	}
	SDL_FreeSurface(enemy_image);
	return true;
}

//Render the texture through given renderer
void Enemy::render(SDL_Renderer* pRenderer)
{
	SDL_RenderCopyEx(pRenderer, enemy_texture, &sprite_rect, &enemy_rect, 180, nullptr, SDL_FLIP_NONE);
}

