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
		static const int SCISSORS = 0;
		static const int ROCK = 1;
		static const int PAPER = 2;

		static const int PHASE_INTRO_0 = 0;
		static const int PHASE_INTRO_1 = 1;
		static const int PHASE_INTRO_2 = 2;
		static const int PHASE_INTRO_3 = 3;
		static const int PHASE_GAME_CHOICE = 4;
		static const int PHASE_GAME_RESULT = 5;
		static const int PHASE_GAME_END = 6;

		string base_path;
		string asset_path;

		string intro_txt_0 = "Hello, you must be the new jankenponer ! Press spacebar and let me explain the game rules.";
		string intro_txt_1 = "You will have 3 choices as the computer (CPU):\nrock, paper and scissors.\n\nChoices are made through R, P and S keys.";
		string intro_txt_2 = "The rules are quite simple:\n\nRock breaks scissors, scissors cut the paper and the paper covers the rock.";
		string intro_txt_3 = "At the top left corner of the screen, a stress level area is now shown. When you will loose a round, your stress will increase. If the CPU stress bar is full, you win !";
		string choice_txt = "What is your choice ?\n(R)ock - (P)aper - (S)cissors";

		SDL_Surface* bg_image;
		SDL_Texture* bg_texture;
		SDL_Texture* chen_texture;
		SDL_Rect bg_rect;
		SDL_Rect chen_rect;
		
		Player player;
		Enemy enemy;
		Box box;

		int current_phase = 0;
		bool is_result_display = false;
		string result;

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
