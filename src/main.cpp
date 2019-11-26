#include "game/Formers.h"
using namespace FormersMJ;
int main()
{
	Formers* game = new Formers();
	game->Play();
	if(game) delete game;
	return 0;
}