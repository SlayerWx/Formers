#include "gameElements/levels/Zone_Structures.h"
namespace FormersMJ
{
	class Door :public Zone_Structures
	{
	public:
		Door(Vector2 Pos, TileType form, Color myColor);
		~Door();
		void setOpen(bool isNewOpen);
		void checkCollision(Vector2 playerPos, Vector2 lastPosition);
		bool getIsOpen();
	private:
		bool isOpen;
	};
}