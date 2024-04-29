#include "FirstLevel.h"

FirstLevel::FirstLevel() {
	this->backgroundColor = Color(220, 174, 193,1);
}

FirstLevel::FirstLevel(Game* game): Level(game){
	this->backgroundColor = Color(220, 174, 193, 1);

	this->setUpPlayer();
	this->setUpTiles();
	this->setUpEnemies();
	this->setUpButtons();
}

FirstLevel::~FirstLevel() {}

void FirstLevel::setUpTiles() {
	this->setUpTerrain();
	this->setUpPlatforms();
	this->setUpTraps();
	this->setUpFruits();
	this->setUpBorder();

	// Set Checkpoint
	this->entityList.push(new Checkpoint(string(PATH) + string("Images/checkpoints/checkpoint.png"), Vector2f(188 * 32, 377), this->player, this->game));
}

void FirstLevel::setUpTerrain() {
	for (float i = 0; i < 18;i++)
		this->entityList.push(new Tile(string(PATH) + string("Images/blocks/terrain_1.png"), Vector2f((i * 32), 1344.f), this->player));

	for (float i = 0; i < 3;i++)
		for (float j = 0;j < 18;j++)
			this->entityList.push(new Tile(string(PATH) + string("Images/blocks/terrain_2.png"), Vector2f((j * 32), (i * 32) + 1376), this->player));

	for (float i = 33, j=0; i < 63;i++) {
		this->entityList.push(new Tile(string(PATH) + string("Images/blocks/terrain_1.png"), Vector2f((i * 32), (j * 32) + 1088), this->player));

		if (i == 54 || i == 57 || i == 59 || i == 60) j++;
	}

	for (float i = 0; i < 11;i++) {
		for (float j = 33;j < 63;j++) {
			this->entityList.push(new Tile(string(PATH) + string("Images/blocks/terrain_2.png"), Vector2f((j * 32), (i * 32) + 1120), this->player));

			if ((i == 0 && j == 54) || (i == 1 && j == 57) || (i == 2 && j == 59) || (i == 3 && j == 60))
				j = 63;
		}
	}

	for (float i = 99, j = 0; i < 110;i++) {
		this->entityList.push(new Tile(string(PATH) + string("Images/blocks/terrain_1.png"), Vector2f((i * 32), 1228 - (j * 32)), this->player));

		if (i == 104 || i == 106) j++;
	}

	for (float i = 0; i < 9;i++) {
		for (float j = 109;j > 98;j--) {
			this->entityList.push(new Tile(string(PATH) + string("Images/blocks/terrain_2.png"), Vector2f((j * 32), 1196 + (i * 32)), this->player));

			if ((i == 0  && j == 107) || (i == 1 && j == 105))
				j = 98;
		}
	}

	for (float i = 140,j=0;i < 164;i++) {
		this->entityList.push(new Tile(string(PATH) + string("Images/blocks/terrain_1.png"), Vector2f((i * 32), 800 - (j * 32)), this->player));

		if (i == 152 || i == 156 || i == 158)
			j++;
	}

	for (float i = 0; i < 23;i++) {
		for (float j = 163;j > 139;j--) {
			this->entityList.push(new Tile(string(PATH) + string("Images/blocks/terrain_2.png"), Vector2f((j * 32), 736 + (i * 32)), this->player));

			if ((i == 0 && j == 159) || (i == 1 && j == 157) || (i == 2 && j == 153))
				j = 139;
		}
	}

	for (float i = 186;i < 190;i++) 
		this->entityList.push(new Tile(string(PATH) + string("Images/blocks/terrain_1.png"), Vector2f((i * 32), 416), this->player));

}

void FirstLevel::setUpPlatforms() {
	this->entityList.push(new Tile(string(PATH) + string("Images/blocks/block_1.png"), Vector2f(17 * 32, 1312), this->player));

	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_1.png"), Vector2f(21 * 32, 1216), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_1.png"), Vector2f(26 * 32, 1120), this->player));

	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_1.png"), Vector2f(69 * 32, 1280), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_1.png"), Vector2f(77 * 32, 1248), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_1.png"), Vector2f(86 * 32, 1344), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_1.png"), Vector2f(94 * 32, 1312), this->player));

	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_1.png"), Vector2f(114 * 32, 1056), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_1.png"), Vector2f(121 * 32, 992), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_1.png"), Vector2f(128 * 32, 928), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_1.png"), Vector2f(135 * 32, 884), this->player));

	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_1.png"), Vector2f(169 * 32, 640), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_1.png"), Vector2f(175 * 32, 576), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_1.png"), Vector2f(181 * 32, 512), this->player));
}

