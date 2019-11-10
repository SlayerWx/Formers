#include "game/Formers.h"
int main()
{
	Formers* game = new Formers();
	game->Play();
	if(game) delete game;
	return 0;
}