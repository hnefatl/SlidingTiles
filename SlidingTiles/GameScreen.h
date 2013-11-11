#ifndef _GAMESCREEN_H
#define _GAMESCREEN_H

#include "Screen.h"

#include "Texture.h"
#include "SDLWindow.h"

class GameScreen
	: public Screen
{
public:
	GameScreen(Texture *const ChosenImage);

	virtual bool Load(SDLWindow *const Window);

	virtual ScreenResult HandleEvents(const SDL_Event &Event, std::stack<Screen *> *const Screens);
	virtual void Update();
	virtual void Draw(SDL_Renderer *const Renderer);

protected:
	virtual bool Load(SDL_Renderer *const Renderer)
	{
		return true;
	}

	Texture *Image;

	unsigned int ImageWidth;
	unsigned int ImageHeight;
};

#endif