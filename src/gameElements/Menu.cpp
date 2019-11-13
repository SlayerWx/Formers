#include "Menu.h"
#include "raylib.h"
#include "Global.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::Init()
{
	actualOption = Play;
}

void Menu::Input()
{
	if (IsKeyReleased(KEY_W))
	{
		if (actualOption == Play)
		{
			actualOption = Exit;
		}
		else
		{
			actualOption--;
		}
	}
	if (IsKeyReleased(KEY_S))
	{
		if (actualOption == Exit)
		{
			actualOption = Play;
		}
		else
		{
			actualOption++;
		}
	}
}

void Menu::Update()
{
	Input();

}

void Menu::Draw()
{
	switch (actualOption)
	{
	case Play:
		DrawText("Play", tileScale*2, tileScale*6, tileScale,YELLOW);
		DrawText("Controls", tileScale * 2, tileScale * 8, tileScale, WHITE);
		DrawText("Credits", tileScale * 2, tileScale * 10, tileScale, WHITE);
		DrawText("Exit", tileScale * 2, tileScale * 12, tileScale, WHITE);
		break;

	case Controls:
		DrawText("Play", tileScale * 2, tileScale * 6, tileScale, WHITE);
		DrawText("Controls", tileScale * 2, tileScale * 8, tileScale, YELLOW);
		DrawText("Credits", tileScale * 2, tileScale * 10, tileScale, WHITE);
		DrawText("Exit", tileScale * 2, tileScale * 12, tileScale, WHITE);
		break;

	case Credits:
		DrawText("Play", tileScale * 2, tileScale * 6, tileScale, WHITE);
		DrawText("Controls", tileScale * 2, tileScale * 8, tileScale, WHITE);
		DrawText("Credits", tileScale * 2, tileScale * 10, tileScale, YELLOW);
		DrawText("Exit", tileScale * 2, tileScale * 12, tileScale, WHITE);
		break;

	case Exit:
		DrawText("Play", tileScale * 2, tileScale * 6, tileScale, WHITE);
		DrawText("Controls", tileScale * 2, tileScale * 8, tileScale, WHITE);
		DrawText("Credits", tileScale * 2, tileScale * 10, tileScale, WHITE);
		DrawText("Exit", tileScale * 2, tileScale * 12, tileScale, YELLOW);
		break;
	default:
		break;
	}
}
