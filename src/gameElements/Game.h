#ifndef GAME_H
#define GAME_H
#include "gameObjects/Player.h"
class Game
{
public:
	Game();
	~Game();
	void Init();
	void Update();
	void Draw();
private:
	Player* player;
};
#endif