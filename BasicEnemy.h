#pragma once

#include "Entity.h"
#include "Player.h"

class BasicEnemy : public Entity {
	private:
		Player* player;
		Vector2f initialPos;

		int direction;
		int distance;

	public:
		BasicEnemy();
		BasicEnemy(string texture, Vector2f pos, Player* player, int direction, int traveledBlocks);
		~BasicEnemy();

		void update();
		void move();
};

