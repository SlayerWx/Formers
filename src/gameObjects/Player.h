#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "gameElements/Global.h"
class Player
{
public:
	Player();
	~Player();
	void drawMe();
	void input();
	void move();
	Vector2 getPosition();
	Vector2 getLastPosition();
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