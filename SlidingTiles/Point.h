#ifndef _POINT_H
#define _POINT_H

#include <SDL.h>

class Point
	: public SDL_Point
{
public:
	Point(const int &x, const int &y)
	{
		this->x=x;
		this->y=y;
	}

	operator SDL_Point ()
	{
		return (SDL_Point)*this;
	}
	
	Point operator +(const Point &One)
	{
		return Point(x+One.x, y+One.y);
	}
	Point operator -(const Point &One)
	{
		return Point(x-One.x, y-One.y);
	}
	Point operator *(const Point &One)
	{
		return Point(x*One.x, y*One.y);
	}
	Point operator /(const Point &One)
	{
		return Point(x*One.x, y*One.y);
	}
};

#endif