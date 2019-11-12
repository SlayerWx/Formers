#include "Player.h"
#include <iostream>
using namespace std;
Player::Player()
{
	speed = 4.0f;
	distance = WidthAndHeightWorld;
	myBody.x = 0;
	myBody.y = 0;
	myColor = RED;
	myBody.width = WidthAndHeightWorld;
	myBody.height = WidthAndHeightWorld;
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
	system("cls");
	cout << "up = " << up << endl;
	cout << "down = " << down << endl;
	cout << "left = " << left << endl;
	cout << "right = " << right << endl;
	std::cout << "x:" << myBody.x << std::endl;
	std::cout << "y:" << myBody.y << std::endl;
	if (!up && !down && !left && !right)
	{
		if (IsKeyDown(KEY_W) && myBody.y > myBody.height/2 && !down)
		{
			up = true;
			startPosition.x = myBody.x;
			startPosition.y = myBody.y;
			endPosition.x = startPosition.x;
			endPosition.y = startPosition.y - distance;
		}
		else if (IsKeyDown(KEY_S) && myBody.y < GetScreenHeight() - myBody.height && !up)
		{
			down = true;
			startPosition.x = myBody.x;
			startPosition.y = myBody.y;
			endPosition.x = startPosition.x;
			endPosition.y = startPosition.y + distance;
		}
		else if (IsKeyDown(KEY_A) && myBody.x >= myBody.height / 2 && !right)
		{
			left = true;
			startPosition.x = myBody.x;
			startPosition.y = myBody.y;
			endPosition.x = startPosition.x - distance;
			endPosition.y = startPosition.y;
		}
		else if (IsKeyDown(KEY_D) && myBody.x < GetScreenWidth() - myBody.height && !left)
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