#ifndef PLATES_H
#define PLATES_H
#include "raylib.h"
#include "gameElements/levels/Zone_Structures.h"
#include "gameElements/Global.h"
namespace FormersMJ
{
	class Plates :public Zone_Structures
	{
	private:
		bool alredyChange;
		static Sound soundPlatesForm;
	public:
		Plates(Vector2 Pos, TileType form, Color myNewColor, Texture2D myNewSkin);
		~Plates();
		bool getAlredyChange();
		void setAlredyChange(bool newRedyChange);
		void checkCollision(Vector2 position, Vector2 lastPosition);
		static void setSoundChangeForm(Sound newSound) { soundPlatesForm = newSound; };
		static Sound getSoundChangeForm() { return soundPlatesForm; };
	};
}
#endif