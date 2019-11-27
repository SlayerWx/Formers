#ifndef DOOR_H
#define DOOR_H
#include "raylib.h"

#include "gameElements/levels/Zone_Structures.h"

namespace FormersMJ
{
	class Door :public Zone_Structures
	{
	public:
		Door(Vector2 Pos, TileType form, Color Color, Texture2D myNewSkin);
		~Door();
		void setOpen(bool isNewOpen);
		void checkCollision(Vector2 playerPos, Vector2 lastPosition);
		bool getIsOpen();
		TileType getForm();
	private:
		bool isOpen;
	};
}
#endif