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

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

enum KeyPress {
	k_default,
	k_up,
	k_down,
	k_left,
	k_right,
	k_strech,
	k_total
};

SDL_Window *window = NULL;
SDL_Surface *surface = NULL;
SDL_Surface *pictures[k_total];
SDL_Surface *current = NULL;
SDL_Surface *strech = NULL;

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

			SDL_Event e;

			while (!quit) {
				while (SDL_PollEvent(&e) != 0) {
					current = pictures[k_default];

					if (e.type == SDL_QUIT) {
						quit = true;
					} else {
						switch (e.key.keysym.sym) {
						case SDLK_UP:
							current = pictures[k_up];
							break;
						case SDLK_DOWN:
							current = pictures[k_down];
							break;
						case SDLK_LEFT:
							current = pictures[k_left];
							break;
						case SDLK_RIGHT:
							current = pictures[k_right];
							break;
						default:
							current = pictures[k_default];
							break;
						}
					}
				}

				// blit - apply
				SDL_BlitSurface(current, NULL, surface,
				NULL);

				SDL_UpdateWindowSurface(window);

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
			cout << "Window can't be created.SDL_Error: "
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
		cout << "The picture can't be loaded. Error: "
				<< SDL_GetError() << endl;
		success = false;
	}

	pictures[k_up] = SDL_LoadBMP("up.bmp");
	if (pictures[k_up] == NULL) {
		cout << "The picture can't be loaded. Error: "
				<< SDL_GetError() << endl;
		success = false;
	}

	pictures[k_down] = SDL_LoadBMP("down.bmp");
	if (pictures[k_down] == NULL) {
		cout << "The picture can't be loaded. Error: "
				<< SDL_GetError() << endl;
		success = false;
	}

	pictures[k_left] = SDL_LoadBMP("left.bmp");
	if (pictures[k_left] == NULL) {
		cout << "The picture can't be loaded. Error: "
				<< SDL_GetError() << endl;
		success = false;
	}

	pictures[k_right] = SDL_LoadBMP("right.bmp");
	if (pictures[k_right] == NULL) {
		cout << "The picture can't be loaded. Error: "
				<< SDL_GetError() << endl;
		success = false;
	}
	pictures[k_strech] = loadSurface("stretch.bmp");

	return success;
}

void close() {
	SDL_FreeSurface(surface);
	surface = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	for (int i = 0; i < k_total; i++) {
		SDL_FreeSurface(pictures[i]);
		pictures[i] = NULL;
	}

	SDL_Quit();
}

SDL_Surface* loadSurface(std::string path) {
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == NULL) {
		cout
				<< "The stretched picture can't be loaded. Error: "
				<< path.c_str() << SDL_GetError() << endl;

	} else {
		optimizedSurface = SDL_ConvertSurface(loadedSurface,
				surface->format, NULL);
		if (optimizedSurface == NULL) {
			cout
					<< "The stretched picture can't be loaded. Error: "
					<< path.c_str() << SDL_GetError()
					<< endl;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
		return loadedSurface;
	}
