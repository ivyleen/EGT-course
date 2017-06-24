/*
 * Game.h
 *
 *  Created on: 24.06.2017 ã.
 *      Author: IVY
 */

#ifndef GAME_H_
#define GAME_H_

#include "Globals.h"

class Game
{
public:
	static SDL_Window* gWindow;
	static SDL_Renderer* gRenderer;
	static SDL_Texture* background;

private:
	ChessFigures figures;
	SDL_Rect whiteChessFigures[6];
	SDL_Rect blackChessFigures[6];

	int chessBoard[8][8] = {
			{ 0, 1, 0, 1, 0, 1, 0, 1 },
			{ 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 1, 0, 1, 0, 1, 0, 1 },
			{ 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 1, 0, 1, 0, 1, 0, 1 },
			{ 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 1, 0, 1, 0, 1, 0, 1 },
			{ 1, 0, 1, 0, 1, 0, 1, 0 } };

public:
	Game();
	virtual ~Game();

	void start();
	void close();

	bool init();
	bool loadMedia();

	void drawChessBord();

private:
	void setBlackChessFigures();
	void setWhiteChessFigures();

	void drawChessFigures();

};

#endif /* GAME_H_ */
