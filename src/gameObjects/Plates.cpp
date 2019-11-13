#include "Plates.h"
#include <iostream>
#include "raylib.h"
using namespace std;
Plates::Plates()
{
	alredyChange = false;
}
/*
void Plates::init(Vector2 Pos, Form form, Color myColor)
{
	Plates(Pos, form, myColor);
}*/
Plates::~Plates()
{
}

Plates::Plates(Vector2 Pos, TileType form, Color myNewColor, Colors numColor)
	:Zone_Structures(Pos,form,myNewColor,numColor)
{
	alredyChange = false;
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
			switch (actualColor) 
			{
			case red:
				if (alredyChange == false)
				{
					setColor(blue);
					alredyChange = true;
				}

				break;
			case blue:
				
				if (alredyChange == false)
				{
					setColor(green);
					alredyChange = true;
				}
				break;
			case green:
				
				if (alredyChange == false)
				{
					setColor(red);
					alredyChange = true;
				}
				break;
			default:
				break;
			}
		}

	}
	else
	{
		alredyChange = false;
	}
}