#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
class Player
{
public:
	Player();
	~Player();
	void drawMe();
private:
	Rectangle myBody;
	Color myColor;
};
#endif