/*
 * Global.h
 *
 *  Created on: 16.06.2017 �.
 *      Author: IVY
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Texture.h"
#include <stdio.h>
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
Texture objectTexture;
TTF_Font *gFont = NULL;
Texture gTextTexture;

bool init()
{

	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init( SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n",
				SDL_GetError());
		success = false;
	} else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY,
				"1"))
		{
			printf(
					"Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("Text Font Testing",
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
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1,
					SDL_RENDERER_ACCELERATED
							| SDL_RENDERER_PRESENTVSYNC);
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
							"SDL_image could not initialize! SDL_image Error: %s\n",
							IMG_GetError());
					success = false;
				}

				//Initialize SDL_ttf
				if (TTF_Init() == -1)
				{
					printf(
							"SDL_ttf could not initialize! SDL_ttf Error: %s\n",
							TTF_GetError());
					success = false;
				}
			}
		}
	}
	return success;
}

bool loadMedia()
{
	bool success = true;

	//Load dot texture
	if (!objectTexture.loadFromFile(gRenderer, "foo.png"))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}

	return success;
}

void close()
{

	objectTexture.free();

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}

#endif /* GLOBAL_H_ */
