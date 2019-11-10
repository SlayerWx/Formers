#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
class Player
{
public:
	Player();
	~Player();
	void drawMe();
	void input();
	void move();
private:
	Rectangle myBody;
	Color myColor;
	float speed;
	float executingMovement;
	float distance;
	bool down;
	bool up;
	bool left;
	bool right;
	bool stopAction;
	Vector2 startPosition;
	Vector2 endPosition;
	float lerp(float start, float end, float percent);
};
#endif