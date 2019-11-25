#ifndef WALL_H
#define WALL_H
#include "gameElements/levels/Zone_Structures.h"
#include "raylib.h"
namespace FormersMJ
{
	class Wall :public Zone_Structures
	{
	public:
		Wall();
		~Wall();
		Wall(Vector2 Pos, Color myColor);
		void checkCollision(Vector2 playerPos, Vector2 lastPosition);
	private:

	};
}
#endif
