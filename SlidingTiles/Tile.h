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

	void Swap(Tile &One);

	void Update();
	void Draw(SDL_Renderer *const Renderer);

	void Move(const Rect &To);

protected:
	bool Blank;

	Texture *SourceImage;
	Rect Clip;
	Rect Position;

	bool Moving;
	Rect MovingTo;

	static Point Velocity;
};

#endif
