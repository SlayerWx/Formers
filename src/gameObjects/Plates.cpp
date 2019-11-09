#include "Plates.h"

Plates::Plates()
{
}

Plates::~Plates()
{
}
void Plates::drawMe()
{
#if DEBUG
	switch (myForm)
	{
	case circle:
		DrawCircle(myPosition.x, myPosition.y, radius, myColor);
		break;
	case rectangle:
		DrawRectangle(myPosition.x, myPosition.y, radius, radius, myColor);
		break;
	case triangle:
		DrawTriangle({ myPosition.x,myPosition.y - radius/4 }, 
					 { myPosition.x - radius / 2,myPosition.y + radius / 4 },
					 { myPosition.x + radius / 2,myPosition.y + radius / 4 }, myColor);
		break;
	}
#endif
}
Vector2 Plates::getPosition()
{
	return myPosition;
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
	if (playerPosition.x + playerWidth / 2 > myPosition.x - radius &&
		playerPosition.x - playerWidth / 2 < myPosition.x + radius &&
		playerPosition.y - playerHeight / 2 > myPosition.x + radius &&
		playerPosition.y + playerHeight / 2 < myPosition.x - radius)
	{

	}
}