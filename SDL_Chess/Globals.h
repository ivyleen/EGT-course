/*
 * Globals.h
 *
 *  Created on: 21.06.2017 ã.
 *      Author: IVY
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "ChessFigures.h"
using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int offset = 74;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Texture* background = NULL;
ChessFigures figures;
SDL_Rect whiteChessFigures[6];
SDL_Rect blackChessFigures[6];

bool init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		cout << "There is a problem with SDL_Init" << endl;
		success = false;
	} else
	{
		gWindow = SDL_CreateWindow("Chess Testing by Ivy",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
				SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			cout
					<< "Window could not be created! SDL Error: "
					<< SDL_GetError() << endl;
			success = false;
		} else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1,
					SDL_RENDERER_ACCELERATED
							| SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				cout
						<< "Renderer could not be created! SDL Error: "
						<< SDL_GetError() << endl;
				success = false;
			} else
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF,
						0xFF, 0xFF, 0xFF);
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					cout
							<< "SDL_image could not initialize! SDL_image Error: "
							<< IMG_GetError() << endl;
					success = false;
				}

			}
		}
	}

	return success;
}

void setWhiteChessFigures()
{
	whiteChessFigures[0].x = 30;
	whiteChessFigures[0].y = 30;
	whiteChessFigures[0].w = 300;
	whiteChessFigures[0].h = 300;

	whiteChessFigures[1].x = 350;
	whiteChessFigures[1].y = 30;
	whiteChessFigures[1].w = 650;
	whiteChessFigures[1].h = 300;

	whiteChessFigures[2].x = 800;
	whiteChessFigures[2].y = 30;
	whiteChessFigures[2].w = 970;
	whiteChessFigures[2].h = 300;

	whiteChessFigures[3].x = 1130;
	whiteChessFigures[3].y = 30;
	whiteChessFigures[3].w = 1290;
	whiteChessFigures[3].h = 300;

	whiteChessFigures[4].x = 1390;
	whiteChessFigures[4].y = 30;
	whiteChessFigures[4].w = 1610;
	whiteChessFigures[4].h = 300;

	whiteChessFigures[5].x = 1730;
	whiteChessFigures[5].y = 30;
	whiteChessFigures[5].w = 300;
	whiteChessFigures[5].h = 300;

}

void setBlackChessFigures()
{
	blackChessFigures[0].x = 30;
	blackChessFigures[0].y = 350;
	blackChessFigures[0].h = 300;
	blackChessFigures[0].w = 670;

	blackChessFigures[1].x = 350;
	blackChessFigures[1].y = 350;
	blackChessFigures[1].w = 650;
	blackChessFigures[1].h = 670;

	blackChessFigures[2].x = 700;
	blackChessFigures[2].y = 350;
	blackChessFigures[2].w = 970;
	blackChessFigures[2].h = 670;

	blackChessFigures[3].x = 1130;
	blackChessFigures[3].y = 350;
	blackChessFigures[3].w = 1290;
	blackChessFigures[3].h = 670;

	blackChessFigures[4].x = 1390;
	blackChessFigures[4].y = 350;
	blackChessFigures[4].w = 1610;
	blackChessFigures[4].h = 670;

	blackChessFigures[5].x = 1730;
	blackChessFigures[5].y = 350;
	blackChessFigures[5].w = 1930;
	blackChessFigures[5].h = 670;

}

bool loadMedia()
{
	bool success = true;

	SDL_Surface * loadedSurface = IMG_Load("chess.jpg");
	if (loadedSurface == NULL)
	{
		cout << "Loaded surface is NULL" << endl;
		success = false;
	} else
	{
		background = SDL_CreateTextureFromSurface(gRenderer,
				loadedSurface);
		if (background == NULL)
		{
			cout << "Background is NULL" << endl;
			success = false;
		}
	}

	if (!figures.loadFromFile(gRenderer,
			"Chess_Pieces_Sprite.png"))
	{
		cout << "Figures are not loaded!" << endl;
	} else
	{
		setWhiteChessFigures();
		setBlackChessFigures();

	}
	SDL_FreeSurface(loadedSurface);
	return success;
}

void close()
{
	figures.free();

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);

	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

#endif /* GLOBALS_H_ */
