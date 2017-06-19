/*
 * Texture.cpp
 *
 *  Created on: 16.06.2017 ã.
 *      Author: IVY
 */

#include "Texture.h"

Texture::Texture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

Texture::~Texture()
{
	//Deallocate
	free();
}

SDL_Texture* Texture::loadFromFile(SDL_Renderer* renderer,
		string path)
{
	free();
	SDL_Texture * newTexture = NULL;
	SDL_Surface * loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		cout << "Loaded surface is NULL: " << IMG_GetError()
				<< endl;
	} else
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE,
				SDL_MapRGB(loadedSurface->format, 0, 0, 0));
		newTexture = SDL_CreateTextureFromSurface(renderer,
				loadedSurface);
		if (newTexture == NULL)
		{
			cout << "New texture is NULL: "
					<< SDL_GetError() << endl;
		} else
		{
			mHeight = loadedSurface->h;
			mWidth = loadedSurface->w;
		}
		SDL_FreeSurface(loadedSurface);
	}
	mTexture = newTexture;
	return mTexture;
}

SDL_Texture* Texture::loadFromRenderedText(
		SDL_Renderer* renderer, TTF_Font* gFont,
		string textureText, SDL_Color textColor)
{
	free();

	SDL_Surface * textSurface = TTF_RenderText_Solid(gFont,
			textureText.c_str(), textColor);

	if (textSurface == NULL)
	{
		cout << "Text surface is NULL: " << SDL_GetError()
				<< endl;
	} else
	{
		textTexture = SDL_CreateTextureFromSurface(renderer,
				textSurface);
		if (textTexture == NULL)
		{
			cout << "textureText is NULL: "
					<< SDL_GetError() << endl;
		} else
		{
			tthH = textSurface->h;
			tthW = textSurface->w;
		}
	}
	SDL_FreeSurface(textSurface);

	return textTexture;
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

	if (textTexture != NULL)
	{
		SDL_DestroyTexture(textTexture);
		textTexture = NULL;
		tthW = 0;
		tthH = 0;
	}
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

void Texture::render(SDL_Renderer* renderer, SDL_Rect* clip,
		double angle, SDL_Point* center,
		SDL_RendererFlip flip)
{
	SDL_Rect rRect =
	{ 0, 0, mWidth, mHeight };

	// text rect
	SDL_Rect renderRect =
	{ 0, 0, tthH, tthW };

	if (clip != NULL)
	{
		renderRect.x = clip->x;
		renderRect.y = clip->y;
		renderRect.w = clip->w;
		renderRect.h = clip->h;
	}

	SDL_RenderCopyEx(renderer, mTexture, clip, &rRect,
			angle, center, flip);
	SDL_RenderCopyEx(renderer, textTexture, clip,
			&renderRect, angle, center, flip);
}

int Texture::getTthH() const
{
	return tthH;
}

int Texture::getTthW() const
{
	return tthW;
}

int Texture::getHeight() const
{
	return mHeight;
}

int Texture::getWidth() const
{
	return mWidth;
}
