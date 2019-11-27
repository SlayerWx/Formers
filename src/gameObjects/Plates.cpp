#include "Plates.h"

#include <iostream>

#include "raylib.h"

#include "gameElements/levels/Zone_Structures.h"
#include "gameElements/Global.h"
namespace FormersMJ
{
	Sound Plates::soundPlatesForm;
	using namespace std;

	Plates::Plates(Vector2 Pos, TileType form, Color myNewColor,Texture2D myNewSkin)
		:Zone_Structures(Pos, form, myNewColor,myNewSkin)
	{
		alredyChange = false;
		type = 'P';
	}
	Plates::~Plates()
	{
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
		if (playerPosition.x == myPosition.x - tileScale &&
			playerPosition.y == myPosition.y - tileScale)
		{
			if (alredyChange == false)
			{
				PlaySound(soundPlatesForm);
			}
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