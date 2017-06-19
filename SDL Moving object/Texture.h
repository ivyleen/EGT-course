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
using std::cout;
using std::endl;
using std::string;

class Texture
{
public:
	Texture();
	virtual ~Texture();

	SDL_Texture* loadFromFile(SDL_Renderer * renderer,
			string path);

	SDL_Texture* loadFromRenderedText(SDL_Renderer * renderer,
			TTF_Font *gFont, string textureText,
			SDL_Color textColor);

	void free();

	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	void setBlendMode(SDL_BlendMode blending);

	void setAlpha(Uint8 alpha);

	void render(SDL_Renderer * renderer,
			SDL_Rect* clip, double angle = 0.0,
			SDL_Point* center = NULL,
			SDL_RendererFlip flip = SDL_FLIP_NONE);


	int getTthH() const;
	int getTthW() const;

	int getHeight() const;
	int getWidth() const;

private:
	SDL_Texture* mTexture;
	SDL_Texture* textTexture;

	int tthW;
	int tthH;

	int mWidth;
	int mHeight;
};

#endif /* TEXTURE_H_ */
