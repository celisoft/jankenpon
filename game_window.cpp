#include "game_window.h"

#ifdef __APPLE__
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#else
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#endif

#include <iostream>

//Initialize an 1024x768 SDL window
bool GameWindow::init()
{
	//Try to initailize all SDL component and check if it works
	if(SDL_Init(SDL_INIT_TIMER|SDL_INIT_VIDEO|SDL_INIT_EVENTS) < 0)
	{
		return false;
	}

	//Create a window and check if it works
	display = SDL_CreateWindow("Jankenpon - Celisoft mini-game",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		       	800, 600, SDL_WINDOW_OPENGL);
	
	if(display == nullptr)
	{
		return false;
	}

	//Create the renderer
	renderer = SDL_CreateRenderer(display, -1, 0);
	if(renderer == nullptr)
	{
		return false;
	}

	if(TTF_Init() < 0)
	{
		return false;
	}
	
	return true;
}


bool GameWindow::run()
{
	is_running = init();
	if(is_running == false)
	{
		//Init phase fails
		return false;
	}
		
	SDL_Event lEvent;

	if(!menu.load(renderer))
	{
		return false;
	}

	if(!game.load(renderer))
	{
		return false;
	}

	while(is_running)
	{
		SDL_RenderClear(renderer);
	
		if(!is_playing)
		{
			menu.display(renderer);
		}
		else
		{
			is_running = game.display(renderer);		
		}

		if(SDL_PollEvent(&lEvent))
		{
			on_event(&lEvent);
			if(!is_playing)
			{
				is_playing = menu.check_event(&lEvent);
			}
			else
			{
				game.on_event(&lEvent);
			}
		}

		SDL_RenderPresent(renderer);
	
		//Slow down cycles
		SDL_Delay(16);
	}

	menu.dispose();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(display);
	TTF_Quit();
	SDL_Quit();
	return true;
}

//Handle SDL events 
void GameWindow::on_event(SDL_Event* pEvent)
{
	switch(pEvent->type)
	{
		case SDL_QUIT:
			is_running = false;
			break;
	}
}	

