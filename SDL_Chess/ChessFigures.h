/*
 * ChessFigures.h
 *
 *  Created on: 21.06.2017 ã.
 *      Author: IVY
 */

#ifndef CHESSFIGURES_H_
#define CHESSFIGURES_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

class ChessFigures
{
private:
	int m_iHeight;
	int m_iWidth;

	SDL_Texture* figure;

public:
	ChessFigures();
	virtual ~ChessFigures();

	// setters & getters
	int getIHeight() const;
	void setIHeight(int iHeight);

	int getIWidth() const;
	void setIWidth(int iWidth);

	// methods
	bool loadFromFile(SDL_Renderer* renderer, std::string path);
	void render(SDL_Renderer* renderer, int x, int y, SDL_Rect* oldPos);
	bool isClicked();
	void free();

};

#endif /* CHESSFIGURES_H_ */
