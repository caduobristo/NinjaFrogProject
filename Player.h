#pragma once

#include "stdafx.h"

#include "Entity.h"
#include "Definitions.h"

class Player : public Entity {
	private:
		Vector2f velocity;
		bool canJump;
		float jumpHeight;
		Vector2f direction;

	public:
		Player();
		Player(string texture, Vector2f pos);
		~Player();

		void update();
		void move();

		void onCollision();
		void setCurrentPosition(Vector2f pos);

		Vector2f* getDirection();
};

