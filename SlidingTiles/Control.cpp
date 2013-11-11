#include "Control.h"

#include "Settings.h"

Control::Control()
{
	Visible=true;
	CurrentColour=Settings::UnselectedColour;
}

bool Control::Load(const std::string &ImagePath, SDL_Renderer *const Renderer)
{
	if(!Image.Load(ImagePath, Renderer))
	{
		return false;
	}

	Position.w=Image.GetWidth();
	Position.h=Image.GetHeight();

	return true;
}
bool Control::Load(const std::string &FontPath, const std::string &Text, const unsigned int &PtSize, SDL_Renderer *const Renderer)
{
	if(!Image.Load(Text, FontPath, PtSize, Colour(0xFF, 0xFF, 0xFF), Renderer))
	{
		return false;
	}

	Position.w=Image.GetWidth();
	Position.h=Image.GetHeight();

	return true;
}

bool Control::Contains(const Point &Point)
{
	return Position.Collides(Point);
}

Rect Control::GetLocation() const
{
	return Position;
}
void Control::SetLocation(const Point &Location)
{
	Position.x=Location.x;
	Position.y=Location.y;
}

Colour Control::GetColour() const
{
	return CurrentColour;
}
void Control::SetColour(const Colour &Colour)
{
	this->CurrentColour=Colour;
}

bool Control::IsVisible() const
{
	return Visible;
}
void Control::SetVisible(const bool &Visible)
{
	this->Visible=Visible;
}