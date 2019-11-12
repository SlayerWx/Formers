#ifndef ZONE_H
#define ZONE_H
#include "gameObjects/Plates.h"
class Zone
{
public:
	Zone_Structures* zoneElements[mapRow][mapColumn];
	virtual void Init();
	void Update(Vector2 playerPos, Vector2 lastPosition);
	void Draw();
	Zone(int newMap[mapRow][mapColumn]);
	~Zone();

private:

};
#endif