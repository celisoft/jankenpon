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
		static const int PHASE_INTRO_0 = 0;
		static const int PHASE_INTRO_1 = 1;
		static const int PHASE_INTRO_2 = 2;
		static const int PHASE_GAME_CHOICE = 3;
		static const int PHASE_GAME_RESULT = 4;
		static const int PHASE_GAME_END = 5;

		string base_path;
		string asset_path;

		string intro_txt_0 = "Hello, you must be the new jankenponer ! Press spacebar and let me explain the game rules.";
		string intro_txt_1 = "You will have 3 choices like the computer (CPU): rock, paper and scissors.";
		string intro_txt_2 = "The rock breaks scissors, scissors cut the paper and the paper covers the rock.";
		string choice_txt = "What is your choice ?\n(R)ock 2- (P)aper 3-(S)cissors";

		SDL_Surface* bg_image;
		SDL_Texture* bg_texture;
		SDL_Rect bg_rect;
		
		Player player;
		Enemy enemy;
		Box box;

		int current_phase = 0;

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
