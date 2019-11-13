#include "Formers.h"
#include "gameElements/Game.h"
#include "gameElements/Menu.h"
#include "gameElements/Credits.h"
#include "raylib.h"

Formers::Formers()
{
	InitWindow(screenWidth, screenHeight, "Formers v0.1");
	gamestatus = MENU;
	game = new Game();
	menu = new Menu();
	credits = new Credits();
	inGame = true;
}

Formers::~Formers()
{
	if (game) delete game;
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
		break;
	}
	EndDrawing();
}