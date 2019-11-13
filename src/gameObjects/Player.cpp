#include "Player.h"
Player::Player()
{
	speed = 4.0f;
	distance = tileScale;
	myBody.x = tileScale;
	myBody.y = tileScale*7;
	myColor = YELLOW;
	myBody.width = tileScale;
	myBody.height = tileScale;
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

	DrawText(FormatText("Moves: %i",getMoves()), tileScale, tileScale/2, tileScale/2, WHITE);
	
}
void Player::input()
{
	
	if (!up && !down && !left && !right)
	{
		if (IsKeyDown(KEY_W) && myBody.y > myBody.height/2 + tileScale && !down)
		{
			up = true;
			startPosition.x = myBody.x;
			startPosition.y = myBody.y;
			endPosition.x = startPosition.x;
			endPosition.y = startPosition.y - distance;
		}
		else if (IsKeyDown(KEY_S) && myBody.y < GetScreenHeight() - myBody.height - tileScale && !up)
		{
			down = true;
			startPosition.x = myBody.x;
			startPosition.y = myBody.y;
			endPosition.x = startPosition.x;
			endPosition.y = startPosition.y + distance;
		}
		else if (IsKeyDown(KEY_A) && myBody.x >= myBody.height / 2 + tileScale && !right)
		{
			left = true;
			startPosition.x = myBody.x;
			startPosition.y = myBody.y;
			endPosition.x = startPosition.x - distance;
			endPosition.y = startPosition.y;
		}
		else if (IsKeyDown(KEY_D) && myBody.x < GetScreenWidth() - myBody.height - tileScale && !left)
		{
			right = true;
			startPosition.x = myBody.x;
			startPosition.y = myBody.y;
			endPosition.x = startPosition.x + distance;
			endPosition.y = startPosition.y;
		}
	}
}
Vector2 Player::getNextPos() {
	if (up)   return{ myBody.x, myBody.y - tileScale };
	if (down) return{ myBody.x, myBody.y + tileScale };
	if (left) return{ myBody.x - tileScale, myBody.y };
	if (right)return{ myBody.x + tileScale, myBody.y };
			  return{ myBody.x, myBody.y };
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