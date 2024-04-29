#pragma once

#include "Level.h"

#include "stdafx.h"
#include "Definitions.h"

#include "Tile.h"
#include "Trap.h"
#include "BasicEnemy.h"
#include "Checkpoint.h"
#include "Fruit.h"

class Game;

class FirstLevel : public Level {
	private:	
		Color backgroundColor;

	public:
		FirstLevel();
		FirstLevel(Game* game);
		~FirstLevel();

		void setUpTiles();
		void setUpTerrain();
		void setUpPlatforms();
		void setUpTraps();
		void setUpFruits();
		void setUpBorder();
		void setUpEnemies();

		const Color getBackgroundColor();
};

