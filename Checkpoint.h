#pragma once

#include "stdafx.h"
#include "Definitions.h"

#include "Entity.h"
#include "Player.h"
#include "SecondLevel.h"

class Game;

class Checkpoint : public Entity {
	private:
		Player* player;
		Game* game;

	public:
		Checkpoint();
		Checkpoint(string texture, Vector2f pos, Player* player, Game* game);
		~Checkpoint();

		void update();
};

