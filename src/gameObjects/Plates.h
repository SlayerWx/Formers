#ifndef PLATES_H
#define PLATES_H
#include "raylib.h"
#include "gameElements/Global.h"
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
	void checkCollision(Vector2 position,float width,float height);
private:
	Vector2 myPosition;
	float radius;
	Form myForm;
	Color myColor;
	bool alredyChange;
};
#endif