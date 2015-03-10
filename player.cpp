#include "player.h"

//Initialize texture
bool Player::load(SDL_Renderer* pRenderer)
{
	//Load the hand
	player_image = IMG_Load(spritesheet_path.c_str());
	player_texture = SDL_CreateTextureFromSurface(pRenderer, player_image);
	if(player_texture <= 0)
	{
		return false;
	}
	SDL_FreeSurface(player_image);

	//Load the text
	txt_font = TTF_OpenFont(font_path.c_str(), 24);
	if(!txt_font)
	{
		return false;						
	}
	
	SDL_Color txt_color = {255, 255, 255};
	SDL_Surface* txt_image = TTF_RenderText_Blended(txt_font, player_name.c_str(), txt_color);
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
	txt_pos.y = 10;
	
	return true;
}

//Render the texture through given renderer
void Player::render(SDL_Renderer* pRenderer, bool pDisplayHand)
{
	//Render the stress indicator
	SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderCopy(pRenderer, txt_texture, &txt_rect, &txt_pos);
	SDL_RenderDrawRect(pRenderer, &stress_border_rect);
	
	SDL_SetRenderDrawColor(pRenderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
	stress_rect.w = stresspoints*10;
	SDL_RenderFillRect(pRenderer, &stress_rect);

	//Render the hand
	if(pDisplayHand)
	{
		SDL_RenderCopy(pRenderer, player_texture, &sprite_rect, &player_rect);
	}
}

//Increase stress (setter)
void Player::stress_up()
{
	stresspoints += 2;
	if(stresspoints >= 10)
	{
		is_overstress = true;
	}
}

//Decrease stress (setter)
void Player::stress_down()
{
	if(stresspoints >=1)
	{
		stresspoints -= 1;
	}
}

void Player::dispose()
{
	SDL_DestroyTexture(player_texture);
	SDL_DestroyTexture(txt_texture);
}
