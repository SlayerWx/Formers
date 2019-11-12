#ifndef ZONE_H
#define ZONE_H
#include "gameObjects/Plates.h"
class Zone
{
public:
	Zone_Structures* zoneElements[widthZone][heightZone];
	virtual void Init();
	void Update(Vector2 playerPos, Vector2 lastPosition);
	void Draw();
	Zone(int newMap[]);
	~Zone();

private:

};
#endif