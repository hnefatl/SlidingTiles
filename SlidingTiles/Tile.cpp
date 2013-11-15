#include "Tile.h"

Tile::Tile()
{
	SourceImage=NULL;
	Blank=true;
}
Tile::Tile(Texture *const SourceImage)
{
	this->SourceImage=SourceImage;
	Blank=false;
}

void Tile::Swap(Tile &One)
{
	Rect TempPosition=this->Position;
	this->Position=One.Position;
	One.Position=TempPosition;
}

void Tile::Move(const Rect &To)
{
	Moving=true;
	MovingTo=To;
}

void Tile::Update()
{
	if(Moving)
	{

	}
}
void Tile::Draw(SDL_Renderer *const Renderer)
{
	if(!Blank)
	{
		SourceImage->Render(Renderer, Position, Clip);
	}
}

Point Tile::Velocity=Point();