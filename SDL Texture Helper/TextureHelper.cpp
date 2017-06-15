//============================================================================
// Name        : TextureHelper.cpp
// Author      : Ivy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Texture.h"
#include "Global.h"
using namespace std;


Texture gSpriteSheetTexture;

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if (!true)
	{
		printf("Failed to load texture!\n");
		success = false;
	} else
	{

	}

	return success;
}

int main(int argc, char* args[])
{

	Texture gSpriteSheetTexture;
	if (!init())
	{
		printf("Failed to initialize!\n");
	} else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		} else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}
				SDL_SetRenderDrawColor(gRenderer, 20,
						0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);


				//Update screen
				SDL_RenderPresent(gRenderer);
			}
		}
	}

	//Free resources and close SDL
	closeGlobal();

	return 0;
}
