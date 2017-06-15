/*
 * Texture.cpp
 *
 *  Created on: 15.06.2017 �.
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

bool Texture::loadFromFile(SDL_Renderer* gRenderer,
		std::string path)
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf(
				"Unable to load image %s! SDL_image Error: %s\n",
				path.c_str(), IMG_GetError());
	} else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE,
				SDL_MapRGB(loadedSurface->format, 0, 0xFF,
						0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer,
				loadedSurface);
		if (newTexture == NULL)
		{
			printf(
					"Unable to create texture from %s! SDL Error: %s\n",
					path.c_str(), SDL_GetError());
		} else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
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

SDL_Renderer* Texture::render(SDL_Renderer* gRenderer, int x, int y,
		SDL_Rect* clip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad =
	{ x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopy(gRenderer, mTexture, clip, &renderQuad);
	return gRenderer;
}

int Texture::getWidth()
{
	return mWidth;
}

int Texture::getHeight()
{
	return mHeight;
}
