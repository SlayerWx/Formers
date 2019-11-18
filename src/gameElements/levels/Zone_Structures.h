#ifndef ZONE_STRUCTURES_H
#define ZONE_STRUCTURES_H
#include "raylib.h"
#include "gameElements/Global.h"
namespace FormersMJ
{
	enum Colors
	{
		red, blue, green, gray, yellow, purple
	};
	enum TileType
	{
		vacio, wall, door, circle, rectangle, triangle, doorC = 23, doorR, doorT, circleR = 31, circleB, circleG, rectangleR = 41, rectangleB, rectangleG, triangleR = 51, triangleB, triangleG, doorCR = 231, doorCB, doorCG, doorRR = 241, doorRB, doorRG, doorTR = 251, doorTB, doorTG
	};
	class Zone_Structures
	{
	public:
		Zone_Structures();
		Zone_Structures(Vector2 Pos, TileType form, Color myNewColor, Colors numColor, int id);
		virtual ~Zone_Structures();
		void setColor(Colors myColor);
		Color getColor();
		int getID();
		Vector2 getPosition();
		void setPosition(Vector2 newPos);
		TileType getForm();
		void setForm(TileType myNewForm);
		virtual void checkCollision(Vector2 playerPos, Vector2 lastPosition) = 0;
		void drawMe();
		bool chekable;
		int id;
		int color;
		char myType();
		char type;
	protected:
		Vector2 myPosition;
		TileType myForm;
		Color myColor;
		
		Colors actualColor;

	};
}
#endif
