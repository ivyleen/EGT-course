/*
 * ChessFigures.cpp
 *
 *  Created on: 21.06.2017 ã.
 *      Author: IVY
 */

#include "ChessFigures.h"

// constructor & destructor
ChessFigures::ChessFigures()
		: m_iHeight(), m_iWidth(), figure()
{
	// TODO Auto-generated constructor stub

}

ChessFigures::~ChessFigures()
{
	free();
}

// setters & getters
int ChessFigures::getIHeight() const
{
	return m_iHeight;
}

void ChessFigures::setIHeight(int iHeight)
{
	m_iHeight = iHeight;
}

int ChessFigures::getIWidth() const
{
	return m_iWidth;
}

void ChessFigures::setIWidth(int iWidth)
{
	m_iWidth = iWidth;
}

// methods
bool ChessFigures::loadFromFile(SDL_Renderer* renderer,
		std::string path)
{
	free();

	SDL_Surface * loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		std::cout
				<< "LoadFromFile::loadededSurface didn't load."
				<< std::endl;
	} else
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE,
				SDL_MapRGB(loadedSurface->format, 2,
						255, 255));
		figure = SDL_CreateTextureFromSurface(renderer,
				loadedSurface);
		if (figure == NULL)
		{
			std::cout << "Unable to load figure."
					<< std::endl;
		} else
		{
			m_iHeight = loadedSurface->h;
			m_iWidth = loadedSurface->w;
		}
	}

	return figure != NULL;
}

void ChessFigures::render(SDL_Renderer* renderer, int x,
		int y, SDL_Rect* oldPos)
{
	SDL_Rect newPos = { x, y, m_iWidth, m_iHeight };

	if (oldPos != NULL)
	{
		newPos.w = oldPos->w/4;
		newPos.h = oldPos->h/4;
	}

	SDL_RenderCopy(renderer, figure, oldPos, &newPos);
}

void ChessFigures::isClicked()
{

}

void ChessFigures::free()
{
	if (figure != NULL)
	{
		figure = NULL;
		m_iHeight = 0;
		m_iWidth = 0;
	}

}
