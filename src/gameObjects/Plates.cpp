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
}
void Plates::drawMe()
{
	switch (myForm)
	{
	case circle:
		DrawCircle(myPosition.x-15.0f, myPosition.y-15.0f, radius, myColor);
		break;
	case rectangle:
		DrawRectangle(myPosition.x, myPosition.y, width, hight, myColor);
		break;
	case triangle:
		DrawTriangle({ myPosition.x,myPosition.y - hight/2},
			{ myPosition.x - width / 2,myPosition.y +  hight/2},
			{ myPosition.x + width / 2,myPosition.y + hight / 2 }, myColor);
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
	if (playerPosition.x == myPosition.x && 
		playerPosition.y == myPosition.y)
	{
		std::cout<<"colision"<<std::endl;
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