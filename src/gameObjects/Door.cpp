#include "Door.h"
namespace FormersMJ
{
	Door::Door(Vector2 Pos, TileType form, Color Color): 
		Zone_Structures(Pos,form,Color)
	{
		type = 'D';
		isOpen = false;
	}
	Door::~Door()
	{
	}
	void Door::setOpen(bool isNewOpen)
	{
		isOpen = isNewOpen;
	}
	bool Door::getIsOpen()
	{
		return isOpen;
	}
	void Door::checkCollision(Vector2 playerPos, Vector2 lastPosition)
	{
		if (playerPos.x == myPosition.x - 30.0f &&
			playerPos.y == myPosition.y - 30.0f)
		{
		}
	}
}