/*
 * Object.h
 *
 *  Created on: 19.06.2017 ã.
 *      Author: IVY
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Object
{
private:
	int mPosX, mPosY;
	int mVelX, mVelY;

public:
	static const int OBJECT_WIDTH = 20;
	static const int OBJECT_HEIGHT = 20;
	static const int OBJECT_VEL = 10;

	Object();
	virtual ~Object();

	void handleEvent(SDL_Event& e);
	void move();
	void render();
};

#endif /* OBJECT_H_ */
