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
	int getMoves();
	void updateMoves();
	void resetMoves();
	Vector2 getPosition();
	Vector2 getLastPosition();
	Vector2 getNextPos();
private:
	Rectangle myBody;
	Color myColor;
	float speed;
	float executingMovement;
	float distance;
	int moves;
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