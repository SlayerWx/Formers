#include "Zone.h"
#include "gameObjects/Plates.h"
#include <iostream>
#include "gameObjects/Player.h"
namespace FormersMJ
{
	using namespace std;
	Zone::Zone(int newMap[mapRow][mapColumn])
	{
		for (int i = 0; i < mapRow; i++)
		{
			for (int j = 0; j < mapColumn; j++)
			{
				zoneElements[i][j] = NULL;
				zoneElements[i][j] = new Plates({ tileScale*(j + 1),tileScale * (i + 1) }, circle, BLUE, blue, newMap[i][j]);
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
					zoneElements[i][j]->chekable = false;

					break;
				case wall:
					zoneElements[i][j]->setForm(wall);
					zoneElements[i][j]->setColor(gray);
					zoneElements[i][j]->color = gray;
					zoneElements[i][j]->chekable = false;
					break;
				case door:
					zoneElements[i][j]->chekable = false;
					break;

				case circleR:
					zoneElements[i][j]->setForm(circle);
					zoneElements[i][j]->setColor(red);
					zoneElements[i][j]->color = red;
					zoneElements[i][j]->chekable = true;
					break;

				case circleB:
					zoneElements[i][j]->setForm(circle);
					zoneElements[i][j]->setColor(blue);
					zoneElements[i][j]->color = blue;
					zoneElements[i][j]->chekable = true;
					break;

				case circleG:
					zoneElements[i][j]->setForm(circle);
					zoneElements[i][j]->setColor(green);
					zoneElements[i][j]->color = green;
					zoneElements[i][j]->chekable = true;
					break;

				case rectangleR:
					zoneElements[i][j]->setForm(rectangle);
					zoneElements[i][j]->setColor(red);
					zoneElements[i][j]->color = red;
					zoneElements[i][j]->chekable = true;
					break;

				case rectangleB:
					zoneElements[i][j]->setForm(rectangle);
					zoneElements[i][j]->setColor(blue);
					zoneElements[i][j]->color = blue;
					zoneElements[i][j]->chekable = true;
					break;

				case rectangleG:
					zoneElements[i][j]->setForm(rectangle);
					zoneElements[i][j]->setColor(green);
					zoneElements[i][j]->color = green;
					zoneElements[i][j]->chekable = true;
					break;

				case triangleR:
					zoneElements[i][j]->setForm(triangle);
					zoneElements[i][j]->setColor(red);
					zoneElements[i][j]->color = red;
					zoneElements[i][j]->chekable = true;
					break;

				case triangleB:
					zoneElements[i][j]->setForm(triangle);
					zoneElements[i][j]->setColor(blue);
					zoneElements[i][j]->color = blue;
					zoneElements[i][j]->chekable = true;
					break;

				case triangleG:
					zoneElements[i][j]->setForm(triangle);
					zoneElements[i][j]->setColor(green);
					zoneElements[i][j]->color = green;
					zoneElements[i][j]->chekable = true;
					break;

				case doorCR:
					zoneElements[i][j]->setForm(doorC);
					zoneElements[i][j]->setColor(red);
					zoneElements[i][j]->color = red;
					zoneElements[i][j]->chekable = false;
					break;

				case doorCB:
					zoneElements[i][j]->setForm(doorC);
					zoneElements[i][j]->setColor(blue);
					zoneElements[i][j]->color = blue;
					zoneElements[i][j]->chekable = false;
					break;

				case doorCG:
					zoneElements[i][j]->setForm(doorC);
					zoneElements[i][j]->setColor(green);
					zoneElements[i][j]->color = green;
					zoneElements[i][j]->chekable = false;
					break;

				case doorRR:
					zoneElements[i][j]->setForm(doorR);
					zoneElements[i][j]->setColor(red);
					zoneElements[i][j]->color = red;
					zoneElements[i][j]->chekable = false;
					break;

				case doorRB:
					zoneElements[i][j]->setForm(doorR);
					zoneElements[i][j]->setColor(blue);
					zoneElements[i][j]->color = blue;
					zoneElements[i][j]->chekable = false;
					break;

				case doorRG:
					zoneElements[i][j]->setForm(doorR);
					zoneElements[i][j]->setColor(green);
					zoneElements[i][j]->color = green;
					zoneElements[i][j]->chekable = false;
					break;

				case doorTR:
					zoneElements[i][j]->setForm(doorT);
					zoneElements[i][j]->setColor(red);
					zoneElements[i][j]->color = red;
					zoneElements[i][j]->chekable = false;
					break;

				case doorTB:
					zoneElements[i][j]->setForm(doorT);
					zoneElements[i][j]->setColor(blue);
					zoneElements[i][j]->color = blue;
					zoneElements[i][j]->chekable = false;
					break;

				case doorTG:
					zoneElements[i][j]->setForm(doorT);
					zoneElements[i][j]->setColor(green);
					zoneElements[i][j]->color = green;
					zoneElements[i][j]->chekable = false;
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
		for (int i = 0; i < mapRow; i++)
		{
			for (int j = 0; j < mapColumn; j++)
			{
				if(zoneElements[i][j])
				delete zoneElements[i][j];
			}

		}
	}

	bool Zone::checkWin()
	{
		bool previousResult = true;
		for (int i = 0;i< mapRow;i++)
		{
			for (int j = 0; j < mapColumn-1; j++)
			{
				if (zoneElements[i][j]->myType() == 'P') {
					if (previousResult && zoneElements[i][j]->getForm() == zoneElements[i][j + 1]->getForm() &&
						zoneElements[i][j]->color == zoneElements[i][j + 1]->color)
					{
						previousResult = true;
					}
					else
					{
						previousResult = false;
					}
				}
			}
		}
		return previousResult;
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
					if (zoneElements[i][j]->getForm() == wall || zoneElements[i][j]->getForm() == doorC || zoneElements[i][j]->getForm() == doorT || zoneElements[i][j]->getForm() == doorR)
					{
						if (zoneElements[i][j]->getPosition().x - tileScale == player->getNextPos().x &&
							zoneElements[i][j]->getPosition().y - tileScale == player->getNextPos().y)
						{
							player->setStopAtion(true);
							player->stopMyAction();
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
		DrawText(FormatText("win: %i", checkWin()), tileScale * 5, tileScale / 2, tileScale / 2, WHITE);
		system("cls");
		cout << checkWin() << endl;
		DrawText(FormatText("Moves has to be less than: %i", getMaxMoves()), tileScale * 10, tileScale / 2, tileScale / 2, WHITE);
	}

	/*Zone_Structures * Zone::GetZoneStructureById(int id)
	{
		for (int i = 0; i < mapRow; i++)
		{
			for (int j = 0; j < mapColumn; j++)
			{
				if (zoneElements[i][j]->GetZone()->id == id)
				{
					return zoneElements[i][j]->GetZone();
				}
			}
		}
		return nullptr;
	}*/
}