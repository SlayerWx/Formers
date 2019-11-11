#ifndef ZONE_H
#define ZONE_H
#include "gameObjects/Plates.h"
class Zone
{
public:
	Plates* cantPlates[25][13];
	virtual void Init();
	virtual void Update();
	void Draw();
	Zone();
	~Zone();

private:

};
#endif