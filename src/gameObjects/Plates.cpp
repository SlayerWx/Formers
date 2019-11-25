#include "Plates.h"
#include <iostream>
#include "gameElements/levels/Zone_Structures.h"
#include "raylib.h"
#include "gameElements/Global.h"
namespace FormersMJ
{
	using namespace std;
	Plates::Plates()
	{
		alredyChange = false;
		type = 'P';
	}
	
	Plates::~Plates()
	{
	}

	Plates::Plates(Vector2 Pos, TileType form, Color myNewColor)
		:Zone_Structures(Pos, form, myNewColor)
	{
		alredyChange = false;
		type = 'P';
	}

	void Plates::setAlredyChange(bool newRedyChange)
	{
		alredyChange = newRedyChange;
	}
	bool Plates::getAlredyChange()
	{
		return alredyChange;
	}
	void Plates::checkCollision(Vector2 playerPosition, Vector2 lastPosition)
	{
		if (playerPosition.x == myPosition.x - 30.0f &&
			playerPosition.y == myPosition.y - 30.0f)
		{
			if (playerPosition.x == lastPosition.x)
			{
				switch (getForm())
				{

				case circle:
					if (alredyChange == false)
					{
						setForm(rectangle);
						alredyChange = true;
						playerPosition.x = tileScale;
					}

					break;
				case rectangle:
					if (alredyChange == false)
					{
						setForm(triangle);
						alredyChange = true;
					}
					break;
				case triangle:

					if (alredyChange == false)
					{
						setForm(circle);
						alredyChange = true;
					}
					break;
				default:
					break;
				}

			}
			else
			{
				
					if(Zone_Structures::compareColor(myColor, F_DARKRED) && alredyChange == false)
					{
						setColor(F_DARKBLUE);
						alredyChange = true;
					}
					if (Zone_Structures::compareColor(myColor, F_DARKBLUE) && alredyChange == false)
					{
						setColor(F_DARKGREEN);
						alredyChange = true;
					}
					if (Zone_Structures::compareColor(myColor, F_DARKGREEN) && alredyChange == false)
					{
						setColor(F_DARKRED);
						alredyChange = true;
					}
					
				
			}

		}
		else
		{
			alredyChange = false;
		}
	}



}