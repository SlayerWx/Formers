#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "gameElements/Global.h"
namespace FormersMJ
{
	class Player
	{
	public:
		Player();
		~Player();
		void drawMe();
		void input();
		void move();
		int getMoves();
		void initMoves();
		void updateMoves();
		void resetMoves();
		Vector2 getPosition();
		void setPosition(Vector2 newPos);
		Vector2 getLastPosition();
		Vector2 getNextPos();
		void stopMyAction();
		void setStopAtion(bool newStopAction);
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
}
#endif