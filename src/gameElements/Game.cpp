#include "Game.h"
#include "gameElements/levels/Level1.h"
#include "gameObjects/Plates.h"
#include "gameElements/levels/zones/Zone.h"

#include "gameElements/Global.h"
#include <iostream>

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
	player->drawMe();
	Lvl1->draw();
	//DrawCircle(testPlate->getPosition().x, testPlate->getPosition().y, WidthAndHeightWorld/2, testPlate->gerColor());
}