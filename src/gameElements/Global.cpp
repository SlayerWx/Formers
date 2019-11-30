#include "Global.h"
namespace FormersMJ
{
	Sound Global::mySoundDoor;
	Texture2D Global::WallSkin;
	GameStage gamestatus = MENU;		
	Texture2D Global::doorCircleTexture;
	Texture2D Global::doorRectangleTexture;
	Texture2D Global::doorTriangleTexture;
	float Global::volume = 0.20f;

	Global::Global()
	{
	}

	Global::~Global()
	{
	}
}