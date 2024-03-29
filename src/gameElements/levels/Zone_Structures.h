#ifndef ZONE_STRUCTURES_H
#define ZONE_STRUCTURES_H
#include "raylib.h"
#include "gameElements/Global.h"
namespace FormersMJ
{
	
	enum TileType
	{
		vacio, wall, door, circle, rectangle, triangle, doorC = 23, doorR, doorT, circleR = 31, circleB, circleG, rectangleR = 41, rectangleB, rectangleG, triangleR = 51, triangleB, triangleG, doorCR = 231, doorCB, doorCG, doorRR = 241, doorRB, doorRG, doorTR = 251, doorTB, doorTG
	};
	class Zone_Structures
	{
	public:
		Zone_Structures(Vector2 Pos, TileType form, Color myNewColor,Texture2D myNewSkin);
		virtual ~Zone_Structures();
		Color getColor();
		void setColor(Color newColor);
		Vector2 getPosition();
		void setPosition(Vector2 newPos);
		virtual TileType getForm();
		void setForm(TileType myNewForm);
		virtual void checkCollision(Vector2 playerPos, Vector2 lastPosition) = 0;
		void drawMe();
		bool chekable;
		char myType();
		char type;
		void setType(char newType);
		static bool compareColor(Color a, Color b);
		bool canPass;
	protected:
		Vector2 myPosition;
		TileType myForm;
		Color myColor;
		Texture2D mySkin;

	};
}
#endif
