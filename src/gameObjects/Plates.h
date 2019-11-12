#ifndef PLATES_H
#define PLATES_H
#include "raylib.h"
#include "gameElements/Global.h"
enum Form
{
	circle, rectangle, triangle
};
enum Colors
{
	red,blue,green
};
class Plates
{
private:
	Vector2 myPosition;
	float width;
	float hight;
	float radius;
	Form myForm;
	Color myColor;
	Colors actualColor;
	bool alredyChange;
	bool isActive;
public:
	Plates();
	~Plates();

	Plates(Vector2 Pos, Form form, Color myColor, Colors numColor);
	void drawMe();
	/*void init(Vector2 Pos, Form form, Color myColor);*/
	Vector2 getPosition();
	void setPosition(Vector2 newPos);
	void setAlredyChange(bool newRedyChange);
	void setForm(Form newForm); 
	void setColor(Colors newColor);
	void setActive();
	bool getActive();
	bool getAlredyChange();
	Form getForm();
	Color getColor();
	void checkCollision(Vector2 position, Vector2 lastPosition, float width, float height);
};
#endif