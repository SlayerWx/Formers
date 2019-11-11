#include "Plates.h"

Plates::Plates()
{
	myPosition.x = 0;
	myPosition.y = 0;
	width = WidthAndHeightWorld;
	hight = WidthAndHeightWorld;
	radius = WidthAndHeightWorld / 2;
	myForm = circle;
	myColor = RED;
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

Plates::Plates(Vector2 Pos, Form form, Color myColor)
{
	myPosition.x = Pos.x;
	myPosition.y = Pos.y;
	width = WidthAndHeightWorld;
	hight = WidthAndHeightWorld;
	radius = WidthAndHeightWorld / 2;
	myForm = form;
	myColor = myColor;
	alredyChange = false;
}
void Plates::drawMe()
{
	
	switch (myForm)
	{
	case circle:
		DrawCircle(myPosition.x+30, myPosition.y+30, radius, myColor);
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
bool Plates::checkCollision(Vector2 playerPosition, float playerWidth, float playerHeight)
{
	if (playerPosition.x + playerWidth / 2 > myPosition.x - radius &&
		playerPosition.x - playerWidth / 2 < myPosition.x + radius &&
		playerPosition.y - playerHeight / 2 > myPosition.x + radius &&
		playerPosition.y + playerHeight / 2 < myPosition.x - radius)
	{
		return true;
	}
	else
	{
		return false;
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