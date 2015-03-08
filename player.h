#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <SDL2/SDL.h>

#ifdef __APPLE__
#include <SDL2_image/SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif

using namespace std;

class Player
{
	//Constant initialization
	static const int HAND_SCISSOR = 0*200;
	static const int HAND_ROCK = 1*200;
	static const int HAND_PAPER = 2*200;

	string spritesheet_path;

	SDL_Surface* player_image;	
	SDL_Texture* player_texture;
	
	SDL_Rect sprite_rect;
	SDL_Rect player_rect;

	public:
		//Constructors
		Player(string pSpritePath="")
		{
			spritesheet_path = pSpritePath;
			
			sprite_rect.w = 200;
			sprite_rect.h = 200;
			sprite_rect.x = HAND_SCISSOR;
			sprite_rect.y = 0;

			player_rect.w = 200;
			player_rect.h = 200;
			player_rect.x = 20;
			player_rect.y = 270;
		}

		//Initialize texture
		bool load(SDL_Renderer* pRenderer);

		//Render the texture through given renderer
		void render(SDL_Renderer* pRenderer);
};
#endif
