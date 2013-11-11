#include "LoadingScreen.h"

#include <Windows.h>
#include <vector>
#include <string>

#include "GameScreen.h"

LoadingScreen::LoadingScreen()
{
	Done=false;
	Executed=false;
}
LoadingScreen::~LoadingScreen()
{
	LoadingThread.detach();
}

bool LoadingScreen::Load(SDL_Renderer *const Renderer)
{
	LoadingThread=std::thread(&LoadingScreen::LoadGame, this, Renderer);

	return true;
}

ScreenResult LoadingScreen::HandleEvents(const SDL_Event &Event, std::stack<Screen *> *const Screens)
{
	if(Executed)
	{
		return ScreenResult::RemoveScreen;
	}
	MessageLock.lock();
	if(!Message.HandleEvents(Event))
	{
		MessageLock.unlock();
		return ScreenResult::Error;
	}
	MessageLock.unlock();

	DoneLock.lock();
	if(Done)
	{
		Screens->push(new GameScreen(&ChosenImage));
		DoneLock.unlock();
		return ScreenResult::NewScreen;
	}
	DoneLock.unlock();

	return ScreenResult::Success;
}
void LoadingScreen::Update()
{
	MessageLock.lock();
	Message.Update();
	MessageLock.unlock();
}
void LoadingScreen::Draw(SDL_Renderer *const Renderer)
{
	MessageLock.lock();
	Message.Draw(Renderer);
	MessageLock.unlock();
}

void LoadingScreen::LoadGame(SDL_Renderer *const Renderer)
{
	ChangeMessageText("Selected image...", Renderer);

	srand((unsigned int)time(NULL));
	std::vector<std::string> Files=FindImageFiles();
	std::string File=Files[rand()%Files.size()];
	Files.clear();

	ChangeMessageText("Loading image \""+File+"\"...", Renderer);

	ChosenImage.Load(File, Renderer);

	DoneLock.lock();
	Done=false;
	DoneLock.unlock();
}
std::vector<std::string> LoadingScreen::FindImageFiles()
{
	std::vector<std::string> Files;
	std::vector<std::string> SupportedExtensions;
	SupportedExtensions.push_back(".bmp");
	SupportedExtensions.push_back(".png");
	SupportedExtensions.push_back(".jpg");

	HANDLE Finder;
	LPWIN32_FIND_DATA FindData=NULL;

	Finder=FindFirstFile("Images\\*.*", FindData);
	if(Finder!=INVALID_HANDLE_VALUE)
	{
		do
		{
			std::string Extension=FindData->cFileName;
			Extension=Extension.substr(Extension.find_last_of(".")+1);
			bool Valid=false;
			for(unsigned int x=0; x<SupportedExtensions.size(); x++)
			{
				if(SupportedExtensions[x]==Extension)
				{
					Valid=true;
					break;
				}
			}
			if(Valid)
			{
				Files.push_back(FindData->cFileName);
			}
		} while(FindNextFile(Finder, FindData));
	}

	return Files;
}

void LoadingScreen::ChangeMessageText(const std::string &Text, SDL_Renderer *const Renderer)
{
	MessageLock.lock();
	Message.Load(Resources::Fonts::Arial, Text, 20, Renderer);
	Message.SetLocation(Point((Settings::WindowWidth/2)-(Message.GetLocation().w/2), (Settings::WindowHeight/2)-(Message.GetLocation().h/2)));
	MessageLock.unlock();
}