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
				SDL_SetRenderDrawColor(gRenderer, 0xFF,
						0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				SDL_RenderCopy(gRenderer, background, 0, 0);

				figures.render(gRenderer, 35, 15,
						&whiteChessFigures[0]);
				/*figures.render(gRenderer,
				 SCREEN_WIDTH - whiteChessFigures[1].w, 0,
				 &whiteChessFigures[1]);

				 figures.render(gRenderer,0,
				 SCREEN_HEIGHT - whiteChessFigures[2].h,
				 &whiteChessFigures[2]);
				 */

				for (int i = 0; i < 8; i++)
				{
					figures.render(gRenderer,
							50 + i * offset, 70,
							&whiteChessFigures[5]);
				}

				for (int i = 0; i < 8; i++)
				{
					figures.render(gRenderer,
							50 + i * offset, 70,
							&blackChessFigures[5]);
				}

				SDL_RenderPresent(gRenderer);
			}

		}
	}

	//close();
	return 0;
}
