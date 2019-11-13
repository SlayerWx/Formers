#ifndef LEVEL_H
#define LEVEL_H
#include "zones/Zone.h"
#include "gameObjects/Player.h"
class Level
{
private:
	Zone* map1;
public:
	Level();
	~Level();
	void update(Player* player);
	void draw();

};
#endif


