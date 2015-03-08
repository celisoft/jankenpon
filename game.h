#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#ifdef __APPLE__
#include <SDL2_image/SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif

#include "player.h"
#include "box.h"

using namespace std;

class Game
{
	private:
		//const int HAND_SCISSOR = 0*200;
		//const int HAND_ROCK = 1*200;
		//const int HAND_PAPER = 2*200;

		string base_path;
		string asset_path;

		string intro_txt = "Hello, you must be the new jankenponer ! What's your name ?";

		SDL_Surface* bg_image;
		SDL_Texture* bg_texture;
		SDL_Rect bg_rect;
		
		//SDL_Texture* hand_texture;
		//SDL_Rect hsprite_rect;
		//SDL_Rect hand_rect;

		Player player;
		Box box;

		//initialize paths
		void init_paths();

	public:
		//Constructor
		Game()
		{
			init_paths();

			bg_rect.w = 800;
			bg_rect.h = 600;
			bg_rect.x = 0;
			bg_rect.y = 0;

			//hsprite_rect.w = 200;
			//hsprite_rect.h = 200;
			//hsprite_rect.x = 0;
			//hsprite_rect.y = 0;

			//hand_rect.w = 200;
			//hand_rect.h = 200;
			//hand_rect.x = 20;
			//hand_rect.y = 270;
		}

		//Load
		bool load(SDL_Renderer* pRenderer);

		//Display
		bool display(SDL_Renderer* pRenderer);

		//Event dispatcher
		void on_event(SDL_Event* pEvent);	
};

#endif
