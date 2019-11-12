#include "Zone.h"
#include "gameObjects/Plates.h"
#include <iostream>
using namespace std;
Zone::Zone(int newMap[mapRow][mapColumn])
{
	for (int i = 0; i < mapRow; i++)
	{
		for (int j = 0; j < mapColumn; j++)
		{
			zoneElements[i][j] = NULL;
			zoneElements[i][j] = new Plates({ 30.0f*(j + 1),30.0f * (i+1 ) }, circle, BLUE, blue);

		}

	}
	for (int i = 0; i < mapRow; i++)
	{
		for (int j = 0; j < mapColumn; j++)
		{
			switch (newMap[i][j])
			{
			case 0:
				zoneElements[i][j]->setForm(vacio);
				
				break;
			case 1:
				zoneElements[i][j]->setForm(rectangle);
				zoneElements[i][j]->setColor(gray);
				break;
			case 2:
				
				break;
			default:
				break;
			}
			/*
			zoneElements[0][j]->setColor(gray);
			zoneElements[i][0]->setColor(gray);
			zoneElements[widthZone - 1][j]->setColor(gray);
			zoneElements[i][heightZone - 1]->setColor(gray);

			zoneElements[i-1][6]->setForm(space);
			zoneElements[i-1][8]->setForm(space);

			zoneElements[0][j]->setForm(rectangle);
			zoneElements[i][0]->setForm(rectangle);
			zoneElements[widthZone - 1][j]->setForm(rectangle);
			zoneElements[i][heightZone - 1]->setForm(rectangle);
			*/
			
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
	for (int i = 0; i < mapRow; i++)
	{
		for (int j = 0; j < mapColumn; j++)
		{
			if (zoneElements[i][j]->getForm()!=vacio)
			{
				zoneElements[i][j]->checkCollision(playerPos, lastPosition);
			}	
		}
	}
}
void Zone::Draw()
{
	for (int i = 0; i < mapRow; i++)
	{
		for (int j = 0; j < mapColumn; j++)
		{
			if (zoneElements[i][j]->getForm() != vacio)
			{
				zoneElements[i][j]->drawMe();
			}
		}
	}
}