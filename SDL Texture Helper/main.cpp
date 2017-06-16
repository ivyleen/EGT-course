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
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
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

				//Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0xFF,
						0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				//Render current frame
				gTextTexture.render(gRenderer,
						SCREEN_WIDTH/15,
						SCREEN_HEIGHT/30);

				//Update screen
				SDL_RenderPresent(gRenderer);
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}
