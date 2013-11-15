#include "TileGrid.h"

TileGrid::TileGrid()
{

}

bool TileGrid::HandleEvents(const SDL_Event &Event)
{


	return true;
}
void TileGrid::Update()
{

}
void TileGrid::Draw(SDL_Renderer *const Renderer)
{
	for(unsigned int y=0; y<Tiles.size(); y++)
	{
		for(unsigned int x=0; x<Tiles.size(); x++)
		{
			Tiles[y][x].Draw(Renderer);
		}
	}
}