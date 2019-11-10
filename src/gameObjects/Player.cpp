#include "Player.h"
#include <iostream>
Player::Player()
{
	speed = 4.0f;
	distance = 30.0f;
	myBody.x = 0;
	myBody.y = 0;
	myColor = RED;
	myBody.width = 30.0f;
	myBody.height = 30.0f;
	stopAction = false;
	executingMovement = 0.0f;
	up = false;
	down = false;
	right = false;
	left = false;
}

Player::~Player()
{

}
void Player::drawMe()
{
#if DEBUG
	DrawRectangleRec(myBody, myColor);
#endif
}
void Player::input()
{
	if (!up && !down && !left && !right)
	{
		if (IsKeyDown(KEY_W))
		{
			up = true;
			startPosition.x = myBody.x;
			startPosition.y = myBody.y;
			endPosition.x = startPosition.x;
			endPosition.y = startPosition.y - distance;
		}
		if (IsKeyDown(KEY_S))
		{
			down = true;
			startPosition.x = myBody.x;
			startPosition.y = myBody.y;
			endPosition.x = startPosition.x;
			endPosition.y = startPosition.y + distance;
		}
		if (IsKeyDown(KEY_A))
		{
			left = true;
			startPosition.x = myBody.x;
			startPosition.y = myBody.y;
			endPosition.x = startPosition.x - distance;
			endPosition.y = startPosition.y;
		}
		if (IsKeyDown(KEY_D))
		{
			right = true;
			startPosition.x = myBody.x;
			startPosition.y = myBody.y;
			endPosition.x = startPosition.x + distance;
			endPosition.y = startPosition.y;
		}
	}
}
void Player::move()
{
	if (stopAction)
	{
		executingMovement = 0.0f;
		up = false;
		down = false;
		left = false;
		right = false;
		stopAction = false;
	}
	if (executingMovement > 1.0f)
	{
		executingMovement = 1.0f;
		stopAction = true;
	}
	if (up)
	{
		myBody.y = lerp(startPosition.y, endPosition.y, executingMovement);
		executingMovement += speed * GetFrameTime();
	}
	if (down) 
	{ 
		myBody.y = lerp(startPosition.y, endPosition.y, executingMovement);
		executingMovement += speed * GetFrameTime();
	}
	if (left) 
	{ 
		myBody.x = lerp(startPosition.x, endPosition.x, executingMovement);
		executingMovement += speed * GetFrameTime();
	}
	if (right)
	{
		myBody.x = lerp(startPosition.x, endPosition.x, executingMovement);
		executingMovement += speed * GetFrameTime();
	}
}
float Player::lerp(float start, float end, float percent)
{
	return (start + percent * (end - start));
}