#include "Zone_Structures.h"
#include "raylib.h"
#include "gameElements/Global.h"
namespace FormersMJ
{
	Zone_Structures::Zone_Structures(Vector2 Pos, TileType form, Color myNewColor,Texture2D myNewSkin)
	{
		myPosition = Pos;
		myForm = form;
		myColor = myNewColor;
		mySkin = myNewSkin;
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
		int tilescale = static_cast<int>(tileScale);
		switch (getForm())
		{
		case circle:
			DrawCircle(static_cast<int>(myPosition.x - tilescale / 2),
				static_cast<int>(myPosition.y - tilescale / 2), tileScale / 2, myColor);
			break;
		case rectangle:
			DrawRectangle(static_cast<int>(myPosition.x - tilescale),
				static_cast<int>(myPosition.y - tilescale), tilescale, tilescale, myColor);
			break;
		case triangle:
			DrawTriangle({ myPosition.x - static_cast<int>(tilescale / 2),myPosition.y - static_cast<int>(tilescale / 2) - tilescale / 2 },
				{ myPosition.x - static_cast<int>(tilescale / 2) - static_cast<int>(tilescale / 2),myPosition.y + static_cast<int>(tilescale / 2) - static_cast<int>(tilescale / 2) },
				{ myPosition.x + static_cast<int>(tilescale / 2) - static_cast<int>(tilescale / 2),myPosition.y + static_cast<int>(tilescale / 2) - static_cast<int>(tilescale / 2) }, myColor);
			break;
		case wall:
#if DEBUG
			DrawRectangle(static_cast<int>(myPosition.x - tilescale),
				static_cast<int>(myPosition.y - tilescale), tilescale, tilescale, myColor);
#endif
#if RELEASE
			DrawTexture(mySkin, static_cast<int>(myPosition.x - tilescale), static_cast<int>(myPosition.y - tilescale),WHITE);
#endif
			break;
		case doorR:
			DrawRectangle(static_cast<int>(myPosition.x - tilescale),
				static_cast<int>(myPosition.y - tilescale), tilescale, tilescale, myColor);
			break;

		case doorT:
#if DEBUG
			DrawTriangle({ myPosition.x - static_cast<int>(tilescale / 2),myPosition.y - static_cast<int>(tilescale / 2) - static_cast<int>(tilescale / 2) },
				{ myPosition.x - static_cast<int>(tilescale / 2) - static_cast<int>(tilescale / 2),myPosition.y + static_cast<int>(tilescale / 2) - static_cast<int>(tilescale / 2) },
				{ myPosition.x + static_cast<int>(tilescale / 2) - static_cast<int>(tilescale / 2),myPosition.y + static_cast<int>(tilescale / 2) - static_cast<int>(tilescale / 2) }, myColor);
#endif
#if RELEASE
			DrawRectangle(static_cast<int>(myPosition.x - tilescale),
				static_cast<int>(myPosition.y - tilescale), tilescale, tilescale, myColor);
#endif
			break;

		case doorC:
#if DEBUG
			DrawCircle(static_cast<int>(static_cast<int>(myPosition.x - tilescale / 2)),
				static_cast<int>(myPosition.y - tilescale / 2), tileScale / 2, myColor);
#endif
#if RELEASE
			DrawRectangle(static_cast<int>(myPosition.x - tilescale),
				static_cast<int>(myPosition.y - tilescale), tilescale, tilescale, myColor);
#endif
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