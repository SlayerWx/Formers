#include "Wall.h"
namespace FormersMJ
{
	Wall::Wall()
	{
	}

	Wall::~Wall()
	{
	}
	Wall::Wall(Vector2 Pos, Color myNewColor, Colors numColor):Zone_Structures(Pos, rectangle, myNewColor, numColor)
	{
	}
	void Wall::checkCollision(Vector2 playerPos, Vector2 lastPosition)
	{
	}
}