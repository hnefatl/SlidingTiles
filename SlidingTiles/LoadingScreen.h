#ifndef _LOADINGSCREEN_H
#define _LOADINGSCREEN_H

#include "Screen.h"
#include "Label.h"
#include "Button.h"

#include <thread>
#include <mutex>

class LoadingScreen
	: public Screen
{
public:
	LoadingScreen();
	~LoadingScreen();

	virtual bool Load(SDL_Renderer *const Renderer);

	virtual ScreenResult HandleEvents(const SDL_Event &Event, std::stack<Screen *> *const Screens);
	virtual void Update();
	virtual void Draw(SDL_Renderer *const Renderer);

protected:
	void LoadGame(SDL_Renderer *const Renderer);
	std::vector<std::string> FindImageFiles();
	
	void ChangeMessageText(const std::string &Text, SDL_Renderer *const Renderer);

	Texture ChosenImage;

	Label Message;
	std::mutex MessageLock;

	std::thread LoadingThread;

	bool Done;
	std::mutex DoneLock;
	
	bool Executed;
};

#endif