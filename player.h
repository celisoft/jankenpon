#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <SDL2/SDL.h>

#ifdef __APPLE__
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#else
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#endif

using namespace std;

class Player
{
	//Constant initialization
	static const int HAND_SCISSOR = 0*200;
	static const int HAND_ROCK = 1*200;
	static const int HAND_PAPER = 2*200;

	string spritesheet_path;
	string player_name = "Player";
	string font_path;
	TTF_Font* txt_font;

	SDL_Surface* player_image;	
	SDL_Texture* player_texture;
	SDL_Texture* txt_texture;
		
	SDL_Rect sprite_rect;
	SDL_Rect player_rect;
	SDL_Rect stress_border_rect;
	SDL_Rect stress_rect;
	SDL_Rect txt_rect;
	SDL_Rect txt_pos;

	bool is_overstress = false;
	int stresspoints = 0;

	public:
		//Constructors
		Player(string pSpritePath="", string pFontPath="")
		{
			spritesheet_path = pSpritePath;
			font_path = pFontPath;

			sprite_rect.w = 200;
			sprite_rect.h = 200;
			sprite_rect.x = HAND_SCISSOR;
			sprite_rect.y = 0;

			player_rect.w = 200;
			player_rect.h = 200;
			player_rect.x = 20;
			player_rect.y = 270;

			stress_border_rect.w = 102;
			stress_border_rect.h = 10;
			stress_border_rect.x = 110;
			stress_border_rect.y = 20;

			stress_rect.w = 0;
			stress_rect.h = stress_border_rect.h-2;
			stress_rect.x = stress_border_rect.x+1;
			stress_rect.y = stress_border_rect.y+1;
		}

		//Initialize texture
		bool load(SDL_Renderer* pRenderer);

		//Set the hand sprite
		void set_hand(int pHand){sprite_rect.x = pHand*200;}

		//Get hand
		int get_hand(){return sprite_rect.x/200;}

		//Getter for life_point
		int get_stresspoints(){return stresspoints;}

		//Return true if the player is too stressed
		bool is_overstressed(){return is_overstress;}

		//Increase stress
		void stress_up();

		//Decrease stress
		void stress_down();

		//Render the texture through given renderer
		void render(SDL_Renderer* pRenderer, bool pDisplayHand);

		//Cleanup textures
		void dispose();
};
#endif
