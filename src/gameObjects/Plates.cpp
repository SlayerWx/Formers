#include "Plates.h"
#include <iostream>
Plates::Plates()
{
	myPosition.x = 0;
	myPosition.y = 0;
	width = WidthAndHeightWorld;
	hight = WidthAndHeightWorld;
	radius = WidthAndHeightWorld / 2;
	myForm = circle;
	myColor = BLUE;
	alredyChange = false;
	isActive = false;
}
/*
void Plates::init(Vector2 Pos, Form form, Color myColor)
{
	Plates(Pos, form, myColor);
}*/
Plates::~Plates()
{
}

Plates::Plates(Vector2 Pos, Form form, Color myNewColor)
{
	myPosition.x = Pos.x;
	myPosition.y = Pos.y;
	width = WidthAndHeightWorld;
	hight = WidthAndHeightWorld;
	radius = WidthAndHeightWorld / 2;
	myForm = form;
	myColor = myNewColor;
	alredyChange = false;
	isActive = false;
}
void Plates::drawMe()
{
	switch (getForm())
	{
	case circle:
		DrawCircle(myPosition.x - 15.0f, myPosition.y - 15.0f, radius, myColor);
		break;
	case rectangle:
		DrawRectangle(myPosition.x-30.0f, myPosition.y -30.0f, width, hight, myColor);
		break;
	case triangle:
		DrawTriangle({ myPosition.x - 15.0f,myPosition.y - hight / 2 - 15.0f },
			{ myPosition.x - width / 2 - 15.0f,myPosition.y + hight / 2 - 15.0f },
			{ myPosition.x + width / 2 - 15.0f,myPosition.y + hight / 2 - 15.0f }, myColor);
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
void Plates::checkCollision(Vector2 playerPosition, float playerWidth, float playerHeight)
{
	if (playerPosition.x == myPosition.x-30.0f &&
		playerPosition.y == myPosition.y - 30.0f)
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
		alredyChange = false;
	}
}

void Plates::setForm(Form newForm)
{
	myForm = newForm;
}
Form Plates::getForm()
{
	return myForm;
}
bool Plates::getActive()
{
	return isActive;
}
void Plates::setActive()
{
	isActive = !isActive;
}