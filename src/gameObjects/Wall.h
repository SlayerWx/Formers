#ifndef WALL_H
#define WALL_H
#include "gameElements/levels/Zone_Structures.h"
class Wall:public Zone_Structures
{
public:
	Wall();
	~Wall();
	void checkCollision(Vector2 playerPos, Vector2 lastPosition);
private:

};
#endif
