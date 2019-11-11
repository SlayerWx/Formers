#ifndef GAME_H
#define GAME_H
#include "gameObjects/Player.h"
#include "gameElements/levels/Level1.h"
#include "gameElements/levels/zones/Zone.h"
class Game
{
public:
	Level1* Lvl1;
	Game();
	~Game();
	void Init();
	void Update();
	void Draw();
private:
	Player* player;
};
#endif