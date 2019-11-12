#ifndef LEVEL1_H
#define LEVEL1_H
#include "zones/Zone.h"
class Level1
{
private:
	Zone* map1;
public:
	Level1();
	~Level1();
	void update(Vector2 playerPos, Vector2 lastPosition);
	void draw();

};
#endif



