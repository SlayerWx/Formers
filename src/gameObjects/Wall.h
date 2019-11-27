#ifndef WALL_H
#define WALL_H

#include "raylib.h"
#include "gameElements/levels/Zone_Structures.h"
namespace FormersMJ
{
	class Wall :public Zone_Structures
	{
	public:
		Wall(Vector2 Pos, Color myNewColor, Texture2D myNewSkin);
		~Wall();
		void checkCollision(Vector2 playerPos, Vector2 lastPosition);
		static Texture2D mySkin;
	private:

	};
}
#endif
