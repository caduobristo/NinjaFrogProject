#pragma once

#include "stdafx.h"
#include "Definitions.h"

#include "EntityList.h"
#include "Tile.h"
#include "FirstLevel.h"
#include "SecondLevel.h"

class Game;

class Menu{
	private:
		RenderWindow* window;
		Game* game;
		EntityList tileList;
		EntityList buttonsList;

		Font font;
		char currentLevel;

		RectangleShape playButton;
		RectangleShape nextLevelButton;
		RectangleShape previousLevelButton;
		RectangleShape exitButton;

	public:
		Menu();
		~Menu();

		void setGame(Game* game);

		void draw();
		void renderTitle();
		void renderButtons();

		void update();

		void initButtons();
		void initFont();
		void initTiles();

		void checkMouseIsOverButtons();
		void checkClickedButtons();

		void setLevel(char level);
};

