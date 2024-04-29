#include "SecondLevel.h"
#include "Game.h"

SecondLevel::SecondLevel() {
	this->backgroundColor = Color(188, 203, 213,1);
}

SecondLevel::SecondLevel(Game* game) : Level(game) {
	this->backgroundColor = Color(188, 203, 213, 1);

	this->setUpPlayer();
	this->setUpTiles();
	this->setUpEnemies();
	this->setUpButtons();
}

SecondLevel::~SecondLevel() {}

void SecondLevel::setUpTiles() {
	this->setUpTerrain();
	this->setUpPlatforms();
	this->setUpTraps();
	this->setUpFruits();
	this->setUpBorder();

	//Set Checkpoint
	this->entityList.push(new Checkpoint(string(PATH) + string("Images/checkpoints/checkpoint.png"), Vector2f(222 * 32, 1140), this->player, this->game));
}

void SecondLevel::setUpTerrain() {
	for (float i = 0; i < 12; i++)
		this->entityList.push(new Tile(string(PATH) + string("Images/blocks/terrain_3.png"), Vector2f((i * 32), 1372), this->player));

	for (float i = 0; i < 3; i++)
		for (float j = 0; j < 12; j++)
			this->entityList.push(new Tile(string(PATH) + string("Images/blocks/terrain_4.png"), Vector2f((j * 32), (i * 32) + 1404), this->player));

	for (float i = 24, j = 0; i < 48; i++){
		this->entityList.push(new Tile(string(PATH) + string("Images/blocks/terrain_3.png"), Vector2f((i * 32), (j * 32) + 988), this->player));
		if (i == 36)
			j++;
	}

	for (float i = 0; i < 15; i++){
		for (float j = 24; j < 48; j++){
			this->entityList.push(new Tile(string(PATH) + string("Images/blocks/terrain_4.png"), Vector2f((j * 32), (i * 32) + 1020), this->player));
			if (i == 0 && j == 36)
				j = 48;
		}
	}

	for (float i = 66, j = 0; i < 90; i++){
		this->entityList.push(new Tile(string(PATH) + string("Images/blocks/terrain_3.png"), Vector2f((i * 32), (j * 32) + 1148), this->player));
		if (i == 77)
			j++;
		if (i == 84)
			j += 2;
	}

	for (float i = 0; i < 10; i++){
		for (float j = 66; j < 90; j++){
			this->entityList.push(new Tile(string(PATH) + string("Images/blocks/terrain_4.png"), Vector2f((j * 32), (i * 32) + 1180), this->player));
			if (i == 0 && (j == 77 || j == 84) || (i == 2 || i == 1) && j == 84)
				j = 90;
		}
	}

	for (float i = 131; i < 187; i++)
		this->entityList.push(new Tile(string(PATH) + string("Images/blocks/terrain_3.png"), Vector2f((i * 32), 1180), this->player));

	for (float i = 0; i < 9; i++)
		for (float j = 131; j < 187; j++)
			this->entityList.push(new Tile(string(PATH) + string("Images/blocks/terrain_4.png"), Vector2f((j * 32), (i * 32) + 1212), this->player));

	for (float i = 218; i < 224; i++)
		this->entityList.push(new Tile(string(PATH) + string("Images/blocks/terrain_3.png"), Vector2f((i * 32), 1180), this->player));

	for (float i = 0; i < 9; i++)
		for (float j = 218; j < 224; j++)
			this->entityList.push(new Tile(string(PATH) + string("Images/blocks/terrain_4.png"), Vector2f((j * 32), (i * 32) + 1212), this->player));
}

void SecondLevel::setUpPlatforms() {
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(450, 1300), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(640, 1228), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(450, 1156), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(640, 1084), this->player));

	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(1616, 988), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(1788, 946), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(1968, 912), this->player));

	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(3008, 1246), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(3216, 1248), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(3392, 1168), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(3591, 1212), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(3728, 1376), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(3856, 1210), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(3904, 1312), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(4080, 1242), this->player));

	this->entityList.push(new Tile(string(PATH) + string("Images/blocks/block_1.png"), Vector2f(4352, 1148), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/blocks/block_1.png"), Vector2f(4384, 1148), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/blocks/block_1.png"), Vector2f(4384, 1116), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/blocks/block_1.png"), Vector2f(5952, 1148), this->player));

	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(4528, 1070), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(4716, 1024), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(4904, 976), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(5064, 912), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(5151, 816), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(5239, 912), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(5399, 976), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(5587, 1024), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(5779, 1070), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(6000, 1070), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(6200, 1180), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(6420, 1180), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(6620, 1180), this->player));
	this->entityList.push(new Tile(string(PATH) + string("Images/platforms/platform_3.png"), Vector2f(6820, 1180), this->player));
}

