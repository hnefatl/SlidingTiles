#ifndef _RECT_H
#define _RECT_H

#include <SDL.h>

#include "Point.h"

class Rect
	: public SDL_Rect
{
public:
	Rect(const int &x=0, const int &y=0, const unsigned int &w=0, const unsigned int &h=0)
	{
		this->x=x;
		this->y=y;
		this->w=w;
		this->h=h;
	}
	Rect(const Point &Position, const unsigned int &w=0, const unsigned int &h=0)
	{
		this->x=Position.x;
		this->y=Position.y;
		this->w=w;
		this->h=h;
	}

	bool Collides(const Point &Location) const
	{
		return (x<=Location.x && x+w>=Location.x && y<=Location.y && y+h>=Location.y);
	}
	bool Collides(const Rect &Location) const
	{
		return (x<Location.x+Location.w &&
			x+w>Location.x &&
			y<Location.y+Location.h &&
			y+h>Location.y);
	}

	operator SDL_Rect ()
	{
		return (SDL_Rect)*this;
	}
	operator Point ()
	{
		return Point(x, y);
	}

	bool operator ==(const Rect &One) const
	{
		return (this->x==One.x && this->y==One.y && this->w==One.w && this->h==One.h);
	}
	bool operator !=(const Rect &One) const
	{
		return !(*this==One);
	}
};

#endif