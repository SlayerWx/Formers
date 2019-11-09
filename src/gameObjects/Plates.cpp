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
bool Plates::checkCollision(Vector2 position, float width, float height)
{

}