void FirstLevel::setUpTraps() {
	for (float i = 18;i < 33;i++) 
		this->entityList.push(new Trap(string(PATH) + string("Images/traps/spike_32x32.png"), Vector2f((i * 32), (45 * 32)), this->player));

	for (float i = 110;i < 140;i++)
		this->entityList.push(new Trap(string(PATH) + string("Images/traps/spike_32x32.png"), Vector2f((i * 32), (45.35f *32)), this->player));

	for (float i = 58;i < 60;i++)
		this->entityList.push(new Trap(string(PATH) + string("Images/traps/spike_32x32.png"), Vector2f((i * 32), 1124), this->player));

	for (float i = 100;i < 102;i++)
		this->entityList.push(new Trap(string(PATH) + string("Images/traps/spike_32x32.png"), Vector2f((i * 32), 1196), this->player));

	this->entityList.push(new Trap(string(PATH) + string("Images/traps/spike_32x32.png"), Vector2f((105 * 32), 1164), this->player));

	for (float i = 63;i < 99;i++)
		this->entityList.push(new Trap(string(PATH) + string("Images/traps/fire_trap.png"), Vector2f((i * 32), (44.8f * 32)), this->player));

	for (float i = 164;i < 190;i++)
		this->entityList.push(new Trap(string(PATH) + string("Images/traps/fire_trap.png"), Vector2f((i * 32), (44.5 * 32)), this->player));
}

void FirstLevel::setUpFruits() {
	this->fruitsList.clear();

	float positionsY[13] = { 480, 544, 608, 852, 896, 960, 1024, 1280, 1312, 1216, 1248, 1088, 1184 };
	float positionsX[13] = { 180.5, 174.5, 168.5, 134.5, 127.5, 120.5, 113.5, 94, 85.5, 76.5, 68.5, 25.5, 20.5 };

	for (int i = 0;i < 13;i++) {
		this->fruitsList.push(
			new Fruit(
				string(PATH) + string("Images/fruits/apple.png"), Vector2f((positionsX[i] * 32), positionsY[i]), this->player, &this->fruitsList, &this->appleCounter
			)
		);

		this->fruitsList.push(
			new Fruit(
				string(PATH) + string("Images/fruits/apple.png"), Vector2f(((positionsX[i]+1) * 32), positionsY[i]), this->player, &this->fruitsList, &this->appleCounter
			)
		);
	}
}

void FirstLevel::setUpBorder() {
	for (float i = 0;i < 190;i++)
		this->entityList.push(new Tile(string(PATH) + string("Images/blocks/rock.png"), Vector2f((i * 32), 0.f), this->player));

	for (float i = 0.3f;i < 46.3f;i++) { 
		this->entityList.push(new Tile(string(PATH) + string("Images/blocks/rock_wall.png"), Vector2f(-16.f, (i * 32)), this->player));
		this->entityList.push(new Tile(string(PATH) + string("Images/blocks/rock_wall.png"), Vector2f((189.5 * 32), (i * 32)), this->player));
	}
}

void FirstLevel::setUpEnemies() {
	this->entityList.push(new BasicEnemy(string(PATH) + string("Images/enemies/rino.png"), Vector2f(43 * 32, 1048), this->player, -1, 6));
	this->entityList.push(new BasicEnemy(string(PATH) + string("Images/enemies/rino.png"), Vector2f(48 * 32, 1048), this->player, 1, 6));

	this->entityList.push(new BasicEnemy(string(PATH) + string("Images/enemies/duck.png"), Vector2f(143 * 32, 768), this->player, 1, 3));
	this->entityList.push(new BasicEnemy(string(PATH) + string("Images/enemies/duck.png"), Vector2f(148 * 32, 768), this->player, -1, 3));
	this->entityList.push(new BasicEnemy(string(PATH) + string("Images/enemies/duck.png"), Vector2f(157.4f * 32, 704), this->player, -1, 1));
	this->entityList.push(new BasicEnemy(string(PATH) + string("Images/enemies/duck.png"), Vector2f(161 * 32, 672), this->player, -1, 2));
}

const Color FirstLevel::getBackgroundColor() {
	return backgroundColor;
}
