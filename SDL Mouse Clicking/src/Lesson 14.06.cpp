//============================================================================
// Name        : 06.cpp
// Author      : Ivy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

bool init();
bool loadMedia();
void close();
SDL_Surface* loadSurface(std::string path);
SDL_Texture* loadTexture(std::string path,
		SDL_Renderer *renderTarget);

enum KeyPress
{
	k_default,
	k_up,
	k_down,
	k_left,
	k_right,
	k_strech,
	k_image,
	k_end
};

SDL_Window *window = NULL;
SDL_Surface *windowSurface = NULL;
SDL_Surface *pictures[k_end];
SDL_Surface *currentImage = NULL;
SDL_Surface *loadedSurface = NULL;
SDL_Surface *optimizedSurface = NULL;

int main(int argc, char *argv[])
{

	currentImage = pictures[k_default];
	bool isRunning = true;
	SDL_Event ev;
	if (!init())
	{
		cout << "Failed initialization." << endl;
	} else
	{
		if (!loadMedia())
		{
			cout << "Failed to load the media." << endl;
		} else
		{

			while (isRunning)
			{
				while (SDL_PollEvent(&ev) != 0)
				{
					if (ev.type == SDL_QUIT)
					{
						isRunning = false;
					} else
					{
						SDL_Rect stretchRect;
						stretchRect.x = 0;
						stretchRect.y = 0;
						stretchRect.w = 0;
						stretchRect.h = 0;
						if (ev.type == SDL_MOUSEBUTTONDOWN)
						{
							if (ev.button.button
									== SDL_BUTTON_LEFT)
								currentImage =
										pictures[k_left];
							if (ev.button.button
									== SDL_BUTTON_RIGHT)
								currentImage =
										pictures[k_right];

							if (ev.button.clicks
									== SDL_PRESSED)
								currentImage =
										pictures[k_up];
						}
						switch (ev.key.keysym.sym)
						{

						case SDLK_DOWN:
							currentImage = pictures[k_down];
							stretchRect.w = 300;
							stretchRect.h = 300;
							stretchRect.y = 0;
							stretchRect.x = 0;
							SDL_BlitScaled(pictures[k_down],
							NULL, windowSurface,
									&stretchRect);
							break;

						case SDLK_LEFT:
							currentImage =
									pictures[k_strech];
							stretchRect.w = 0;
							stretchRect.h = 1290;
							stretchRect.x = 1880;
							stretchRect.y = 0;
							SDL_BlitScaled(
									pictures[k_strech],
									NULL, windowSurface,
									&stretchRect);
							break;

						case SDLK_RIGHT:
							currentImage =
									pictures[k_image];
							stretchRect.w = 0;
							stretchRect.h = 0;
							stretchRect.y = 720;
							stretchRect.x = 463;
							SDL_BlitScaled(
									pictures[k_image],
									NULL, windowSurface,
									&stretchRect);
							break;

						}
					}
				}

				SDL_BlitSurface(currentImage, NULL,
						windowSurface, NULL);
				SDL_UpdateWindowSurface(window);

			}
		}
	}

	return 0;
}

bool init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		cout << "SDL doesn't work! SDL_Error: "
				<< SDL_GetError() << endl;
		success = false;
	}

	else
	{
		window = SDL_CreateWindow("SDL Tutorial",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, 640, 480,
				SDL_WINDOW_SHOWN);

		if (window == NULL)
		{
			cout << "Window can't be created. SDL_Error: "
					<< SDL_GetError() << endl;
			success = false;
		}

		else
		{

			windowSurface = SDL_GetWindowSurface(window);
		}
	}

	return success;
}

bool loadMedia()
{
	bool success = true;
	pictures[k_default] = loadSurface("Untitled.png");
	if (pictures[k_default] == NULL)
	{
		cout
				<< "The default picture can't be loaded. Error: "
				<< IMG_GetError() << endl;
		success = false;
	}

	pictures[k_up] = loadSurface("checkers.png");
	if (pictures[k_up] == NULL)
	{
		cout << "The up picture can't be loaded. Error: "
				<< IMG_GetError() << endl;
		success = false;
	}

	pictures[k_down] = loadSurface(
			"LinearGradient_gradient1.png");
	if (pictures[k_down] == NULL)
	{
		cout << "The down picture can't be loaded. Error: "
				<< IMG_GetError() << endl;
		success = false;
	}

	pictures[k_left] = loadSurface(
			"wallpaper_ubtunu_500x.png");
	if (pictures[k_left] == NULL)
	{
		cout << "The left picture can't be loaded. Error: "
				<< IMG_GetError() << endl;
		success = false;
	}

	pictures[k_right] = loadSurface("056320.png");
	if (pictures[k_right] == NULL)
	{
		cout << "The right picture can't be loaded. Error: "
				<< IMG_GetError() << endl;
		success = false;
	}
	pictures[k_strech] = loadSurface(
			"Tse2009e_500mm_mid.png");
	if (pictures[k_strech] == NULL)
	{
		cout
				<< "The streched picture can't be loaded. Error: "
				<< IMG_GetError() << endl;
		success = false;
	}
	pictures[k_image] = loadSurface("fond.png");
	if (pictures[k_image] == NULL)
	{
		cout
				<< "The loaded picture can't be loaded. Error: "
				<< IMG_GetError() << endl;
		success = false;
	}

	return success;
}

void close()
{
	SDL_FreeSurface(windowSurface);
	windowSurface = NULL;

	SDL_FreeSurface(loadedSurface);
	loadedSurface = NULL;

	SDL_FreeSurface(optimizedSurface);
	optimizedSurface = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	for (int i = 0; i < k_end; i++)
	{
		SDL_FreeSurface(pictures[i]);
		pictures[i] = NULL;
	}

	SDL_Quit();
}

SDL_Surface* loadSurface(std::string path)
{
	loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		cout
				<< "The loaded picture can't be loaded. Error: "
				<< path.c_str() << SDL_GetError() << endl;

	} else
	{
		optimizedSurface = SDL_ConvertSurface(loadedSurface,
				windowSurface->format, 0);
		if (optimizedSurface == NULL)
		{
			cout
					<< "The optimized surface can't be loaded. Error: "
					<< path.c_str() << SDL_GetError()
					<< endl;
		}
	}
	return loadedSurface;

}

SDL_Texture* loadTexture(std::string path,
		SDL_Renderer *renderTarget)
{
	loadedTexture = NULL;
	loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		cout
				<< "The loaded picture can't be loaded. Error: "
				<< path.c_str() << SDL_GetError() << endl;

	} else
	{
		loadedTexture = SDL_CreateTextureFromSurface(
				renderTarget, loadedSurface);
		if (loadedTexture == NULL)
		{
			cout
					<< "The optimized surface can't be loaded. Error: "
					<< path.c_str() << SDL_GetError()
					<< endl;
		}
	}
	return loadedTexture;

}
