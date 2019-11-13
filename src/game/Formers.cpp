#include "Formers.h"
#include "gameElements/Game.h"
#include "raylib.h"

Formers::Formers()
{
	InitWindow(screenWidth, screenHeight, "Formers v0.1");
	gamestatus = GAME;
	game = new Game();
	inGame = true;
}

Formers::~Formers()
{
	if (game) delete game;
}
void Formers::Play()
{
	while (inGame && !WindowShouldClose())
	{
		Init();
		Update();
		Draw();
	}
}
void Formers::Init()
{
	game->Init();
}
void Formers::Update()
{
	switch (gamestatus)
	{
	case MENU:
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
		break;
	case GAME:
		game->Draw();
		break;
	case CREDITS:
		break;
	}
	EndDrawing();
}