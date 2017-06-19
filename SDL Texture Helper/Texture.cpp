/*
 * Texture.cpp
 *
 *  Created on: 16.06.2017 ã.
 *      Author: IVY
 */

#include "Texture.h"

Texture::Texture()
{
	background = NULL;
	txtTexture = NULL;
	mWidth = 300;
	mHeight = 50;
}

Texture::~Texture()
{
	free();
}

SDL_Texture* Texture::loadFromFile(SDL_Renderer * renderer,
		std::string path)
{
	free();

	SDL_Texture *newTexture = NULL;
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		std::cout
				<< "Loaded surface of loadFromFile didn't load: "
				<< IMG_GetError() << std::endl;
	} else
	{
		newTexture = SDL_CreateTextureFromSurface(renderer,
				loadedSurface);
		if (newTexture == NULL)
		{
			std::cout << "The texture couldn't be created: "
					<< SDL_GetError() << std::endl;
		} else
		{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		SDL_FreeSurface(loadedSurface);
	}
	background = newTexture;
	return newTexture;
}

SDL_Texture* Texture::loadFromRenderedText(SDL_Renderer * renderer,
		TTF_Font *font, std::string textureText,
		SDL_Color textColor)
{
	free();
	SDL_Surface* textSurface = TTF_RenderText_Solid(font,
			textureText.c_str(), textColor);

	if (textSurface == NULL)
	{
		std::cout
				<< "There is a problem with loaded textSurface"
				<< TTF_GetError() << std::endl;
	} else
	{
		txtTexture = SDL_CreateTextureFromSurface(renderer,
				textSurface);
		if (txtTexture == NULL)
		{
			std::cout
					<< "Problem in load from rendered text "
					<<
					TTF_GetError() << std::endl;
		} else {

		}
		SDL_FreeSurface(textSurface);
	}

	return txtTexture;
}

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod(txtTexture, red, green, blue);
}

void Texture::setBlendMode(SDL_BlendMode blending)
{
	SDL_SetTextureBlendMode(txtTexture, blending);
}

void Texture::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(txtTexture, alpha);
}

void Texture::renderB(SDL_Renderer * renderer,
		SDL_Rect* clip, double angle, SDL_Point* center,
		SDL_RendererFlip flip)
{
	SDL_Rect rRect =
	{ 50, 50, 540, 500 };
	SDL_Rect renderRect =
	{ 0, 0, mWidth, mHeight };

	if (clip != NULL)
	{
		renderRect.x = clip->x;
		renderRect.y = clip->y;
		renderRect.w = clip->w;
		renderRect.h = clip->h;
	}

	SDL_RenderCopyEx(renderer, background, clip, &rRect,
			angle, center, flip);
	SDL_RenderCopyEx(renderer, txtTexture, clip,
			&renderRect, angle, center, flip);
}

void Texture::free()
{
	if (txtTexture != NULL)
	{
		SDL_DestroyTexture(txtTexture);
		txtTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

int Texture::getWidth()
{
	return mWidth;
}

int Texture::getHeight()
{
	return mHeight;
}
