#ifndef _TILE_H
#define _TILE_H

#include "Texture.h"
#include "Rect.h"
#include "Settings.h"

class Tile
{
public:
	Tile();
	Tile(Texture *const SourceImage);

	void Swap(const Tile &One);

	void 

protected:
	bool Blank;

	Texture *SourceImage;
	Rect Clip;
	Rect Position;
};

#endif