#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <SDL2/SDL.h>

#ifdef __APPLE__
#include <SDL2_image/SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif

using namespace std;

class Enemy
{
	//Constant initialization
	static const int HAND_SCISSOR = 0*200;
	static const int HAND_ROCK = 1*200;
	static const int HAND_PAPER = 2*200;

	string spritesheet_path;

	SDL_Surface* enemy_image;	
	SDL_Texture* enemy_texture;
	
	SDL_Rect sprite_rect;
	SDL_Rect enemy_rect;

	public:
		//Constructors
		Enemy(string pSpritePath="")
		{
			spritesheet_path = pSpritePath;
			
			sprite_rect.w = 200;
			sprite_rect.h = 200;
			sprite_rect.x = HAND_ROCK;
			sprite_rect.y = 0;

			enemy_rect.w = 200;
			enemy_rect.h = 200;
			enemy_rect.x = 590;
			enemy_rect.y = 0;
		}

		//Initialize texture
		bool load(SDL_Renderer* pRenderer);

		//Render the texture through given renderer
		void render(SDL_Renderer* pRenderer);
};
#endif
