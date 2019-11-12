#ifndef PLATES_H
#define PLATES_H
#include "raylib.h"
#include "gameElements/levels/Zone_Structures.h"
#include "gameElements/Global.h"
class Plates :public Zone_Structures
{
private:
	bool alredyChange;
public:
	Plates();
	~Plates();

	Plates(Vector2 Pos, TileType form, Color myColor, Colors numColor);
	void drawMe();
	/*void init(Vector2 Pos, Form form, Color myColor);*/
	Vector2 getPosition();
	void setPosition(Vector2 newPos);
	void setAlredyChange(bool newRedyChange);
	void setForm(TileType newForm); 
	void setColor(Colors newColor);
	bool getAlredyChange();
	TileType getForm();
	Color getColor();
	void checkCollision(Vector2 position, Vector2 lastPosition);
};
#endif