//============================================================================
// Name        : 06.cpp
// Author      : Ivy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "Texture.h"
#include "Global.h"

int main(int argc, char* args[])
{
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

			bool quit = false;
			double degrees = 0;
			SDL_RendererFlip flipType = SDL_FLIP_NONE;
			SDL_Event e;

			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					} else if (e.type == SDL_KEYDOWN)
					{
						switch (e.key.keysym.sym)
						{
						case SDLK_a:
							degrees -= 60;
							break;

						case SDLK_d:
							degrees += 60;
							break;

						case SDLK_q:
							flipType = SDL_FLIP_HORIZONTAL;
							break;

						case SDLK_w:
							flipType = SDL_FLIP_NONE;
							break;

						case SDLK_e:
							flipType = SDL_FLIP_VERTICAL;
							break;
						}

					}

					SDL_SetRenderDrawColor(gRenderer, 0xFF,
							0xFF, 0xFF, 0xFF);
					SDL_RenderClear(gRenderer);

					SDL_Rect topLeftViewport;
					topLeftViewport.x = 0;
					topLeftViewport.y = 0;
					topLeftViewport.w =gTextTexture.getWidth();
					topLeftViewport.h = gTextTexture.getHeight();

					background.renderB(gRenderer, NULL,
							degrees, NULL, flipType);

					gTextTexture.renderB(gRenderer,
							&topLeftViewport,
							degrees,NULL, flipType);

					//Update screen
					SDL_RenderPresent(gRenderer);
				}
			}
		}
	}

	close();

	return 0;
}
