#ifndef ZONE_H
#define ZONE_H
#include "gameObjects/Plates.h"
class Zone
{
public:
	Plates* zonePlates[25][13];
	virtual void Init();
	void Update(Vector2 playerPos);
	void Draw();
	Zone();
	~Zone();

private:

};
#endif