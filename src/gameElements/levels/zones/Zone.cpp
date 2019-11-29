#include "Zone.h"
#include <iostream>
#include "raylib.h"
#include "gameElements/levels/Zone_Structures.h"
#include "gameElements/Global.h"
#include "gameObjects/Plates.h"
#include "gameObjects/Door.h"
#include "gameObjects/Player.h"
#include "gameObjects/Wall.h"
#include "gameElements/Global.h"

namespace FormersMJ
{
	using namespace std;
	Zone::Zone(int newMap[mapRow][mapColumn], int maxMovments)
	{
		isFinish = false;
		for (int i = 0; i < MAXDOORS; i++)
		{
			doors[i] = { NULL };
		}
		
		for (int i = 0; i < mapRow; i++)
		{
			for (int j = 0; j < mapColumn; j++)
			{
				zoneElements[i][j] = NULL;
				
				maxMoves = maxMovments;
			}

		}
		for (int i = 0; i < mapRow; i++)
		{
			for (int j = 0; j < mapColumn; j++)
			{
				switch (newMap[i][j])
				{
				case vacio:
					zoneElements[i][j] = new Plates({ tileScale*(j + SCALEDIF),tileScale * (i + SCALEDIF) }, vacio, BLUE, Global::WallSkin);
					zoneElements[i][j]->chekable = false;
					zoneElements[i][j]->setType('V');
					zoneElements[i][j]->canPass = true;

					break;
				case wall:
					zoneElements[i][j] = new Wall({ tileScale*(j + 1),tileScale * (i + SCALEDIF) }, GRAY, Global::WallSkin);
					zoneElements[i][j]->setForm(wall);
					zoneElements[i][j]->setColor(GRAY);
					zoneElements[i][j]->chekable = false;
					zoneElements[i][j]->canPass = true;
					break;
				case door:
					zoneElements[i][j]->chekable = false;
					zoneElements[i][j]->canPass = false;
					break;

				case circleR:
					zoneElements[i][j] = new Plates({ tileScale*(j + SCALEDIF),tileScale * (i + SCALEDIF) }, circle, F_DARKRED, Global::WallSkin);
					zoneElements[i][j]->setForm(circle);
					zoneElements[i][j]->setColor(F_DARKRED);
					zoneElements[i][j]->chekable = true;
					zoneElements[i][j]->canPass = true;
					break;

				case circleB:
					zoneElements[i][j] = new Plates({ tileScale*(j + SCALEDIF),tileScale * (i + SCALEDIF) }, circle, F_DARKBLUE, Global::WallSkin);
					zoneElements[i][j]->setForm(circle);
					zoneElements[i][j]->setColor(F_DARKBLUE);
					zoneElements[i][j]->chekable = true;
					zoneElements[i][j]->canPass = true;
					break;

				case circleG:
					zoneElements[i][j] = new Plates({ tileScale*(j + SCALEDIF),tileScale * (i + SCALEDIF) }, circle, F_DARKGREEN, Global::WallSkin);
					zoneElements[i][j]->setForm(circle);
					zoneElements[i][j]->setColor(F_DARKGREEN);
					zoneElements[i][j]->chekable = true;
					zoneElements[i][j]->canPass = true;
					break;

				case rectangleR:
					zoneElements[i][j] = new Plates({ tileScale*(j + SCALEDIF),tileScale * (i + SCALEDIF) }, rectangle, F_DARKRED, Global::WallSkin);
					zoneElements[i][j]->setForm(rectangle);
					zoneElements[i][j]->setColor(F_DARKRED);
					zoneElements[i][j]->chekable = true;
					zoneElements[i][j]->canPass = true;
					break;

				case rectangleB:
					zoneElements[i][j] = new Plates({ tileScale*(j + SCALEDIF),tileScale * (i + SCALEDIF) }, rectangle, F_DARKBLUE, Global::WallSkin);
					zoneElements[i][j]->setForm(rectangle);
					zoneElements[i][j]->setColor(F_DARKBLUE);
					zoneElements[i][j]->chekable = true;
					zoneElements[i][j]->canPass = true;
					break;

				case rectangleG:
					zoneElements[i][j] = new Plates({ tileScale*(j + SCALEDIF),tileScale * (i + SCALEDIF) }, rectangle, F_DARKGREEN, Global::WallSkin);
					zoneElements[i][j]->setForm(rectangle);
					zoneElements[i][j]->setColor(F_DARKGREEN);
					zoneElements[i][j]->chekable = true;
					zoneElements[i][j]->canPass = true;
					break;

				case triangleR:
					zoneElements[i][j] = new Plates({ tileScale*(j + SCALEDIF),tileScale * (i + SCALEDIF) }, triangle, F_DARKRED, Global::WallSkin);
					zoneElements[i][j]->setForm(triangle);
					zoneElements[i][j]->setColor(F_DARKRED);
					zoneElements[i][j]->chekable = true;
					zoneElements[i][j]->canPass = true;
					break;

				case triangleB:
					zoneElements[i][j] = new Plates({ tileScale*(j + SCALEDIF),tileScale * (i + SCALEDIF) }, triangle, F_DARKBLUE, Global::WallSkin);
					zoneElements[i][j]->setForm(triangle);
					zoneElements[i][j]->setColor(F_DARKBLUE);
					zoneElements[i][j]->chekable = true;
					zoneElements[i][j]->canPass = true;
					break;

				case triangleG:
					zoneElements[i][j] = new Plates({ tileScale*(j + SCALEDIF),tileScale * (i + SCALEDIF) }, triangle, F_DARKGREEN, Global::WallSkin);
					zoneElements[i][j]->setForm(triangle);
					zoneElements[i][j]->setColor(F_DARKGREEN);
					zoneElements[i][j]->chekable = true;
					zoneElements[i][j]->canPass = true;
					break;

				case doorCR:
					zoneElements[i][j] = new Door({ tileScale*(j + SCALEDIF),tileScale * (i + SCALEDIF) }, circle, F_DARKRED, Global::WallSkin);
					zoneElements[i][j]->setForm(doorC);
					zoneElements[i][j]->setColor(F_DARKRED);
					zoneElements[i][j]->chekable = false;
					zoneElements[i][j]->canPass = false;
					break;

				case doorCB:
					zoneElements[i][j] = new Door({ tileScale*(j + SCALEDIF),tileScale * (i + SCALEDIF) }, circle, F_DARKBLUE, Global::WallSkin);
					zoneElements[i][j]->setForm(doorC);
					zoneElements[i][j]->setColor(F_DARKBLUE);
					zoneElements[i][j]->chekable = false;
					zoneElements[i][j]->canPass = false;
					break;

				case doorCG:
					zoneElements[i][j] = new Door({ tileScale*(j + SCALEDIF),tileScale * (i + SCALEDIF) }, circle, F_DARKGREEN, Global::WallSkin);
					zoneElements[i][j]->setForm(doorC);
					zoneElements[i][j]->setColor(F_DARKGREEN);
					zoneElements[i][j]->chekable = false;
					zoneElements[i][j]->canPass = false;
					break;

				case doorRR:
					zoneElements[i][j] = new Door({ tileScale*(j + SCALEDIF),tileScale * (i + SCALEDIF) }, rectangle, F_DARKRED, Global::WallSkin);
					zoneElements[i][j]->setForm(doorR);
					zoneElements[i][j]->setColor(F_DARKRED);
					zoneElements[i][j]->chekable = false;
					zoneElements[i][j]->canPass = false;
					break;

				case doorRB:
					zoneElements[i][j] = new Door({ tileScale*(j + SCALEDIF),tileScale * (i + SCALEDIF) }, rectangle, F_DARKBLUE, Global::WallSkin);
					zoneElements[i][j]->setForm(doorR);
					zoneElements[i][j]->setColor(F_DARKBLUE);
					zoneElements[i][j]->chekable = false;
					zoneElements[i][j]->canPass = false;
					break;

				case doorRG:
					zoneElements[i][j] = new Door({ tileScale*(j + SCALEDIF),tileScale * (i + SCALEDIF) }, rectangle, F_DARKGREEN, Global::WallSkin);
					zoneElements[i][j]->setForm(doorR);
					zoneElements[i][j]->setColor(F_DARKGREEN);
					zoneElements[i][j]->chekable = false;
					zoneElements[i][j]->canPass = false;
					break;

				case doorTR:
					zoneElements[i][j] = new Door({ tileScale*(j + SCALEDIF),tileScale * (i + SCALEDIF) }, triangle, F_DARKRED, Global::WallSkin);
					zoneElements[i][j]->setForm(doorT);
					zoneElements[i][j]->setColor(F_DARKRED);
					zoneElements[i][j]->chekable = false;
					zoneElements[i][j]->canPass = false;
					break;

				case doorTB:
					zoneElements[i][j] = new Door({ tileScale*(j + SCALEDIF),tileScale * (i + SCALEDIF) }, triangle, F_DARKBLUE, Global::WallSkin);
					zoneElements[i][j]->setForm(doorT);
					zoneElements[i][j]->setColor(F_DARKBLUE);
					zoneElements[i][j]->chekable = false;
					zoneElements[i][j]->canPass = false;
					break;

				case doorTG:
					zoneElements[i][j] = new Door({ tileScale*(j + SCALEDIF),tileScale * (i + SCALEDIF) }, triangle, F_DARKGREEN, Global::WallSkin);
					zoneElements[i][j]->setForm(doorT);
					zoneElements[i][j]->setColor(F_DARKGREEN);
					zoneElements[i][j]->chekable = false;
					zoneElements[i][j]->canPass = false;
					break;
				default:
					break;
				}
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

	void Zone::checkWin()
	{
		Zone_Structures* aux1 = NULL;
		Zone_Structures* aux2 = NULL;
		isFinish = false;
		for (int i = 0; i < mapRow; i++)
		{
			for (int j = 0; j < mapColumn; j++)
			{
				if (zoneElements[i][j]->myType() == 'P')
				{
					if (aux1 == NULL)
					{
						aux1 = zoneElements[i][j];
					}
					aux2 = zoneElements[i][j];


					if (aux1->getForm() == aux2->getForm() &&
						Zone_Structures::compareColor(aux1->getColor(), aux2->getColor()))
					{
						for (int k = 0; k < MAXDOORS; k++)
						{
							if (doors[k] != NULL)
							{
								TileType door = doors[k]->getForm();
								if (door == doorC) door = circle;
								if (door == doorR) door = rectangle;
								if (door == doorT) door = triangle;


								if (aux1->getForm() == door &&
									Zone_Structures::compareColor(aux1->getColor(), doors[k]->getColor()))
								{
									doors[k]->canPass = true;
									isFinish = true;
								}
								else
								{
									doors[k]->canPass = false;
								}
							}
						}
					}
				}
				if (zoneElements[i][j]->myType() == 'D')
				{
					if (doors[0] == NULL)
					{
						doors[0] = static_cast <Door*>(zoneElements[i][j]);
					}
					else if (doors[1] == NULL)
					{
						doors[1] = static_cast <Door*>(zoneElements[i][j]);
					}
					else if (doors[2] == NULL)
					{
						doors[2] = static_cast <Door*>(zoneElements[i][j]);
					}
					else if (doors[3] == NULL)
					{
						doors[3] = static_cast <Door*>(zoneElements[i][j]);
					}
				}
			}
		}
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
		checkWin();
		for (int i = 0; i < mapRow; i++)
		{
			for (int j = 0; j < mapColumn; j++)
			{
				if (zoneElements[i][j]->getForm() != vacio)
				{
					if (zoneElements[i][j]->myType() == 'P')
					{
						if(player->getMoves() <= maxMoves )
						{
						zoneElements[i][j]->checkCollision(player->getPosition(), player->getLastPosition());
						}
					}
					else if (zoneElements[i][j]->myType() == 'W')
					{
						if (zoneElements[i][j]->getPosition().x - tileScale == player->getNextPos().x &&
							zoneElements[i][j]->getPosition().y - tileScale == player->getNextPos().y)
						{
							player->setStopAtion(true);
							player->stopMyAction();
						}

					}
					else if(zoneElements[i][j]->myType() == 'D')
					{
						static_cast<Door*>(zoneElements[i][j])->setOpen(true);
						if (zoneElements[i][j]->getPosition().x - tileScale == player->getNextPos().x &&
							zoneElements[i][j]->getPosition().y - tileScale == player->getNextPos().y &&
							zoneElements[i][j]->canPass == false)
						{
							player->setStopAtion(true);
							player->stopMyAction();
						}
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
		DrawText(FormatText("Moves has to be less than: %i", getMaxMoves()), static_cast<int>(tileScale * 18), static_cast<int>(tileScale / 2), static_cast<int>(tileScale / 2), WHITE);
	}

}