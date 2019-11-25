#include "Zone.h"
#include "gameObjects/Plates.h"
#include "gameObjects/Door.h"
#include <iostream>
#include "gameObjects/Player.h"
#include "gameObjects/Wall.h"
#include "gameElements/Global.h"
namespace FormersMJ
{
	using namespace std;
	Zone::Zone(int newMap[mapRow][mapColumn], int maxMovments)
	{
		for (int i = 0; i < 4; i++)
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
					zoneElements[i][j] = new Plates({ tileScale*(j + 1),tileScale * (i + 1) }, vacio, BLUE);
					zoneElements[i][j]->chekable = false;
					zoneElements[i][j]->setType('V');
					zoneElements[i][j]->canPass = true;

					break;
				case wall:
					zoneElements[i][j] = new Wall({ tileScale*(j + 1),tileScale * (i + 1) }, GRAY);
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
					zoneElements[i][j] = new Plates({ tileScale*(j + 1),tileScale * (i + 1) }, circle, F_DARKRED);
					zoneElements[i][j]->setForm(circle);
					zoneElements[i][j]->setColor(F_DARKRED);
					zoneElements[i][j]->chekable = true;
					zoneElements[i][j]->canPass = true;
					break;

				case circleB:
					zoneElements[i][j] = new Plates({ tileScale*(j + 1),tileScale * (i + 1) }, circle, F_DARKBLUE);
					zoneElements[i][j]->setForm(circle);
					zoneElements[i][j]->setColor(F_DARKBLUE);
					zoneElements[i][j]->chekable = true;
					zoneElements[i][j]->canPass = true;
					break;

				case circleG:
					zoneElements[i][j] = new Plates({ tileScale*(j + 1),tileScale * (i + 1) }, circle, F_DARKGREEN);
					zoneElements[i][j]->setForm(circle);
					zoneElements[i][j]->setColor(F_DARKGREEN);
					zoneElements[i][j]->chekable = true;
					zoneElements[i][j]->canPass = true;
					break;

				case rectangleR:
					zoneElements[i][j] = new Plates({ tileScale*(j + 1),tileScale * (i + 1) }, rectangle, F_DARKRED);
					zoneElements[i][j]->setForm(rectangle);
					zoneElements[i][j]->setColor(F_DARKRED);
					zoneElements[i][j]->chekable = true;
					zoneElements[i][j]->canPass = true;
					break;

				case rectangleB:
					zoneElements[i][j] = new Plates({ tileScale*(j + 1),tileScale * (i + 1) }, rectangle, F_DARKBLUE);
					zoneElements[i][j]->setForm(rectangle);
					zoneElements[i][j]->setColor(F_DARKBLUE);
					zoneElements[i][j]->chekable = true;
					zoneElements[i][j]->canPass = true;
					break;

				case rectangleG:
					zoneElements[i][j] = new Plates({ tileScale*(j + 1),tileScale * (i + 1) }, rectangle, F_DARKGREEN);
					zoneElements[i][j]->setForm(rectangle);
					zoneElements[i][j]->setColor(F_DARKGREEN);
					zoneElements[i][j]->chekable = true;
					zoneElements[i][j]->canPass = true;
					break;

				case triangleR:
					zoneElements[i][j] = new Plates({ tileScale*(j + 1),tileScale * (i + 1) }, triangle, F_DARKRED);
					zoneElements[i][j]->setForm(triangle);
					zoneElements[i][j]->setColor(F_DARKRED);
					zoneElements[i][j]->chekable = true;
					zoneElements[i][j]->canPass = true;
					break;

				case triangleB:
					zoneElements[i][j] = new Plates({ tileScale*(j + 1),tileScale * (i + 1) }, triangle, F_DARKBLUE);
					zoneElements[i][j]->setForm(triangle);
					zoneElements[i][j]->setColor(F_DARKBLUE);
					zoneElements[i][j]->chekable = true;
					zoneElements[i][j]->canPass = true;
					break;

				case triangleG:
					zoneElements[i][j] = new Plates({ tileScale*(j + 1),tileScale * (i + 1) }, triangle, F_DARKGREEN);
					zoneElements[i][j]->setForm(triangle);
					zoneElements[i][j]->setColor(F_DARKGREEN);
					zoneElements[i][j]->chekable = true;
					zoneElements[i][j]->canPass = true;
					break;

				case doorCR:
					zoneElements[i][j] = new Door({ tileScale*(j + 1),tileScale * (i + 1) }, circle, F_DARKRED);
					zoneElements[i][j]->setForm(doorC);
					zoneElements[i][j]->setColor(F_DARKRED);
					zoneElements[i][j]->chekable = false;
					zoneElements[i][j]->canPass = false;
					break;

				case doorCB:
					zoneElements[i][j] = new Door({ tileScale*(j + 1),tileScale * (i + 1) }, circle, F_DARKBLUE);
					zoneElements[i][j]->setForm(doorC);
					zoneElements[i][j]->setColor(F_DARKBLUE);
					zoneElements[i][j]->chekable = false;
					zoneElements[i][j]->canPass = false;
					break;

				case doorCG:
					zoneElements[i][j] = new Door({ tileScale*(j + 1),tileScale * (i + 1) }, circle, F_DARKGREEN);
					zoneElements[i][j]->setForm(doorC);
					zoneElements[i][j]->setColor(F_DARKGREEN);
					zoneElements[i][j]->chekable = false;
					zoneElements[i][j]->canPass = false;
					break;

				case doorRR:
					zoneElements[i][j] = new Door({ tileScale*(j + 1),tileScale * (i + 1) }, rectangle, F_DARKRED);
					zoneElements[i][j]->setForm(doorR);
					zoneElements[i][j]->setColor(F_DARKRED);
					zoneElements[i][j]->chekable = false;
					zoneElements[i][j]->canPass = false;
					break;

				case doorRB:
					zoneElements[i][j] = new Door({ tileScale*(j + 1),tileScale * (i + 1) }, rectangle, F_DARKBLUE);
					zoneElements[i][j]->setForm(doorR);
					zoneElements[i][j]->setColor(F_DARKBLUE);
					zoneElements[i][j]->chekable = false;
					zoneElements[i][j]->canPass = false;
					break;

				case doorRG:
					zoneElements[i][j] = new Door({ tileScale*(j + 1),tileScale * (i + 1) }, rectangle, F_DARKGREEN);
					zoneElements[i][j]->setForm(doorR);
					zoneElements[i][j]->setColor(F_DARKGREEN);
					zoneElements[i][j]->chekable = false;
					zoneElements[i][j]->canPass = false;
					break;

				case doorTR:
					zoneElements[i][j] = new Door({ tileScale*(j + 1),tileScale * (i + 1) }, triangle, F_DARKRED);
					zoneElements[i][j]->setForm(doorT);
					zoneElements[i][j]->setColor(F_DARKRED);
					zoneElements[i][j]->chekable = false;
					zoneElements[i][j]->canPass = false;
					break;

				case doorTB:
					zoneElements[i][j] = new Door({ tileScale*(j + 1),tileScale * (i + 1) }, triangle, F_DARKBLUE);
					zoneElements[i][j]->setForm(doorT);
					zoneElements[i][j]->setColor(F_DARKBLUE);
					zoneElements[i][j]->chekable = false;
					zoneElements[i][j]->canPass = false;
					break;

				case doorTG:
					zoneElements[i][j] = new Door({ tileScale*(j + 1),tileScale * (i + 1) }, triangle, F_DARKGREEN);
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

	bool Zone::checkWin()
	{
		bool previousResult = true;
		Zone_Structures* aux1 = NULL;
		Zone_Structures* aux2 = NULL;
		
		
			
		
		

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
						for (int k = 0; k < 4; k++)
						{
							if (doors[k] != NULL)
							{

								if (aux1->getForm() == doors[k]->getForm() &&
									Zone_Structures::compareColor(aux1->getColor(), doors[k]->getColor()))
								{
									doors[k]->canPass = true;
								}
								else
								{
									cout << doors[k]->getForm() << endl;
									previousResult = false;
									doors[k]->canPass = false;
								}
							}
						}
					}
					else
					{
						previousResult = false;
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
					if (zoneElements[i][j]->myType() == 'P')
					{
						zoneElements[i][j]->checkCollision(player->getPosition(), player->getLastPosition());
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
		DrawText(FormatText("win: %i", checkWin()), tileScale * 5, tileScale / 2, tileScale / 2, WHITE);
		system("cls");
		cout << checkWin() << endl;
		DrawText(FormatText("Moves has to be less than: %i", getMaxMoves()), tileScale * 18, tileScale / 2, tileScale / 2, WHITE);
	}

}