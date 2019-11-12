#ifndef ZONE_STRUCTURES_H
#define ZONE_STRUCTURES_H
#include "raylib.h"
enum Colors
{
	red, blue, green
};
enum Form
{
	space,wall,door,circle, rectangle, triangle
};
class Zone_Structures
{
public:
	Zone_Structures();
	~Zone_Structures();
	virtual void setColor(Colors myColor) = 0;
	virtual Color getColor() = 0;
	virtual Vector2 getPosition() = 0;
	Form getForm();
	virtual void checkCollision(Vector2 playerPos, Vector2 lastPosition) = 0;
	virtual void drawMe() = 0;
protected:
	Vector2 myPosition;
	Form myForm;
	Color myColor;
	Colors actualColor;

};
#endif
