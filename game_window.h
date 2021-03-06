#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <SDL2/SDL.h>
#include "menu.h"

#include "game.h"

class GameWindow
{
	private:
 		bool is_running;   
		bool is_playing = false;

		SDL_Window* display;
		SDL_Renderer* renderer;
		SDL_Surface* icon;
		
		Menu menu;
		Game game;

	public:
		//Constructor
		GameWindow()
		{
			display = nullptr;
			renderer = nullptr;
		}

		//Initialize the game display
		bool init();

		//Display the game
		bool run();

		//Catch game events
		void on_event(SDL_Event* event);
};

#endif
