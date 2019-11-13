#ifndef ZONE_H
#define ZONE_H
#include "gameObjects/Plates.h"
#include "gameObjects/Player.h"
namespace FormersMJ
{
	class Zone
	{
	public:
		Zone_Structures* zoneElements[mapRow][mapColumn];
		virtual void Init();
		void Update(Player* player);
		void Draw();
		Zone_Structures * GetZoneStructureById(int id);
		Zone(int newMap[mapRow][mapColumn]);
		~Zone();
		bool checkWin();
		int getMaxMoves();

	private:
		int maxMoves;
	};
}
#endif