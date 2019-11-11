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
private:
	Vector2 myPosition;
	float width;
	float hight;
	float radius;
	Form myForm;
	Color myColor;
	bool alredyChange;
public:
	Plates();
	~Plates();

	Plates(Vector2 Pos, Form form, Color myColor);
	void drawMe();
	/*void init(Vector2 Pos, Form form, Color myColor);*/
	Vector2 getPosition();
	void setPosition(Vector2 newPos);
	void setAlredyChange(bool newRedyChange);
	void setForm(Form newForm);
	bool getAlredyChange();
	Form getForm();
	Color getColor();
	void checkCollision(Vector2 position, float width, float height);
};
#endif