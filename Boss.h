#pragma once

#include "stdafx.h"
#include "Definitions.h"

#include "EntityList.h"
#include "Player.h"
#include "Projectile.h"

class Boss : public Entity {
	Player* player;
	Projectile* projectile;
	RenderWindow* window;
	Clock clock;

	public:
		Boss();
		Boss(string texture, Vector2f pos, Player* player, RenderWindow* window);
		~Boss();

		void update();
};

