#pragma once

#include "EntityList.h"
#include "Player.h"

class Fruit : public Entity{
	private:
		Player* player;
		EntityList* fruitList;
		int* appleCounter;

	public:
		Fruit();
		Fruit(string texture, Vector2f pos, Player* player, EntityList* fruitList, int* appleCounter);
		~Fruit();

		void update();
};

