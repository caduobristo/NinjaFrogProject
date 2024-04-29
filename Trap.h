#pragma once

#include "Entity.h"
#include "Player.h"

class Trap : public Entity {
	private:
		Player* player;

	public:
		Trap();
		~Trap();
		Trap(string texture, Vector2f pos, Player* player);

		void update();
};

