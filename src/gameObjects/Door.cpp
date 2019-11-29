#include "Door.h"
#include "raylib.h"
#include "gameElements/levels/Zone_Structures.h"
namespace FormersMJ
{
	Door::Door(Vector2 Pos, TileType form, Color Color,Texture2D myNewSkin): 
		Zone_Structures(Pos,form,Color,myNewSkin)
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
	TileType Door::getForm()
	{
			return myForm;
	}
	void Door::checkCollision(Vector2 playerPos, Vector2 lastPosition)
	{
		if (playerPos.x == myPosition.x - tileScale &&
			playerPos.y == myPosition.y - tileScale)
		{
			lastPosition = lastPosition;
		}
	}
}