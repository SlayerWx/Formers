#include "Zone_Structures.h"
#include "raylib.h"
#include "gameElements/Global.h"
namespace FormersMJ
{
	Zone_Structures::Zone_Structures()
	{
		myPosition.x = 0;
		myPosition.y = 0;
		myForm = circle;
		myColor = F_DARKBLUE;
	}
	Zone_Structures::Zone_Structures(Vector2 Pos, TileType form, Color myNewColor)
	{
		myPosition = Pos;
		myForm = form;
		myColor = myNewColor;
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

	void Zone_Structures::setColor(Color newColor)
	{
		myColor = newColor;
	}



	char Zone_Structures::myType()
	{
		return type;
	}
	void Zone_Structures::setType(char newType)
	{
		type = newType;
	}
	bool Zone_Structures::compareColor(Color a, Color b)
	{
		if (a.b == b.b &&
			a.g == b.g &&
			a.r == b.r)
		{
			return true;
		}
		return false;
	}
}