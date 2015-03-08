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
#include "enemy.h"
#include "box.h"

using namespace std;

class Game
{
	private:
		string base_path;
		string asset_path;

		string intro_txt = "Hello, you must be the new jankenponer ! What's your name ?";

		SDL_Surface* bg_image;
		SDL_Texture* bg_texture;
		SDL_Rect bg_rect;
		
		Player player;
		Enemy enemy;
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
		}

		//Load
		bool load(SDL_Renderer* pRenderer);

		//Display
		bool display(SDL_Renderer* pRenderer);

		//Event dispatcher
		void on_event(SDL_Event* pEvent);	
};

#endif
