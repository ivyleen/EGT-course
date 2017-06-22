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
const int SCREEN_HEIGHT = 640;
const int offset = 80;
const int rectOfBoardH = 80;
const int rectOfBoardW = 80;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Texture* background = NULL;
ChessFigures figures;
SDL_Rect whiteChessFigures[6];
SDL_Rect blackChessFigures[6];

int chessBoard[8][8] = { { 0, 1, 0, 1, 0, 1, 0, 1 }, { 1, 0,
		1, 0, 1, 0, 1, 0 }, { 0, 1, 0, 1, 0, 1, 0, 1 }, { 1,
		0, 1, 0, 1, 0, 1, 0 }, { 0, 1, 0, 1, 0, 1, 0, 1 }, {
		1, 0, 1, 0, 1, 0, 1, 0 },
		{ 0, 1, 0, 1, 0, 1, 0, 1 },
		{ 1, 0, 1, 0, 1, 0, 1, 0 } };

bool init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		cout << "There is a problem with SDL_Init" << endl;
		success = false;
	} else
	{
		gWindow = SDL_CreateWindow("Chess by Ivy",
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

void drawChessFigures()
{
	// drawing bishop, knight and rook
	int j = 0;
	for (int i = 4; i > 1; i--)
	{
		// left
		figures.render(gRenderer, (j * rectOfBoardW),
				SCREEN_HEIGHT - rectOfBoardH,
				&whiteChessFigures[i]);
		figures.render(gRenderer, (j * rectOfBoardW), 0,
				&blackChessFigures[i]);

		//right
		figures.render(gRenderer,
				((8 - j - 1) * rectOfBoardW),
				SCREEN_HEIGHT - rectOfBoardH,
				&whiteChessFigures[i]);
		figures.render(gRenderer,
				((8 - j - 1) * rectOfBoardW), 0,
				&blackChessFigures[i]);
		j++;
	}

	// drawing queen and king
	int help = 2;
	for (int i = 2; i > -1; i--)
	{
		figures.render(gRenderer, (help * rectOfBoardW),
				SCREEN_HEIGHT - rectOfBoardH,
				&whiteChessFigures[i]);
		figures.render(gRenderer, (help * rectOfBoardW), 0,
				&blackChessFigures[i]);

		help++;
	}

	// drawing pawns
	for (int i = 0; i < 8; i++)
	{
		figures.render(gRenderer, (i + (i * offset)),
				(6 * offset), &whiteChessFigures[5]);

		figures.render(gRenderer, (i + (i * offset)),
				offset, &blackChessFigures[5]);
	}
}

void drawChessBord()
{
	SDL_Rect q;
	q.w = rectOfBoardW;
	q.h = rectOfBoardH;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (chessBoard[i][j] == 0)
			{
				SDL_SetRenderDrawColor(gRenderer, 255, 255,
						255, 0);
			}
			if (chessBoard[i][j] == 1)
			{
				SDL_SetRenderDrawColor(gRenderer, 230, 180,
						100, 0);
			}
			q.x = 80 * j;
			q.y = 80 * i;
			SDL_RenderFillRect(gRenderer, &q);
		}
	}
}

void setWhiteChessFigures()
{
	int stepP = 333;
	for (int i = 0; i < 6; i++)
	{
		whiteChessFigures[i].x = i * stepP;
		whiteChessFigures[i].y = 0;
		whiteChessFigures[i].w = 350;
		whiteChessFigures[i].h = 350;
	}

}

void setBlackChessFigures()
{
	int stepP = 333;
	for (int i = 0; i < 6; i++)
	{
		blackChessFigures[i].x = i * stepP;
		blackChessFigures[i].y = 350;
		blackChessFigures[i].w = 350;
		blackChessFigures[i].h = 350;
	}
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
