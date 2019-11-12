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

Plates::Plates(Vector2 Pos, Form form, Color myNewColor, Colors numColor)
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
		DrawCircle(myPosition.x - 15.0f, myPosition.y - 15.0f, widthAndHeightWorld/2, myColor);
		break;
	case rectangle:
		DrawRectangle(myPosition.x - 30.0f, myPosition.y - 30.0f, widthAndHeightWorld, widthAndHeightWorld, myColor);
		break;
	case triangle:
		DrawTriangle({ myPosition.x - 15.0f,myPosition.y - widthAndHeightWorld / 2 - 15.0f },
			{ myPosition.x - widthAndHeightWorld / 2 - 15.0f,myPosition.y + widthAndHeightWorld / 2 - 15.0f },
			{ myPosition.x + widthAndHeightWorld / 2 - 15.0f,myPosition.y + widthAndHeightWorld / 2 - 15.0f }, myColor);
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
				std::cout << "circle" << std::endl;
				if (alredyChange == false)
				{
					setForm(rectangle);
					alredyChange = true;
				}

				break;
			case rectangle:
				std::cout << "rectangle" << std::endl;
				if (alredyChange == false)
				{
					setForm(triangle);
					alredyChange = true;
				}
				break;
			case triangle:
				std::cout << "triangle" << std::endl;
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
			system("cls");
			
			std::cout << "color:" << actualColor << std::endl;
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

void Plates::setForm(Form newForm)
{
	myForm = newForm;
}
void Plates::setColor(Colors newColor)
{
		actualColor = newColor;
		if (actualColor == red)myColor = RED;
		if (actualColor == blue)myColor = BLUE;
		if (actualColor == green)myColor = GREEN;
}
Form Plates::getForm()
{
	return myForm;
}