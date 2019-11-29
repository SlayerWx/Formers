#ifndef FORMERS_H
#define FORMERS_H
#include "raylib.h"

#include "gameElements/Game.h"
#include "gameElements/Menu.h"
#include "gameElements/Credits.h"
#include "gameElements/Global.h"
namespace FormersMJ
{
	class Formers
	{
	public:
		Formers();
		~Formers();
		void Play();
		const int screenWidth = 810;
		const int screenHeight = 450;

		Game* game;
		Menu* menu;
		Credits* credits;
		bool firstTime;
	private:
		void Init();
		void Update();
		void Draw();
		bool inGame;
		Sound winSong;
	};
}
#endif