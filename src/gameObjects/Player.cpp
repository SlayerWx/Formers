#include "Player.h"
Player::Player()
{
	speed = 4.0f;
	distance = tileSize;
	myBody.x = tileSize;
	myBody.y = tileSize*7;
	myColor = YELLOW;
	myBody.width = tileSize;
	myBody.height = tileSize;
	stopAction = false;
	executingMovement = 0.0f;
	up = false;
	down = false;
	right = false;
	left = false;
	moves = 0;
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

	DrawText(FormatText("Moves: %i",getMoves()), tileSize, tileSize/2, tileSize/2, WHITE);
	
}
void Player::input()
{
	
	if (!up && !down && !left && !right)
	{
		if (IsKeyDown(KEY_W) && myBody.y > myBody.height/2 + tileSize && !down)
		{
			up = true;
			startPosition.x = myBody.x;
			startPosition.y = myBody.y;
			endPosition.x = startPosition.x;
			endPosition.y = startPosition.y - distance;
		}
		else if (IsKeyDown(KEY_S) && myBody.y < GetScreenHeight() - myBody.height - tileSize && !up)
		{
			down = true;
			startPosition.x = myBody.x;
			startPosition.y = myBody.y;
			endPosition.x = startPosition.x;
			endPosition.y = startPosition.y + distance;
		}
		else if (IsKeyDown(KEY_A) && myBody.x >= myBody.height / 2 + tileSize && !right)
		{
			left = true;
			startPosition.x = myBody.x;
			startPosition.y = myBody.y;
			endPosition.x = startPosition.x - distance;
			endPosition.y = startPosition.y;
		}
		else if (IsKeyDown(KEY_D) && myBody.x < GetScreenWidth() - myBody.height - tileSize && !left)
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
		updateMoves();
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
int Player::getMoves()
{
	return moves;
}

void Player::updateMoves()
{
	moves++;
}
void Player::resetMoves()
{
	moves = 0;
}
float Player::lerp(float start, float end, float percent)
{
	return (start + percent * (end - start));
}