#include "Zone_Structures.h"
#include "gameElements/Global.h"
namespace FormersMJ
{
	Zone_Structures::Zone_Structures()
	{
		myPosition.x = 0;
		myPosition.y = 0;
		myForm = circle;
		myColor = F_DARKBLUE;
		actualColor = blue;
	}
	Zone_Structures::Zone_Structures(Vector2 Pos, TileType form, Color myNewColor, Colors numColor)
	{
		myPosition = Pos;
		myForm = form;
		myColor = myNewColor;
		actualColor = numColor;
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
			DrawCircle(static_cast<int>(myPosition.x - tileScale / 2),
				static_cast<int>(myPosition.y - tileScale / 2), tileScale / 2, myColor);
			break;
		case rectangle:
			DrawRectangle(static_cast<int>(myPosition.x - tileScale),
				static_cast<int>(myPosition.y - tileScale), tileScale, tileScale, myColor);
			break;
		case triangle:
			DrawTriangle({ myPosition.x - tileScale / 2,myPosition.y - tileScale / 2 - tileScale / 2 },
				{ myPosition.x - tileScale / 2 - tileScale / 2,myPosition.y + tileScale / 2 - tileScale / 2 },
				{ myPosition.x + tileScale / 2 - tileScale / 2,myPosition.y + tileScale / 2 - tileScale / 2 }, myColor);
			break;
		case wall:
			DrawRectangle(static_cast<int>(myPosition.x - tileScale),
				static_cast<int>(myPosition.y - tileScale), tileScale, tileScale, myColor);
			break;

		case doorR:
			DrawRectangle(static_cast<int>(myPosition.x - tileScale),
				static_cast<int>(myPosition.y - tileScale), tileScale, tileScale, myColor);
			break;

		case doorT:
			DrawTriangle({ myPosition.x - tileScale / 2,myPosition.y - tileScale / 2 - tileScale / 2 },
				{ myPosition.x - tileScale / 2 - tileScale / 2,myPosition.y + tileScale / 2 - tileScale / 2 },
				{ myPosition.x + tileScale / 2 - tileScale / 2,myPosition.y + tileScale / 2 - tileScale / 2 }, myColor);
			break;

		case doorC:
			DrawCircle(static_cast<int>(myPosition.x - tileScale / 2),
				static_cast<int>(myPosition.y - tileScale / 2), tileScale / 2, myColor);
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
		if (actualColor == red)   myColor = F_DARKRED;
		if (actualColor == blue)  myColor = F_DARKBLUE;
		if (actualColor == green) myColor = F_DARKGREEN;
		if (actualColor == gray)  myColor = GRAY;
		if (actualColor == yellow)myColor = YELLOW;
		if (actualColor == purple)myColor = PURPLE;

	}
}