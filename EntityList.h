#pragma once

#include "stdafx.h"
#include "List.h"
#include "Element.h"
#include "Entity.h"

class EntityList{
	private:
		List<Entity> list;

	public:
		EntityList();
		~EntityList();

		void push(Entity* entity);
		void remove(Entity* entity);
		Entity* getItem(int pos);

		void draw(RenderWindow* window);
		void update();
		void clear();
		int getSize();
};

