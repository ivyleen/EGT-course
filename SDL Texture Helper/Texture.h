/*
 * Texture.h
 *
 *  Created on: 15.06.2017 ã.
 *      Author: IVY
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Texture
{
public:
	Texture();

//Deallocates memory
	~Texture();

//Loads image at specified path
	bool loadFromFile(SDL_Renderer* gRenderer,
			std::string path);

//Deallocates texture
	void free();

//Renders texture at given point
	SDL_Renderer* render(SDL_Renderer* gRenderer, int x, int y,
			SDL_Rect* clip = NULL);

//Gets image dimensions
	int getWidth();
	int getHeight();

private:
//The actual hardware texture
	SDL_Texture* mTexture;

//Image dimensions
	int mWidth;
	int mHeight;
};

#endif /* TEXTURE_H_ */
