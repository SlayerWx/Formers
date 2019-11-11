#include "Game.h"
#include "gameElements/levels/Level1.h"
#include "gameObjects/Plates.h"

Game::Game()
{
	player = new Player();
	Lvl1 = new Level1();
}

Game::~Game()
{
	if(player) delete player;
}
void Game::Init()
{

}
void Game::Update()
{
	player->input();
	player->move();
}
void Game::Draw()
{
	player->drawMe();
}