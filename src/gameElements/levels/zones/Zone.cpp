#include "Zone.h"
#include "gameObjects/Plates.h"
#include "gameObjects/Player.h"
#include <iostream>
using namespace std;
Zone::Zone()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			zonePlates[i][j] = new Plates({ (15.0f + (30.0f*i)),(15.0f + (30.0f * j)) }, circle,RED);
		}
	}
}

Zone::~Zone()
{
	
}

void Zone::Init() 
{
	/*for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			cantPlates[i][j]->init(TILE1X1,circle,RED);
		}
	}*/
}
void Zone::Update(Vector2 playerPos)
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (zonePlates[i][j]->checkCollision(playerPos, WidthAndHeightWorld, WidthAndHeightWorld))
			{
				zonePlates[i][j]->setForm(rectangle);
				cout << "Colision" << endl;
			}
		}
	}
}
void Zone::Draw()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			zonePlates[i][j]->drawMe();
		}
	}
}