void SecondLevel::setUpTraps() {
	for (float i = 12; i < 24; i++)
		this->entityList.push(new Trap(string(PATH) + string("Images/traps/spike_32x32.png"), Vector2f((i * 32), 1468), this->player));

	this->entityList.push(new Trap(string(PATH) + string("Images/traps/katana_trap.png"), Vector2f(1184, 988), this->player));
	this->entityList.push(new Trap(string(PATH) + string("Images/traps/katana_trap.png"), Vector2f(1220, 988), this->player));

	for (float i = 48; i < 66; i++)
		this->entityList.push(new Trap(string(PATH) + string("Images/traps/spike_32x32.png"), Vector2f((i * 32), 1468), this->player));

	this->entityList.push(new Trap(string(PATH) + string("Images/traps/katana_trap.png"), Vector2f(2112, 1116), this->player));
	this->entityList.push(new Trap(string(PATH) + string("Images/traps/katana_trap.png"), Vector2f(2150, 1116), this->player));
	this->entityList.push(new Trap(string(PATH) + string("Images/traps/katana_trap.png"), Vector2f(2752, 1212), this->player));

	for (float i = 90; i < 131; i++)
		this->entityList.push(new Trap(string(PATH) + string("Images/traps/spike_32x32.png"), Vector2f((i * 32), 1468), this->player));

	this->entityList.push(new Trap(string(PATH) + string("Images/traps/katana_trap.png"), Vector2f(3700, 1344), this->player));

	for (float i = 138; i < 186; i++)
		this->entityList.push(new Trap(string(PATH) + string("Images/traps/fire_trap.png"), Vector2f((i * 32), 1132), this->player));

	this->entityList.push(new Trap(string(PATH) + string("Images/traps/katana_trap.png"), Vector2f(4715, 990), this->player));
	this->entityList.push(new Trap(string(PATH) + string("Images/traps/katana_trap.png"), Vector2f(4904, 944), this->player));
	this->entityList.push(new Trap(string(PATH) + string("Images/traps/katana_trap.png"), Vector2f(5100, 880), this->player));
	this->entityList.push(new Trap(string(PATH) + string("Images/traps/katana_trap.png"), Vector2f(5202, 880), this->player));
	this->entityList.push(new Trap(string(PATH) + string("Images/traps/katana_trap.png"), Vector2f(5399, 944), this->player));
	this->entityList.push(new Trap(string(PATH) + string("Images/traps/katana_trap.png"), Vector2f(5582, 990), this->player));

	for (float i = 187; i < 218; i++)
		this->entityList.push(new Trap(string(PATH) + string("Images/traps/spike_32x32.png"), Vector2f((i * 32), 1468), this->player));
}

void SecondLevel::setUpFruits() {
	this->fruitsList.clear();

	float positionsY[18] = { 1141, 1141, 1148, 1148, 1148, 1148, 1216, 1344, 1344, 1216, 1212, 875, 914, 956, 1052, 1124, 1196, 1268 };
	float positionsX[18] = { 206.8f, 193.75f, 134.7f, 133.8f, 132.9f, 132.f, 127.5f, 117.5f, 116.7f, 100.50f, 85.f, 61.55f, 55.9f, 50.55f, 20.f, 14.05f, 20.f, 14.05f };

	for (int i = 0;i < 18;i++) {
		this->fruitsList.push(
			new Fruit(
				string(PATH) + string("Images/fruits/apple.png"), Vector2f((positionsX[i] * 32), positionsY[i]), this->player, &this->fruitsList, &this->appleCounter
			)
		);
	}
}

void SecondLevel::setUpBorder() {
	for (float i = 0; i < 190; i++) // Set border roof
		this->entityList.push(new Tile(string(PATH) + string("Images/blocks/rock.png"), Vector2f((i * 32), 0.f), this->player));

	for (float i = 0.3f; i < 46.3f; i++) { // Set border wall
		this->entityList.push(new Tile(string(PATH) + string("Images/blocks/rock_wall.png"), Vector2f(-16.f, (i * 32)), this->player));
		this->entityList.push(new Tile(string(PATH) + string("Images/blocks/rock_wall.png"), Vector2f((223.5 * 32), (i * 32)), this->player));
	}
}

void SecondLevel::setUpEnemies() {
	this->entityList.push(new BasicEnemy(string(PATH) + string("Images/enemies/turtle.png"), Vector2f(967, 962), this->player, -1, 6));
	this->entityList.push(new BasicEnemy(string(PATH) + string("Images/enemies/turtle.png"), Vector2f(1386, 994), this->player, -1, 4));
	this->entityList.push(new BasicEnemy(string(PATH) + string("Images/enemies/duck.png"), Vector2f(2587, 1149), this->player, -1, 3));

	this->entityList.push(new Boss(string(PATH) + string("Images/enemies/three_boss.png"), Vector2f(219 * 32, 1155), this->player, this->game->getWindow()));
}

const Color SecondLevel::getBackgroundColor() {
	return backgroundColor;
}

