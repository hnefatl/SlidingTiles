#ifndef _TILEGRID_H
#define _TILEGRID_H

#include "Tile.h"
#include "Control.h"

#include <vector>

class TileGrid
	: Control
{
public:
	TileGrid();
	
	virtual bool HandleEvents(const SDL_Event &Event);
	virtual void Update();
	virtual void Draw(SDL_Renderer *const Renderer);

protected:
	Point SelectedTile;

	std::vector<std::vector<Tile>> Tiles;
};

#endif