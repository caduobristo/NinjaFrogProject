#pragma once

#include "Entity.h"
#include "Player.h"

class Projectile : public Entity {
	Player* player;
	Vector2f initialPos;

	public:
		Projectile();
		Projectile(string texture, Vector2f pos, Player* player);
		~Projectile();

		void update();
};

