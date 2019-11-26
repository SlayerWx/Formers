#ifndef ZONE_H
#define ZONE_H

#include "gameElements/levels/Zone_Structures.h"
#include "gameObjects/Player.h"
#include "gameObjects/Door.h"
namespace FormersMJ
{
	static const int MAXDOORS = 4;
	class Zone
	{
	public:
		Zone_Structures* zoneElements[mapRow][mapColumn];
		virtual void Init();
		void Update(Player* player);
		void Draw();
		Zone(int newMap[mapRow][mapColumn], int maxMovments);
		~Zone();
		bool checkWin();
		int getMaxMoves();
		bool isFinish;
	private:
		int maxMoves;
		Door* doors[MAXDOORS];
	};
}
#endif