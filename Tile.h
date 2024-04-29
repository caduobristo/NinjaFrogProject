#pragma once

#include "stdafx.h"

#include "Entity.h"
#include "Player.h"

class Tile : public Entity {
	private: 
		Player* player;
			 
	public:
		Tile();
		Tile(string texture, Vector2f pos, Player* player);
		~Tile();

		void update();
};

