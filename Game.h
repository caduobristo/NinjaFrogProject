#pragma once

#include "stdafx.h"
#include "Definitions.h"

#include "Menu.h"
#include "Level.h"

class Game{
	private:
		RenderWindow* window;
		Menu mainMenu;

		Level* currentLevel;

	public:
		Game();
		~Game();

		void setCurrentLevel(Level* level);
		Level* getCurrentLevel();

		RenderWindow* getWindow();
};

