#include "GameScreen.h"

#include "Settings.h"

GameScreen::GameScreen(Texture *const ChosenImage)
{
	Image=ChosenImage;
}

bool GameScreen::Load(SDLWindow *const Window)
{
	ImageWidth=Image->GetWidth()-(Image->GetWidth()%Settings::TileWidth);
	ImageHeight=Image->GetHeight()-(Image->GetHeight()%Settings::TileHeight);

	Window->SetSize(ImageWidth, ImageHeight);

	return true;
}

ScreenResult GameScreen::HandleEvents(const SDL_Event &Event, std::stack<Screen *> *const Screens)
{


	return ScreenResult::Success;
}
void GameScreen::Update()
{

}
void GameScreen::Draw(SDL_Renderer *const Renderer)
{

}