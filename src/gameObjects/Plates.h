#ifndef PLATES_H
#define PLATES_H
#include "raylib.h"
enum Form
{
	circle, rectangle, triangle
};
class Plates
{
public:
	Plates();
	~Plates();
	void drawMe();
	Vector2 getPosition();
	void setPosition(Vector2 newPos);
	void setAlredyChange(bool newRedyChange);
	bool getAlredyChange();
private:
	Vector2 myPosition;
	float radius;
	Form myForm;
	Color myColor;
	bool alredyChange;
};
#endif