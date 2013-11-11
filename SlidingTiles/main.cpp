#include <SDL.h>
#ifdef _DEBUG
#include <iostream>
#endif

#include "SDLWindow.h"
#include "Screen.h"
#include "MainMenuScreen.h"
#include "GameScreen.h"
#include "Timer.h"

#include <stack>

int main(int argc, char *argv[])
{
	if(!InitialisePrint())
		return -1;
	if(!Settings::Initialise())
		return -2;
	if(!Settings::Load())
		return -3;

	SDLWindow Window;
	if(!Window.Create(Settings::WindowWidth, Settings::WindowHeight, "Sliding Tiles"))
		return -4;

	std::stack<Screen *> Screens;
	Screens.push(new MainMenuScreen());
	Screens.top()->Load(Window.GetRenderer());

	const unsigned int FPS=60;
	Timer Timer;

	while(!Screens.empty())
	{
		Timer.Start();

		SDL_Event Event;
		if(SDL_PollEvent(&Event))
		{
			if(Event.type==SDL_QUIT)
			{
				break;
			}

			ScreenResult Result=Screens.top()->HandleEvents(Event, &Screens);
			if(Result==ScreenResult::Error)
			{
				Print("Error in screen.");
			}
			else if(Result==ScreenResult::NewScreen)
			{
				if(dynamic_cast<GameScreen *>(Screens.top())!=NULL)
				{
					if(!dynamic_cast<GameScreen *>(Screens.top())->Load(&Window))
					{
						Print("Failed to load game screen.");
						break;
					}
				}
				else
				{
					if(!Screens.top()->Load(Window.GetRenderer()))
					{
						Print("Failed to load screen.");
						break;
					}
				}
			}
			else if(Result==ScreenResult::RemoveScreen)
			{
				delete Screens.top();
				Screens.top()=NULL;
				Screens.pop();
			}
		}

		if(!Screens.empty())
		{
			Screens.top()->Update();

			Window.BeginScene();
			Screens.top()->Draw(Window.GetRenderer());
			Window.EndScene();
		}

		if(Timer.GetTicks()<(1000/FPS))
		{
			SDL_Delay((1000/FPS)-Timer.GetTicks());
		}
	}

	while(!Screens.empty())
	{
		if(Screens.top()!=NULL)
		{
			delete Screens.top();
			Screens.top()=NULL;
			Screens.pop();
		}
	}

	return 0;
}