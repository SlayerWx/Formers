#include "Wall.h"
#include "raylib.h"
#include "gameElements/levels/Zone_Structures.h"
namespace FormersMJ
{

	Wall::Wall(Vector2 Pos, Color myNewColor,Texture2D myNewSkin):
		Zone_Structures(Pos, rectangle, myNewColor,myNewSkin)
	{
		type = 'W';
	}
	Wall::~Wall()
	{

	}
	void Wall::checkCollision(Vector2 playerPos, Vector2 lastPosition)
	{
		playerPos = playerPos;
		lastPosition = lastPosition;
	}
}