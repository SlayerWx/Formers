#include "Plates.h"
#include <iostream>
#include "raylib.h"
using namespace std;
Plates::Plates()
{
	myPosition.x = 0;
	myPosition.y = 0;
	myForm = circle;
	myColor = BLUE;
	actualColor = blue;
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
{
	myPosition.x = Pos.x;
	myPosition.y = Pos.y;
	myForm = form;
	myColor = myNewColor;
	actualColor = numColor;
	alredyChange = false;
}
void Plates::drawMe()
{
	switch (getForm())
	{
	case circle:
		DrawCircle(myPosition.x - widthAndHeightWorld/2, myPosition.y - widthAndHeightWorld / 2, widthAndHeightWorld/2, myColor);
		break;
	case rectangle:
		DrawRectangle(myPosition.x - widthAndHeightWorld, myPosition.y - widthAndHeightWorld, widthAndHeightWorld, widthAndHeightWorld, myColor);
		break;
	case triangle:
		DrawTriangle({ myPosition.x - widthAndHeightWorld / 2,myPosition.y - widthAndHeightWorld / 2 - widthAndHeightWorld / 2 },
			{ myPosition.x - widthAndHeightWorld / 2 - widthAndHeightWorld / 2,myPosition.y + widthAndHeightWorld / 2 - widthAndHeightWorld / 2 },
			{ myPosition.x + widthAndHeightWorld / 2 - widthAndHeightWorld / 2,myPosition.y + widthAndHeightWorld / 2 - widthAndHeightWorld / 2 }, myColor);
		break;
	case wall:
		DrawRectangle(myPosition.x - widthAndHeightWorld, myPosition.y - widthAndHeightWorld, widthAndHeightWorld, widthAndHeightWorld, myColor);
		break;
	}
}
Vector2 Plates::getPosition()
{
	return myPosition;
}

Color Plates::getColor()
{
	return myColor;
}
void Plates::setPosition(Vector2 newPos)
{
	myPosition = newPos;
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

void Plates::setForm(TileType newForm)
{
	myForm = newForm;
}
void Plates::setColor(Colors newColor)
{
		actualColor = newColor;
		if (actualColor == red)myColor = RED;
		if (actualColor == blue)myColor = BLUE;
		if (actualColor == green)myColor = GREEN;
		if (actualColor == gray)myColor = GRAY;
		if (actualColor == yellow)myColor = YELLOW;
		if (actualColor == purple)myColor = PURPLE;

}
TileType Plates::getForm()
{
	return myForm;
}