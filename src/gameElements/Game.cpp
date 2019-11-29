#include "Game.h"
#include <iostream>
#include "raylib.h"
#include "gameElements/levels/zones/Zone.h"
#include "gameElements/Global.h"
#include "gameElements/levels/Level.h"
#include "gameObjects/Player.h"
#include "gameObjects/Plates.h"

namespace FormersMJ
{
	Game::Game()
	{
		player = new Player();
		lvl = new Level();
		gameMusic = LoadMusicStream("assets/sound/gamePlayMusic.ogg");
		resetSong = LoadSound("assets/sound/resetSong.wav");
		SetMusicVolume(gameMusic, 0.25f);
		//SetSoundVolume();
	}
	Game::~Game()
	{
		UnloadMusicStream(gameMusic);
		UnloadSound(resetSong);
		if (player) delete player;
	}
	void Game::Init()
	{
		player = new Player();
		lvl = new Level();
		PlayMusicStream(gameMusic);
	}
	bool Game::Update()
	{
		UpdateMusicStream(gameMusic);
		player->input();
		if (lvl->update(player))
		{
			return true;
		}
		
		player->move();
		if (IsKeyReleased(KEY_R))
		{
			lvl = new Level();
			player->restartPosition();
			player->resetMoves();
			if (!IsSoundPlaying(resetSong)) 
			{
				PlaySound(resetSong);
			}
		}
		else if (IsKeyDown(KEY_ESCAPE))
		{
			gamestatus = MENU;
			lvl = new Level();
			player->restartPosition();
			player->resetMoves();
			if (!IsSoundPlaying(resetSong))
			{
				PlaySound(resetSong);
			}
		}
		return false;
	}
	void Game::Draw()
	{
		lvl->draw();
		player->drawMe();
	}
}