//============================================================================
// Name        : 06.cpp
// Author      : Ivy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
//#undef main
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 750;

enum KeyPress {
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
SDL_Surface *surface = NULL;
SDL_Surface *pictures[k_end];
SDL_Surface *current = NULL;
SDL_Surface *strech = NULL;
SDL_Surface* optimizedSurface = NULL;
SDL_Surface* loadedSurface = NULL;

bool init();
bool loadMedia();
void close();
SDL_Surface* loadSurface(std::string path);

int main(int argc, char *argv[]) {
	if (!init()) {
		cout << "Failed initialization." << endl;
	} else {
		if (!loadMedia()) {
			cout << "Failed to load the media." << endl;
		} else {

			bool quit = false;
			current = pictures[k_default];

			SDL_Event e;

			while (!quit) {
				int i = 0;
				cout << quit << " ¹ " << i << endl;
				i++;
				while (SDL_PollEvent(&e) != 0) {
					if (e.type == SDL_QUIT) {
						cout << "Q" << endl;
						quit = true;
					} else {
						SDL_Rect stretchRect;
						stretchRect.x = 0;
						stretchRect.y = 0;
						stretchRect.w = 800;
						stretchRect.h = 750;

						switch (e.key.keysym.sym) {
						case SDLK_UP:
							current = pictures[k_up];
							stretchRect.w = 640;
							stretchRect.h = 480;
							stretchRect.x = (SCREEN_WIDTH
									- stretchRect.w) / 2;
							stretchRect.y = 0;
							SDL_BlitScaled(pictures[k_up],
							NULL, surface, &stretchRect);
							break;

						case SDLK_DOWN:
							current = pictures[k_down];
							stretchRect.w = 640;
							stretchRect.h = 480;
							stretchRect.y = SCREEN_HEIGHT
									- stretchRect.h;
							stretchRect.x = (SCREEN_WIDTH
									- stretchRect.w) / 2;
							SDL_BlitScaled(pictures[k_down],
							NULL, surface, &stretchRect);
							break;

						case SDLK_LEFT:
							current = pictures[k_left];
							stretchRect.w = 640;
							stretchRect.h = 480;
							stretchRect.y = (SCREEN_HEIGHT
									- stretchRect.h) / 2;
							stretchRect.x = 0;
							SDL_BlitScaled(pictures[k_left],
							NULL, surface, &stretchRect);
							break;

						case SDLK_RIGHT:
							current = pictures[k_right];
							stretchRect.w = 640;
							stretchRect.h = 480;
							stretchRect.y = (SCREEN_HEIGHT
									- stretchRect.h) / 2;
							stretchRect.x = (SCREEN_WIDTH
									- stretchRect.w);
							SDL_BlitScaled(
									pictures[k_right],
									NULL, surface,
									&stretchRect);
							break;

						case SDLK_s: {
							current = pictures[k_strech];
							stretchRect.w = 800;
							stretchRect.h = 750;
							SDL_BlitScaled(
									pictures[k_strech],
									NULL, surface,
									&stretchRect);
							break;
						}
						case SDLK_i:
							current = pictures[k_image];
							SDL_BlitSurface(current, NULL,
									surface,
									NULL);
							break;

						default:
							current = pictures[k_default];
							stretchRect.w = 640;
							stretchRect.h = 480;
							stretchRect.x = (SCREEN_WIDTH
									- stretchRect.w) / 2;
							stretchRect.y = (SCREEN_HEIGHT
									- stretchRect.h) / 2;
							SDL_BlitScaled(
									pictures[k_default],
									NULL, surface,
									&stretchRect);
							break;
						}
					}
					SDL_UpdateWindowSurface(window);
				}
				// blit - apply
			}
		}
	}

	close();
	return 0;
}

bool init() {
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		cout << "SDL doesn't work! SDL_Error: "
				<< SDL_GetError() << endl;
		success = false;
	}

	else {
		window = SDL_CreateWindow("SDL Tutorial",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
				SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL) {
			cout << "Window can't be created. SDL_Error: "
					<< SDL_GetError() << endl;
			success = false;
		}

		else {

			surface = SDL_GetWindowSurface(window);
		}
	}

	return success;
}

bool loadMedia() {
	bool success = true;
	pictures[k_default] = SDL_LoadBMP("hello_world.bmp");
	if (pictures[k_default] == NULL) {
		cout
				<< "The default picture can't be loaded. Error: "
				<< SDL_GetError() << endl;
		success = false;
	}

	pictures[k_up] = SDL_LoadBMP("up.bmp");
	if (pictures[k_up] == NULL) {
		cout << "The up picture can't be loaded. Error: "
				<< SDL_GetError() << endl;
		success = false;
	}

	pictures[k_down] = SDL_LoadBMP("down.bmp");
	if (pictures[k_down] == NULL) {
		cout << "The down picture can't be loaded. Error: "
				<< SDL_GetError() << endl;
		success = false;
	}

	pictures[k_left] = SDL_LoadBMP("left.bmp");
	if (pictures[k_left] == NULL) {
		cout << "The left picture can't be loaded. Error: "
				<< SDL_GetError() << endl;
		success = false;
	}

	pictures[k_right] = SDL_LoadBMP("right.bmp");
	if (pictures[k_right] == NULL) {
		cout << "The right picture can't be loaded. Error: "
				<< SDL_GetError() << endl;
		success = false;
	}
	pictures[k_strech] = SDL_LoadBMP("stretch.bmp");
	if (pictures[k_strech] == NULL) {
		cout
				<< "The streched picture can't be loaded. Error: "
				<< SDL_GetError() << endl;
		success = false;
	}
	pictures[k_image] = loadSurface("loaded.png");
	if (pictures[k_image] == NULL) {
		cout
				<< "The loaded picture can't be loaded. Error: "
				<< SDL_GetError() << endl;
		success = false;
	}

	return success;
}

void close() {
	SDL_FreeSurface(surface);
	surface = NULL;

	SDL_FreeSurface(loadedSurface);
	loadedSurface = NULL;

	SDL_FreeSurface(optimizedSurface);
	optimizedSurface = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	for (int i = 0; i < k_end; i++) {
		SDL_FreeSurface(pictures[i]);
		pictures[i] = NULL;
	}

	SDL_Quit();
}

SDL_Surface* loadSurface(std::string path) {
	loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		cout
				<< "The loaded picture can't be loaded. Error: "
				<< path.c_str() << SDL_GetError() << endl;

	} else {
		optimizedSurface = SDL_ConvertSurface(loadedSurface,
				surface->format, 0);
		if (optimizedSurface == NULL) {
			cout
					<< "The optimized surface can't be loaded. Error: "
					<< path.c_str() << SDL_GetError()
					<< endl;
		}
	}
	return loadedSurface;

}
