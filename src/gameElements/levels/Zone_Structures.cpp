#include "Zone_Structures.h"
Zone_Structures::Zone_Structures()
{
}
Zone_Structures::~Zone_Structures()
{
}
TileType Zone_Structures::getForm()
{
	return myForm;
}

void Zone_Structures::setForm(TileType myNewForm)
{
	myForm = myNewForm;
}
Vector2 Zone_Structures::getPosition()
{
	return myPosition;
}
void Zone_Structures::setPosition(Vector2 newPos)
{
	myPosition = newPos;
}
void Zone_Structures::drawMe()
{
	switch (getForm())
	{
	case circle:
		DrawCircle(myPosition.x - tileScale / 2, myPosition.y - tileScale / 2, tileScale / 2, myColor);
		break;
	case rectangle:
		DrawRectangle(myPosition.x - tileScale, myPosition.y - tileScale, tileScale, tileScale, myColor);
		break;
	case triangle:
		DrawTriangle({ myPosition.x - tileScale / 2,myPosition.y - tileScale / 2 - tileScale / 2 },
			{ myPosition.x - tileScale / 2 - tileScale / 2,myPosition.y + tileScale / 2 - tileScale / 2 },
			{ myPosition.x + tileScale / 2 - tileScale / 2,myPosition.y + tileScale / 2 - tileScale / 2 }, myColor);
		break;
	case wall:
		DrawRectangle(myPosition.x - tileScale, myPosition.y - tileScale, tileScale, tileScale, myColor);
		break;
	}
}
Color Zone_Structures::getColor()
{
	return myColor;
}
void Zone_Structures::setColor(Colors newColor)
{
	actualColor = newColor;
	if (actualColor == red)myColor = RED;
	if (actualColor == blue)myColor = BLUE;
	if (actualColor == green)myColor = GREEN;
	if (actualColor == gray)myColor = GRAY;
	if (actualColor == yellow)myColor = YELLOW;
	if (actualColor == purple)myColor = PURPLE;

}