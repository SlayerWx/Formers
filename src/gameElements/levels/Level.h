#ifndef LEVEL_H
#define LEVEL_H
#include "zones/Zone.h"
#include "gameObjects/Player.h"
namespace FormersMJ
{
	class Level
	{
	private:
		Zone* map[5][5];
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


