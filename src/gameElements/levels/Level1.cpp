#include "Level1.h"
Level1::Level1()
{
	int a[mapRow][mapColumn]{
		{  1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1},
		{  1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1},
		{  1,   0,   0,   0,   1,   0,  31,   1,   0,   0,  32,   0,   0,   0,   0,  33,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1},
		{  1,   0,   0,   0,   1,   0,   0,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1},
		{  1,   0,   0,   0,   1,   0,   0,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1},
		{  1,   0,   0,   0,   1,   0,   0,   1,   0,   0,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1},
		{  1,   0,   0,   0,   1,   1,  41,   1,   0,   0,  42,   1,   0,   0,   0,  43,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1},
		{  1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1},
		{  1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1},
		{  1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1},
		{  1,   0,   0,   0,   0,   0,  51,   0,   0,   0,  52,   0,   0,   0,   1,  53,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1},
		{  1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1},
		{  1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1},
		{  1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1},
		{  1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1},
	};
	map1 = new Zone(a);
}

Level1::~Level1()
{
}
void Level1::update(Vector2 playerPos, Vector2 lastPosition)
{
	map1->Update(playerPos, lastPosition);
}
void Level1::draw()
{
	map1->Draw();
}