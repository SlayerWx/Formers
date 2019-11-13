#include "Credits.h"
#include "raylib.h"
#include "Global.h"
namespace FormersMJ
{
	Credits::Credits()
	{
	}

	Credits::~Credits()
	{
	}
	void Credits::Init()
	{
	}
	void Credits::Input()
	{
		if (IsKeyReleased(KEY_ENTER))
		{
			gamestatus = MENU;
		}
	}
	void Credits::Update()
	{
		Input();
	}
	void Credits::Draw()
	{
		DrawText("Credits", tileScale * 2, tileScale * 10, tileScale, WHITE);
	}
}