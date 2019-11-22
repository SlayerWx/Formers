#include "Player.h"
namespace FormersMJ 
{
	Player::Player()
	{
		speed = 4.0f;
		distance = tileScale;
		myBody.x = tileScale;
		myBody.y = tileScale * 7;
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
		return { myBody.x, myBody.y };
	}
	void Player::setPosition(Vector2 newPos)
	{
		endPosition = newPos;
	}
	Vector2 Player::getLastPosition()
	{
		return { startPosition.x, startPosition.y };
	}
	void Player::drawMe()
	{
		//#if DEBUG
		DrawRectangleRec(myBody, myColor);
		//#endif

		DrawText(FormatText("Moves: %i", getMoves()), tileScale, tileScale / 2, tileScale / 2, WHITE);

	}
	void Player::input()
	{

		if (!up && !down && !left && !right)
		{
			if (IsKeyDown(KEY_W) && !down)
			{
				up = true;
				startPosition.x = myBody.x;
				startPosition.y = myBody.y;
				endPosition.x = startPosition.x;
				endPosition.y = startPosition.y - distance;
			}
			else if (IsKeyDown(KEY_S) && !up)
			{
				down = true;
				startPosition.x = myBody.x;
				startPosition.y = myBody.y;
				endPosition.x = startPosition.x;
				endPosition.y = startPosition.y + distance;
			}
			else if (IsKeyDown(KEY_A) && !right)
			{
				left = true;
				startPosition.x = myBody.x;
				startPosition.y = myBody.y;
				endPosition.x = startPosition.x - distance;
				endPosition.y = startPosition.y;
			}
			else if (IsKeyDown(KEY_D) && !left)
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
		if (left) return{ myBody.x - tileScale , myBody.y };
		if (right)return{ myBody.x + tileScale , myBody.y };
		return{ myBody.x, myBody.y };
	}
	void Player::move()
	{
		stopMyAction();
		if (executingMovement > 1.0f)
		{
			executingMovement = 1.0f;
			stopAction = true;
			updateMoves();
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
	void Player::stopMyAction()
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
	}
	void Player::setStopAtion(bool newStopAction)
	{
		stopAction = newStopAction;
	}

}