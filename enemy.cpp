#include "enemy.h"

#include <random>
#include <chrono>

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

	//Load the text
	txt_font = TTF_OpenFont(font_path.c_str(), 24);
	if(!txt_font)
	{
		return false;						
	}
	
	SDL_Color txt_color = {255, 255, 255};
	SDL_Surface* txt_image = TTF_RenderText_Blended(txt_font, enemy_name.c_str(), txt_color);
	txt_texture = SDL_CreateTextureFromSurface(pRenderer, txt_image);
	if(txt_texture <= 0)
	{
		return false;
	}
	SDL_FreeSurface(txt_image);
	TTF_CloseFont(txt_font);

	int lWidth{0};
	int lHeight{0};
	SDL_QueryTexture(txt_texture, nullptr, nullptr, &lWidth, &lHeight);

	txt_rect.w = lWidth;
	txt_rect.h = lHeight;
	txt_rect.x = 0;
	txt_rect.y = 0;

	txt_pos.w = lWidth;
	txt_pos.h = lHeight;
	txt_pos.x = 10;
	txt_pos.y = 40;

	return true;
}

//Render the texture through given renderer
void Enemy::render(SDL_Renderer* pRenderer, bool pDisplayHand)
{
	//Render the stress indicator
	SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderCopy(pRenderer, txt_texture, &txt_rect, &txt_pos);
	SDL_RenderDrawRect(pRenderer, &stress_border_rect);
	
	SDL_SetRenderDrawColor(pRenderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
	stress_rect.w = stresspoints*10;
	SDL_RenderFillRect(pRenderer, &stress_rect);

	if(pDisplayHand)
	{
		SDL_RenderCopyEx(pRenderer, enemy_texture, &sprite_rect, &enemy_rect, 180, nullptr, SDL_FLIP_NONE);
	}
}

//Make random choice
int Enemy::make_random_choice()
{
	unsigned lSeed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine rand_generator(lSeed);
	uniform_int_distribution<int> distribution(0, 2);
	return distribution(rand_generator)*200;
}

//Increase stress (setter)
void Enemy::stress_up()
{
	stresspoints += 2;
	if(stresspoints >= 10)
	{
		is_overstress = true;
	}
}

//Decrease stress (setter)
void Enemy::stress_down()
{
	if(stresspoints >=1)
	{
		stresspoints -= 1;
	}
}

void Enemy::dispose()
{
	SDL_DestroyTexture(enemy_texture);
	SDL_DestroyTexture(txt_texture);
}
