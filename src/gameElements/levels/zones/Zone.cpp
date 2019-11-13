#include "Zone.h"
#include "gameObjects/Plates.h"
#include <iostream>
#include "gameObjects/Player.h"
using namespace std;
Zone::Zone(int newMap[mapRow][mapColumn])
{
	for (int i = 0; i < mapRow; i++)
	{
		for (int j = 0; j < mapColumn; j++)
		{
			zoneElements[i][j] = NULL;
			zoneElements[i][j] = new Plates({ tileScale*(j + 1),tileScale * (i+1 ) }, circle, BLUE, blue);
			maxMoves = 60;
		}

	}
	for (int i = 0; i < mapRow; i++)
	{
		for (int j = 0; j < mapColumn; j++)
		{
			switch (newMap[i][j])
			{
			case vacio:
				zoneElements[i][j]->setForm(vacio);
				
				break;
			case wall:
				zoneElements[i][j]->setForm(wall);
				zoneElements[i][j]->setColor(gray);
				break;
			case door:
				
				break;

			case circleR:
				zoneElements[i][j]->setForm(circle);
				zoneElements[i][j]->setColor(red);
				break;

			case circleB:
				zoneElements[i][j]->setForm(circle);
				zoneElements[i][j]->setColor(blue);
				break;

			case circleG:
				zoneElements[i][j]->setForm(circle);
				zoneElements[i][j]->setColor(green);
				break;

			case rectangleR:
				zoneElements[i][j]->setForm(rectangle);
				zoneElements[i][j]->setColor(red);
				break;

			case rectangleB:
				zoneElements[i][j]->setForm(rectangle);
				zoneElements[i][j]->setColor(blue);
				break;

			case rectangleG:
				zoneElements[i][j]->setForm(rectangle);
				zoneElements[i][j]->setColor(green);
				break;

			case triangleR:
				zoneElements[i][j]->setForm(triangle);
				zoneElements[i][j]->setColor(red);
				break;

			case triangleB:
				zoneElements[i][j]->setForm(triangle);
				zoneElements[i][j]->setColor(blue);
				break;

			case triangleG:
				zoneElements[i][j]->setForm(triangle);
				zoneElements[i][j]->setColor(green);
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

bool Zone::checkWin()
{
	int testIfSame = 0;
	bool wins = true;
	for (int i = 0; i < mapRow; i++)
	{
		for (int j = 0; j < mapColumn; j++)
		{
			if (zoneElements[i][j]->getForm() != vacio && zoneElements[i][j]->getForm() != wall)
			{
				testIfSame = zoneElements[i][j]->getForm();

				for (int k = 0; k < mapRow; k++)
				{
					for (int l = 0; l < mapColumn; l++)
					{
						if (testIfSame != zoneElements[k][l]->getForm() && zoneElements[k][l]->getForm() != vacio && zoneElements[k][l]->getForm() != wall)
						{
							//necesito agarrar la cantidad de movimientos que va y compararlo con maxMoves
							wins = false;
						}
					}
				}
			}
		}
	}
	return wins;
}

int Zone::getMaxMoves()
{
	return maxMoves;
}

void Zone::Init() 
{
	

}
void Zone::Update(Player* player)
{
	for (int i = 0; i < mapRow; i++)
	{
		for (int j = 0; j < mapColumn; j++)
		{
			if (zoneElements[i][j]->getForm() != vacio)
			{
				if (zoneElements[i][j]->getForm()== wall)
				{
					if (zoneElements[i][j]->getPosition().x == player->getPosition().x &&
						zoneElements[i][j]->getPosition().y == player->getPosition().y)
					{

					}
				}
				else 
				{
					zoneElements[i][j]->checkCollision(player->getPosition(), player->getLastPosition());
				}
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
	DrawText(FormatText("win: %i", checkWin()), tileScale*5, tileScale / 2, tileScale / 2, WHITE);

	DrawText(FormatText("Moves has to be less than: %i", getMaxMoves()) , tileScale * 10, tileScale / 2, tileScale / 2, WHITE);
}