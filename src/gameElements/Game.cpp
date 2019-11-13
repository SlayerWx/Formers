#include "Game.h"
#include "gameElements/levels/Level.h"
#include "gameObjects/Plates.h"
#include "gameElements/levels/zones/Zone.h"

#include "gameElements/Global.h"
#include <iostream>

Game::Game()
{
	player = new Player();
	Lvl1 = new Level();
}

Game::~Game()
{
	if(player) delete player;
}
void Game::Init()
{
	//testZone->Init();
}
void Game::Update()
{
	player->input();
	Lvl1->update(player->getPosition(), player->getLastPosition());
	//std::cout << player->getPosition().x << ";" << player->getPosition().y << std::endl;
	//std::cout << player->getLastPosition().x << ";" << player->getLastPosition().y << std::endl;
	player->move();

}
void Game::Draw()
{
	Lvl1->draw();
	player->drawMe();
	//DrawCircle(testPlate->getPosition().x, testPlate->getPosition().y, WidthAndHeightWorld/2, testPlate->gerColor());
}