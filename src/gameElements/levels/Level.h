#ifndef LEVEL_H
#define LEVEL_H
#include "zones/Zone.h"
#include "gameObjects/Player.h"
namespace FormersMJ
{
	class Level
	{
	private:
		Zone* map[9];
		bool alreadyChange;
		int actualMap;
	public:
		Level();
		~Level();
		void update(Player* player);
		void draw();

	};
}
#endif


