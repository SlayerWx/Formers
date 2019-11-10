#include "Game.h"

Game::Game()
{
	player = new Player();
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