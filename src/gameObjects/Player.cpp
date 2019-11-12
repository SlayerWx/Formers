#include "Player.h"
#include <iostream>
Player::Player()
{
	speed = 4.0f;
	distance = widthAndHeightWorld;
	myBody.x = widthAndHeightWorld;
	myBody.y = widthAndHeightWorld*7;
	myColor = YELLOW;
	myBody.width = widthAndHeightWorld;
	myBody.height = widthAndHeightWorld;
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

Vector2 Player::getPosition()
{
	return {myBody.x, myBody.y};
}
Vector2 Player::getLastPosition()
{
	return { startPosition.x, startPosition.y };
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
		if (IsKeyDown(KEY_W) && myBody.y > myBody.height/2 + widthAndHeightWorld && !down)
		{
			up = true;
			startPosition.x = myBody.x;
			startPosition.y = myBody.y;
			endPosition.x = startPosition.x;
			endPosition.y = startPosition.y - distance;
		}
		else if (IsKeyDown(KEY_S) && myBody.y < GetScreenHeight() - myBody.height - widthAndHeightWorld && !up)
		{
			down = true;
			startPosition.x = myBody.x;
			startPosition.y = myBody.y;
			endPosition.x = startPosition.x;
			endPosition.y = startPosition.y + distance;
		}
		else if (IsKeyDown(KEY_A) && myBody.x >= myBody.height / 2 + widthAndHeightWorld && !right)
		{
			left = true;
			startPosition.x = myBody.x;
			startPosition.y = myBody.y;
			endPosition.x = startPosition.x - distance;
			endPosition.y = startPosition.y;
		}
		else if (IsKeyDown(KEY_D) && myBody.x < GetScreenWidth() - myBody.height - widthAndHeightWorld && !left)
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