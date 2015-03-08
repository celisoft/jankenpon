#include "box.h"

//Load the box
void Box::load(SDL_Renderer* pRenderer)
{
	is_load = true;
	
	txt_font = TTF_OpenFont(font_path.c_str(), 24);
	if(!txt_font)
	{
		is_load = false;
	}
	
	SDL_Surface* txt_image = TTF_RenderText_Blended_Wrapped(txt_font, txt.c_str(), txt_color, border_int_rect.w - 5);
	txt_texture = SDL_CreateTextureFromSurface(pRenderer, txt_image);
       	if(txt_texture <= 0)
	{
		is_load = false;
	}
	SDL_FreeSurface(txt_image);

	int lWidth{0};
	int lHeight{0};
	SDL_QueryTexture(txt_texture, nullptr, nullptr, &lWidth, &lHeight);

	txt_rect.w = lWidth;
	txt_rect.h = lHeight;
	txt_rect.x = 0;
	txt_rect.y = 0;

	txt_pos.w = lWidth;
	txt_pos.h = lHeight;
	txt_pos.x = border_int_rect.x + 10;
	txt_pos.y = border_int_rect.y + 10;
}	

//Update the text
void Box::update_text(SDL_Renderer* pRenderer, string pText)
{
	if(txt.compare(pText) != 0)
	{
		txt = pText;	
		SDL_Surface* txt_image = TTF_RenderText_Blended_Wrapped(txt_font, txt.c_str(), txt_color, border_int_rect.w - 5);
		txt_texture = SDL_CreateTextureFromSurface(pRenderer, txt_image);
       		if(txt_texture <= 0)
		{
			is_load = false;
		}
		SDL_FreeSurface(txt_image);

		int lWidth{0};
		int lHeight{0};
		SDL_QueryTexture(txt_texture, nullptr, nullptr, &lWidth, &lHeight);

		txt_rect.w = lWidth;
		txt_rect.h = lHeight;

		txt_pos.w = lWidth;
		txt_pos.h = lHeight;
	}
}

void Box::dispose()
{
	TTF_CloseFont(txt_font);
	SDL_DestroyTexture(txt_texture);
}

//Display the current level
void Box::display(SDL_Renderer* pRenderer)
{
	if(!is_load)
	{
		load(pRenderer);
	}

	SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawRect(pRenderer, &border_ext_rect);
	SDL_RenderDrawRect(pRenderer, &border_int_rect);

	SDL_RenderCopy(pRenderer, txt_texture, &txt_rect, &txt_pos);
}

