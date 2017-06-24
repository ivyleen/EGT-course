/*
 * Game.cpp
 *
 *  Created on: 24.06.2017 ã.
 *      Author: IVY
 */

#include "Game.h"

SDL_Window* Game::gWindow = NULL;
SDL_Renderer* Game::gRenderer = NULL;
SDL_Texture* Game::background = NULL;

Game::Game()
		: figures(), whiteChessFigures(), blackChessFigures()
{

}

Game::~Game()
{
// TODO Auto-generated destructor stub
}

bool Game::init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		cout << "There is a problem with SDL_Init" << endl;
		success = false;
	} else
	{
		// making window
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
			// making the renderer
			gRenderer = SDL_CreateRenderer(gWindow, -1,
					SDL_RENDERER_ACCELERATED
							| SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				cout
						<< "Renderer could not be created! SDL Error: "
						<< SDL_GetError() << endl;
				success = false;
			}
		}
	}

	return success;
}

void Game::setWhiteChessFigures()
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

void Game::setBlackChessFigures()
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

bool Game::loadMedia()
{
	bool success = true;

	SDL_Surface * loadedSurface = IMG_Load("chess.jpg");
	if (loadedSurface == NULL)
	{
		cout << "Loaded surface is NULL" << endl;
		success = false;
	} else
	{
		// making the background texture
		background = SDL_CreateTextureFromSurface(
				Game::gRenderer, loadedSurface);
		if (background == NULL)
		{
			cout << "Background is NULL" << endl;
			success = false;
		}
	}
// loading the picture for figures
	if (!figures.loadFromFile(Game::gRenderer,
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

void Game::close()
{

//Destroy window
	SDL_DestroyRenderer(Game::gRenderer);
	SDL_DestroyWindow(Game::gWindow);

	Game::gWindow = NULL;
	Game::gRenderer = NULL;

//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

void Game::start()
{

	if (!init())
	{
		cout << "Failed to initialize!" << endl;
	} else
	{
		//Load media
		if (!loadMedia())
		{
			cout << "Failed to load media!" << endl;
		} else
		{
			bool quit = false;
			bool drawn = false;
			SDL_Event e;

			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}

				if (!drawn)
				{
					SDL_RenderClear(gRenderer);
					drawChessBord();
					drawChessFigures();
					drawn = true;
				}
				// if you want to be with a background picture
				//	SDL_SetRenderDrawColor(gRenderer, 0xFF,
				//  0xFF, 0xFF, 0xFF);
				// SDL_RenderCopy(gRenderer, background, 0, 0);

				SDL_RenderPresent(gRenderer);
			}

		}
	}
}

void Game::drawChessFigures()
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
		// up
		figures.render(gRenderer, (help * rectOfBoardW), 0,
				&blackChessFigures[i]);

		// down
		figures.render(gRenderer, (help * rectOfBoardW),
				SCREEN_HEIGHT - rectOfBoardH,
				&whiteChessFigures[i]);
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

void Game::drawChessBord()
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
				//setting light color
				SDL_SetRenderDrawColor(gRenderer, 255, 255,
						255, 0);
			}
			if (chessBoard[i][j] == 1)
			{
				// setting dark color
				SDL_SetRenderDrawColor(gRenderer, 230, 180,
						100, 0);
			}

			q.x = rectOfBoardW * j;
			q.y = rectOfBoardH * i;
			SDL_RenderFillRect(gRenderer, &q);
		}
	}
	drawChessFigures();
}
