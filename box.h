#ifndef BOX_H
#define BOX_H

#include <string>
#include <iostream>

#include <SDL2/SDL.h>
#ifdef __APPLE__
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#else
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#endif

using namespace std;

class Box
{
	private:
		string font_path;

		SDL_Color txt_color = {255, 255, 255};
		TTF_Font* txt_font;	
		string txt;

		SDL_Rect border_ext_rect;
		SDL_Rect border_int_rect;
		SDL_Rect txt_rect;
		SDL_Rect txt_pos;

		SDL_Texture* txt_texture;

		bool is_load = false;

		//initialize paths
		void init_paths();

		//Load
		void load(SDL_Renderer* pRenderer);

	public:
		//Constructor
		Box(string pFontPath="", int pWidth=0, int pHeight=0, int pX=0, int pY=0, string pText="")
		{
			font_path = pFontPath;
			txt = pText;

			//Initialize the box border rect
			border_ext_rect.w = pWidth;
			border_ext_rect.h = pHeight;
			border_ext_rect.x = pX;
			border_ext_rect.y = pY;

			border_int_rect.w = pWidth-10;
			border_int_rect.h = pHeight-10;
			border_int_rect.x = pX+5;
			border_int_rect.y = pY+5;
		}

		//Update the box content
		void update_text(SDL_Renderer* pRenderer, string pText);

		//Display
		void display(SDL_Renderer* pRenderer);

		//Dispose box memory
		void dispose();
};

#endif
