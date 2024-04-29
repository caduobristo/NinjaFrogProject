#pragma once

#include "stdafx.h"

class Collider {
	private:
		RectangleShape& body;

	public:
		Collider();
		Collider(RectangleShape& body);
		~Collider();

		void move(float x, float y);

		bool checkCollision(Collider* other, Vector2f* direction, float push);

		Vector2f getPosition();
		Vector2f getHalfSize();
};

