#ifndef ZONE_H
#define ZONE_H
#include "gameObjects/Player.h"
#include "gameElements/levels/Zone_Structures.h"
#include "gameObjects/Door.h"
namespace FormersMJ
{
	class Zone
	{
	public:
		Zone_Structures* zoneElements[mapRow][mapColumn];
		virtual void Init();
		void Update(Player* player);
		void Draw();
		Zone(int newMap[mapRow][mapColumn], int maxMovments);
		~Zone();
		bool checkWin(Player* player);
		int getMaxMoves();
	private:
		int maxMoves;
		Door* doors[4];
	};
}
#endif