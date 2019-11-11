#include "Level1.h"
Level1::Level1()
{
	map1 = new Zone();
}

Level1::~Level1()
{
}
void Level1::update(Vector2 playerPos)
{
	map1->Update(playerPos);
}
void Level1::draw()
{
	map1->Draw();
}