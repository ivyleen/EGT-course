//============================================================================
// Name        : SDL_Chess.cpp
// Author      : Ivy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Globals.h"

int main(int argc, char* args[])
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

	//close();
	return 0;
}
