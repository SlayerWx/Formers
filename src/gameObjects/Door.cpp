#include "Door.h"
#include "raylib.h"
#include "gameElements/levels/Zone_Structures.h"
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
	TileType Door::getForm()
	{
		if (myForm == doorC || myForm == doorCB || myForm == doorCR || myForm == doorCG) { return circle; }else
		if (myForm == doorR || myForm == doorRB || myForm == doorRR || myForm == doorRG) { return rectangle; }else
		if (myForm == doorT || myForm == doorTB || myForm == doorTR || myForm == doorTG) { return triangle; }
		else
		{
			return myForm;
		}
		
	}
	void Door::checkCollision(Vector2 playerPos, Vector2 lastPosition)
	{
		if (playerPos.x == myPosition.x - tileScale &&
			playerPos.y == myPosition.y - tileScale)
		{
		}
	}
}