#include "Formers.h"

#include "raylib.h"

#include "gameElements/Game.h"
#include "gameElements/Menu.h"
#include "gameElements/Credits.h"
#include "gameElements/Global.h"

namespace FormersMJ
{
	Formers::Formers()
	{
		InitWindow(screenWidth, screenHeight, "Formers v0.3");
		InitAudioDevice();
		game = new Game();
		menu = new Menu();
		credits = new Credits();
		inGame = true;
	}

	Formers::~Formers()
	{
		if (game) delete game;
		if (menu) delete menu;
		if (credits) delete credits;
		CloseAudioDevice();
		CloseWindow();
	}
	void Formers::Play()
	{
		Init();
		while (inGame && !WindowShouldClose())
		{

			Update();
			Draw();
		}
	}
	void Formers::Init()
	{
		menu->Init();
		game->Init();
		credits->Init();
		gamestatus = MENU;
	}
	void Formers::Update()
	{
		switch (gamestatus)
		{
		case MENU:
			menu->Update();
			break;
		case GAME:
			if (!firstTime)
			{
				firstTime = true;
				game->Init();
			}
			if (game->Update())
				{
				gamestatus = CREDITS;
				menu->changeIsControlMenu();
				firstTime = false;
				}
			break;
		case CREDITS:
			credits->Update();
			break;
		case EXIT:
			inGame = false;
			break;
		}
	}
	void Formers::Draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);
		switch (gamestatus)
		{
		case MENU:
			menu->Draw();
			break;
		case GAME:
			game->Draw();
			break;
		case CREDITS:
			credits->Draw();
			break;
		}
		EndDrawing();
	}
}