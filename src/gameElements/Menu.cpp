#include "Menu.h"
#include "raylib.h"
#include "Global.h"
namespace FormersMJ
{
	Menu::Menu()
	{
		menuSelectorSound = LoadSound("assets/sound/menuSelector.wav");
		titleTexture = LoadTexture("assets/img/Titulo para el menu.png");
		titleTexture.height = titleTexture.height / 2;
		titleTexture.width = titleTexture.width / 2;
		controlsTexture = LoadTexture("assets/img/Controls.png");
		controlsTexture.width = GetScreenWidth();
		controlsTexture.height = GetScreenHeight();

	}

	Menu::~Menu()
	{
		UnloadSound(menuSelectorSound);
		UnloadTexture(titleTexture);
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
				CloseWindow();
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

	void Menu::Draw()
	{
		if (isControlMenu == false)
		{
			DrawTexture(titleTexture, GetScreenWidth() / 2 - titleTexture.width / 2,
				GetScreenHeight() / 5 - titleTexture.height / 2, WHITE);
			switch (actualOption)
			{
			case Play:
				DrawText("Play", tileScale * TEXTDISTANCEINX, tileScale * PLAYTEXTDISTANCEINY, tileScale, YELLOW);
				DrawText("Controls", tileScale * TEXTDISTANCEINX, tileScale * CONTROLESTEXTDISTANCEINY, tileScale, WHITE);
				DrawText("Credits", tileScale * TEXTDISTANCEINX, tileScale * CREDITSTEXTDISTANCEINY, tileScale, WHITE);
				DrawText("Exit", tileScale * TEXTDISTANCEINX, tileScale * EXITTEXTDISTANCEINY, tileScale, WHITE);
				break;

			case Controls:
				DrawText("Play", tileScale * TEXTDISTANCEINX, tileScale * PLAYTEXTDISTANCEINY, tileScale, WHITE);
				DrawText("Controls", tileScale * TEXTDISTANCEINX, tileScale * CONTROLESTEXTDISTANCEINY, tileScale, YELLOW);
				DrawText("Credits", tileScale * TEXTDISTANCEINX, tileScale * CREDITSTEXTDISTANCEINY, tileScale, WHITE);
				DrawText("Exit", tileScale * TEXTDISTANCEINX, tileScale * EXITTEXTDISTANCEINY, tileScale, WHITE);
				break;

			case Credits:
				DrawText("Play", tileScale * TEXTDISTANCEINX, tileScale * PLAYTEXTDISTANCEINY, tileScale, WHITE);
				DrawText("Controls", tileScale * TEXTDISTANCEINX, tileScale * CONTROLESTEXTDISTANCEINY, tileScale, WHITE);
				DrawText("Credits", tileScale * TEXTDISTANCEINX, tileScale * CREDITSTEXTDISTANCEINY, tileScale, YELLOW);
				DrawText("Exit", tileScale * TEXTDISTANCEINX, tileScale * EXITTEXTDISTANCEINY, tileScale, WHITE);
				break;

			case Exit:
				DrawText("Play", tileScale * TEXTDISTANCEINX, tileScale * PLAYTEXTDISTANCEINY, tileScale, WHITE);
				DrawText("Controls", tileScale * TEXTDISTANCEINX, tileScale * CONTROLESTEXTDISTANCEINY, tileScale, WHITE);
				DrawText("Credits", tileScale * TEXTDISTANCEINX, tileScale * CREDITSTEXTDISTANCEINY, tileScale, WHITE);
				DrawText("Exit", tileScale * TEXTDISTANCEINX, tileScale * EXITTEXTDISTANCEINY, tileScale, YELLOW);
				break;
			default:
				break;
			}
		}
		else
		{
			DrawTexture(controlsTexture,0,0, WHITE);
		}
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