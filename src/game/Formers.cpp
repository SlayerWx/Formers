#include "Formers.h"
#include "gameElements/Game.h"
#include "gameElements/Menu.h"
#include "gameElements/Credits.h"
#include "gameElements/Global.h"
#include "raylib.h"
namespace FormersMJ
{
	Formers::Formers()
	{
		InitWindow(screenWidth, screenHeight, "Formers v0.1");
		game = new Game();
		menu = new Menu();
		credits = new Credits();
		inGame = true;
		InitAudioDevice();
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
			game->Update();
			break;
		case CREDITS:
			credits->Update();
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