#include "Zone.h"
#include "gameObjects/Plates.h"
#include <iostream>
using namespace std;
Zone::Zone()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			zonePlates[i][j] = new Plates({ (30.0f + (30.0f*(i+1))),(30.0f + (30.0f * (j+1))) }, circle,BLUE);
			
		}

	}
	zonePlates[3][3]->setActive();
}

Zone::~Zone()
{
	
}

void Zone::Init() 
{
	

}
void Zone::Update(Vector2 playerPos)
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (zonePlates[i][j]->getActive())
			{
				zonePlates[i][j]->checkCollision(playerPos, WidthAndHeightWorld, WidthAndHeightWorld);
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
			if (zonePlates[i][j]->getActive())
			{
			zonePlates[i][j]->drawMe();
			}
		}
	}
}