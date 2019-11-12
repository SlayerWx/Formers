#include "Zone.h"
#include "gameObjects/Plates.h"
#include <iostream>
using namespace std;
Zone::Zone(int newMap[])
{
	for (int i = 0; i < WidthZone; i++)
	{
		for (int j = 0; j < HeightZone; j++)
		{
			zoneElements[i][j] = NULL;
			zoneElements[i][j] = new Plates({ 30.0f*(i+1),30.0f * (j+1) }, circle,BLUE,blue);
			
		}

	}
}

Zone::~Zone()
{
	
}

void Zone::Init() 
{
	

}
void Zone::Update(Vector2 playerPos, Vector2 lastPosition)
{
	for (int i = 0; i < WidthZone; i++)
	{
		for (int j = 0; j < HeightZone; j++)
		{
			if (zoneElements[i][j]->getForm()!=space)
			{
				zoneElements[i][j]->checkCollision(playerPos, lastPosition);
			}	
		}
	}
}
void Zone::Draw()
{
	for (int i = 0; i < WidthZone; i++)
	{
		for (int j = 0; j < HeightZone; j++)
		{
			if (zoneElements[i][j]->getForm() != space)
			{
				zoneElements[i][j]->drawMe();
			}
		}
	}
}