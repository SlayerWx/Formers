#ifndef LEVEL_H
#define LEVEL_H
#include "zones/Zone.h"
#include "gameObjects/Player.h"
#include "gameElements/Global.h"
namespace FormersMJ
{
	class Level
	{
	private:
		Zone* map[maxMapZoneRow][maxMapZoneColumn];
		bool alreadyChange;
		int actualMapX;
		int actualMapY;
	public:
		Level();
		~Level();
		void Zones();
		bool update(Player* player);
		void draw();

	};
}
#endif


