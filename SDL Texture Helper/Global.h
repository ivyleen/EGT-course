/*
 * Global.h
 *
 *  Created on: 15.06.2017 ã.
 *      Author: IVY
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(
	SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n",
				SDL_GetError());
		success = false;
	} else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,
				"1"))
		{
			printf(
					"Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("SDL Testing",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
				SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf(
					"Window could not be created! SDL Error: %s\n",
					SDL_GetError());
			success = false;
		} else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1,
					SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf(
						"Renderer could not be created! SDL Error: %s\n",
						SDL_GetError());
				success = false;
			} else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF,
						0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf(
							"SDL_image could not initialize! SDL_mage Error: %s\n",
							IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

void closeGlobal()
{
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
}


#endif /* GLOBAL_H_ */
