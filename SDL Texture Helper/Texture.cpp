/*
 * Texture.cpp
 *
 *  Created on: 16.06.2017 ã.
 *      Author: IVY
 */

#include "Texture.h"

Texture::Texture()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

Texture::~Texture()
{
	free();
}

bool Texture::loadFromFile(SDL_Renderer * renderer,
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
		SDL_SetColorKey(loadedSurface, SDL_TRUE,
				SDL_MapRGB(loadedSurface->format, 0, 10,
						255));

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
	mTexture = newTexture;
	return mTexture != NULL;
}

bool Texture::loadFromRenderedText(SDL_Renderer * renderer,
		std::string textureText, SDL_Color textColor)
{
	TTF_Font *font = NULL;
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
		mTexture = SDL_CreateTextureFromSurface(renderer,
				textSurface);
		if (mTexture == NULL)
		{
			std::cout
					<< "Problem in load from rendered text "
					<<
					TTF_GetError() << std::endl;
		} else
		{
			mHeight = textSurface->h;
			mWidth = textSurface->w;
		}
		SDL_FreeSurface(textSurface);
	}

	return mTexture != NULL;
}

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void Texture::setBlendMode(SDL_BlendMode blending)
{
	SDL_SetTextureBlendMode(mTexture, blending);
}

void Texture::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

void Texture::render(SDL_Renderer * renderer, int x, int y,
		SDL_Rect* clip, double angle, SDL_Point* center,
		SDL_RendererFlip flip)
{
	SDL_Rect renderRect =
	{ x, y, mWidth, mHeight };

	if (clip != NULL)
	{
		renderRect.w = clip->w;
		renderRect.h = clip->h;
	}
	SDL_RenderCopyEx(renderer, mTexture, clip, &renderRect,
			angle, center, flip);
}

void Texture::free()
{
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
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
