#pragma once

#include "stdafx.h"

#include "Collider.h"

class Entity{
	protected:
		Texture texture;

		RectangleShape body;
		Collider* collider;

	public:
		Entity();
		Entity(const string texture, Vector2f pos);
		~Entity();

		void draw(RenderWindow* window);
		virtual void update();

		void setPos(Vector2f pos);

		RectangleShape getBody();
		Collider* getCollider();
};

