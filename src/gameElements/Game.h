#ifndef GAME_H
#define GAME_H
#include "raylib.h"
#include "gameObjects/Player.h"
#include "gameElements/levels/Level.h"
#include "gameElements/levels/zones/Zone.h"
namespace FormersMJ
{
	class Game
	{
	public:
		Level* lvl;
		Game();
		~Game();
		void Init();
		bool Update();
		void Draw();
		Music gameplayMusic;
		float volume;
	private:
		Player* player;
		Music gameMusic;
		Sound resetSong;
	};
}
#endif