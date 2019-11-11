#include "Game.h"
#include "gameElements/levels/Level1.h"
#include "gameObjects/Plates.h"
#include "gameElements/levels/zones/Zone.h"

#include "gameElements/Global.h"

Game::Game()
{
	player = new Player();
	Lvl1 = new Level1();
	testZone = new Zone();
	testPlate = new Plates({ 105, 75 }, circle, BLUE);
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
	player->move();
	testZone->Update(player->getPosition());

}
void Game::Draw()
{
	player->drawMe();
	testZone->Draw();
	//DrawCircle(testPlate->getPosition().x, testPlate->getPosition().y, WidthAndHeightWorld/2, testPlate->gerColor());
}