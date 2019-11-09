#include "Player.h"

Player::Player()
{

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