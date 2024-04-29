#pragma once

#include "stdafx.h"
#include "Definitions.h"

#include "EntityList.h"
#include "Player.h"
#include "Tile.h"

class Game;

class Level{
	protected:
		EntityList entityList;
		EntityList fruitsList;
		EntityList buttonsList;
		Game* game;

		Player* player;

		Text appleCounterText;
		Font font;
		int appleCounter;

	public:
		Level();
		Level(Game* game);
		~Level();

		void draw();
		void update(View* view);

		void setUpPlayer();
		void setUpButtons();
		virtual void setUpFruits(){}

		const virtual Color getBackgroundColor();

		void checkClickedButtons();
};

