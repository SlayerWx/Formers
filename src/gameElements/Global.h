#ifndef GLOBAL_H
#define GLOBAL_H

#include "raylib.h"
namespace FormersMJ
{
	static float tileScale = 30.0f;
	static Sound mySoundDoor;
	const int mapColumn = 27;
	const int mapRow = 15;
	const static Vector2 rightDoor = { (mapColumn-1)*tileScale , tileScale*8 };
	const static Vector2 bottomDoor = { ((mapColumn+1)/2)*tileScale , (mapRow - 1)*tileScale };
	const static Vector2 topDoor = { ((mapColumn + 1) / 2)*tileScale, 0 };
	const static Vector2 leftDoor = { 0 , tileScale * 8 };
	static const int SCALEDIF = 1;
#define F_DARKRED  CLITERAL{ 182, 24, 24, 255 }
#define F_DARKGREEN  CLITERAL{ 24, 182, 24, 255 }
#define F_DARKBLUE  CLITERAL{ 24, 24, 182, 255 } 
	enum GameStage
	{
		MENU, GAME, CREDITS, EXIT
	};
	extern GameStage gamestatus;
}
#endif

