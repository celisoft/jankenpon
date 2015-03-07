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


using namespace std;

class Game
{
	private:
		string base_path;

		SDL_Texture* hand_texture;

		//initialize paths
		void init_paths();

	public:
		//Constructor
		Game()
		{
			init_paths();
		}

		//Load
		bool load(SDL_Renderer* pRenderer);

		//Display
		bool display(SDL_Renderer* pRenderer);

		//Event dispatcher
		void on_event(SDL_Event* pEvent);	
};

#endif
