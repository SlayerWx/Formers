#include "Wall.h"
#include "raylib.h"
#include "gameElements/levels/Zone_Structures.h"
namespace FormersMJ
{
	Wall::Wall()
	{
		type = 'W';
	}

	Wall::~Wall()
	{
	}
	Wall::Wall(Vector2 Pos, Color myNewColor):Zone_Structures(Pos, rectangle, myNewColor)
	{
		type = 'W';
	}
	void Wall::checkCollision(Vector2 playerPos, Vector2 lastPosition)
	{
		playerPos = playerPos;
		lastPosition = lastPosition;
	}
}