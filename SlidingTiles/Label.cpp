#include "Label.h"

Label::Label()
{

}

bool Label::HandleEvents(const SDL_Event &Event)
{
	return true;
}
void Label::Update()
{

}
void Label::Draw(SDL_Renderer *const Renderer)
{
	if(Visible)
		Image.Render(Renderer, Position);
}