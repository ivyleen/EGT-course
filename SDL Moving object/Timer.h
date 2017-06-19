/*
 * Timer.h
 *
 *  Created on: 19.06.2017 ã.
 *      Author: IVY
 */

#ifndef TIMER_H_
#define TIMER_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>

class Timer
{
	Timer();
	virtual ~Timer();

	void start();
	void stop();
	void pause();
	void unpause();

	Uint32 getTicks();

	bool isStarted();
	bool isPaused();

private:
	Uint32 mStartTicks;
	Uint32 mPausedTicks;

	bool mPaused;
	bool mStarted;
};

#endif /* TIMER_H_ */
