#ifndef CREDITS_H
#define CREDITS_H
#include "raylib.h"
namespace FormersMJ
{
	class Credits
	{
	public:
		Credits();
		~Credits();
		void Init();
		void Input();
		void Update();
		void Draw();
	private:
		Texture2D creditsTexture;
	};
}
#endif