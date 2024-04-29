#pragma once

#include "Level.h"

#include "stdafx.h"
#include "Definitions.h"

#include "Tile.h"
#include "Trap.h"
#include "BasicEnemy.h"
#include "Checkpoint.h"
#include "Fruit.h"
#include "Boss.h"

class Game;

class SecondLevel : public Level {
	private:
		Color backgroundColor;

	public:
		SecondLevel();
		SecondLevel(Game* game);
		~SecondLevel();

		void setUpTiles();
		void setUpTerrain();
		void setUpPlatforms();
		void setUpTraps();
		void setUpFruits();
		void setUpBorder();
		void setUpEnemies();
		
		const Color getBackgroundColor();
};

