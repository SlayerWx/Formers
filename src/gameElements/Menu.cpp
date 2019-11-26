#include "Menu.h"
#include "raylib.h"
#include "Global.h"
namespace FormersMJ
{
	Menu::Menu()
	{
		menuSelectorSound = LoadSound("res/sound/menuSelector.wav");
	}

	Menu::~Menu()
	{
		UnloadSound(menuSelectorSound);
	}

	void Menu::Init()
	{
		actualOption = Play;
		isControlMenu = false;
	}

	void Menu::Input()
	{
		if (IsKeyReleased(KEY_W))
		{

			PlaySound(menuSelectorSound);

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

			PlaySound(menuSelectorSound);

			if (actualOption == Exit)
			{
				actualOption = Play;
			}
			else
			{
				actualOption++;
			}
		}
		if (IsKeyReleased(KEY_ENTER))
		{
			if (isControlMenu == false)
			{
				switch (actualOption)
				{
				case Play:
					gamestatus = GAME;
					StopSound(menuSelectorSound);
				case Controls:
					isControlMenu = true;
					break;

				case Credits:
					gamestatus = CREDITS;
					break;

				case Exit:

					break;
				default:
					break;
				}
			}
			else
			{
				changeIsControlMenu();
			}
		}
	}

	void Menu::Update()
	{
		Input();

	}

	void Menu::UpdateControlsMenu()
	{
	}

	void Menu::Draw()
	{
		if (isControlMenu == false)
		{
			switch (actualOption)
			{
			case Play:
				DrawText("Play", tileScale * 2, tileScale * 6, tileScale, YELLOW);
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
		else
		{
			DrawText("Controls", tileScale * 6, tileScale * 2, tileScale, WHITE);
		}
	}

	void Menu::DrawControlsMenu()
	{
	}

	bool Menu::getIsControlMenu()
	{
		return isControlMenu;
	}

	void Menu::changeIsControlMenu()
	{
		isControlMenu = !isControlMenu;
	}

}