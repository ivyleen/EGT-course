/*
 * Texture.h
 *
 *  Created on: 16.06.2017 ã.
 *      Author: IVY
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include <cmath>

class Texture
{
public:
	Texture();

	~Texture();

	SDL_Texture* loadFromFile(SDL_Renderer * renderer,
			std::string path);

	SDL_Texture* loadFromRenderedText(SDL_Renderer * renderer,
			TTF_Font *gFont, std::string textureText,
			SDL_Color textColor);

	void free();

	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	void setBlendMode(SDL_BlendMode blending);

	void setAlpha(Uint8 alpha);

	void renderB(SDL_Renderer * renderer,
			SDL_Rect* clip, double angle = 0.0,
			SDL_Point* center = NULL,
			SDL_RendererFlip flip = SDL_FLIP_NONE);


	int getWidth();
	int getHeight();

private:
	SDL_Texture* txtTexture;
	SDL_Texture* background;

	int mWidth;
	int mHeight;


};

#endif /* TEXTURE_H_ */
