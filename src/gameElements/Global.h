#ifndef GLOBAL_H
#define GLOBAL_H
namespace FormersMJ
{
	static float tileScale = 30.0f;
	const int mapColumn = 27;
	const int mapRow = 15;
#define F_DARKRED  CLITERAL{ 182, 24, 24, 255 }
#define F_DARKGREEN  CLITERAL{ 24, 182, 24, 255 }
#define F_DARKBLUE  CLITERAL{ 24, 24, 182, 255 } 
	enum GameStage
	{
		MENU, GAME, CREDITS
	};
	extern GameStage gamestatus;
}
#endif

