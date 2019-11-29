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
		volume = 0.25f;
		SetMusicVolume(gameMusic, volume);
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
		SetMusicVolume(gameMusic, volume);
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
		if (IsKeyReleased(KEY_F3))
		{
			if (volume <= 1.00f)
			{
				volume = volume + 0.1f;
			}
		}
		if (IsKeyReleased(KEY_F2))
		{
			if (volume >= 0.00f)
			{
				volume = volume - 0.1f;
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