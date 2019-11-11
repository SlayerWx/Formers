#ifndef FORMERS_H
#define FORMERS_H
#include "raylib.h"
#include "gameElements/Game.h"
enum GameStage
{
	MENU,GAME,CREDITS
};
class Formers
{
public:
	Formers();
	~Formers();
	void Play();
	const int screenWidth = 810;
	const int screenHeight = 450;
	GameStage gamestatus;
	Game* game;
private:
	void Init();
	void Update();
	void Draw();
	bool inGame;
};
#endif