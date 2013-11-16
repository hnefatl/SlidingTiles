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
	if(!Moving)
	{
		Moving=true;
		MovingTo=To;
		OriginalPosition=Position;
	}
}

void Tile::Update()
{
	if(Moving)
	{
		if(Position==MovingTo)
		{
			MovingTo=false;
		}
		Position.x+=(MovingTo.x-OriginalPosition.x)/(int)FramesToMove;
		Position.y+=(MovingTo.y-OriginalPosition.y)/(int)FramesToMove;
	}
}
void Tile::Draw(SDL_Renderer *const Renderer)
{
	if(!Blank)
	{
		SourceImage->Render(Renderer, Position, Clip);
	}
}

unsigned int Tile::FramesToMove=10;