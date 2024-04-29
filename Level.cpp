#include "Level.h"
#include "Game.h"

Level::Level() {
	this->game = nullptr;
	this->player = nullptr;
	this->appleCounter = 0;
}

Level::Level(Game* game) {
	this->game = game;
	this->player = nullptr;
	this->appleCounter = 0;
}

Level::~Level(){
	this->entityList.clear();
	this->fruitsList.clear();
	this->buttonsList.clear();
}

void Level::draw() {
	this->entityList.draw(this->game->getWindow());
	this->fruitsList.draw(this->game->getWindow());
	this->buttonsList.draw(this->game->getWindow());
		
	this->game->getWindow()->draw(this->appleCounterText);
}

void Level::update(View* view) {
	this->entityList.update();

	for (int i = 0;i < this->fruitsList.getSize();i++) 
		this->fruitsList.getItem(i)->update();
	
	this->buttonsList.getItem(0)->setPos(Vector2f(this->player->getBody().getPosition().x + 480.f, this->player->getBody().getPosition().y -325.f));
	this->buttonsList.getItem(1)->setPos(Vector2f(this->player->getBody().getPosition().x + 460.f, this->player->getBody().getPosition().y - 325.f));
	this->buttonsList.getItem(2)->setPos(Vector2f(this->player->getBody().getPosition().x - 270.f, this->player->getBody().getPosition().y -325.f));
	this->appleCounterText.setPosition(Vector2f(this->player->getBody().getPosition().x + -258.f, this->player->getBody().getPosition().y - 335.f));
	this->appleCounterText.setString(to_string(this->appleCounter));

	if(Mouse::isButtonPressed(Mouse::Left))
		this->checkClickedButtons();

	view->setCenter(Vector2f(player->getBody().getPosition().x + 100, player->getBody().getPosition().y - 100));
}

void Level::setUpPlayer() {
	this->player = new Player(string(PATH) + string("Images/characters/idle.png"), Vector2f(3 * 32, 38 * 32));
	this->entityList.push(this->player);
}

void Level::setUpButtons() {
	Vector2f exitButtonPosition(this->player->getBody().getPosition().x + 480.f, this->player->getBody().getPosition().y -325.f);
	Vector2f restartButtonPosition(this->player->getBody().getPosition().x + 460.f, this->player->getBody().getPosition().y - 325.f);
	Vector2f appleCounterTilePosition(this->player->getBody().getPosition().x + -270.f, this->player->getBody().getPosition().y - 325.f);
	Vector2f appleCounterTextPosition(this->player->getBody().getPosition().x + - 258.f, this->player->getBody().getPosition().y - 335.f);

	this->buttonsList.push(new Tile(string(PATH) + string("Images/buttons/Close.png"), exitButtonPosition, nullptr));
	this->buttonsList.push(new Tile(string(PATH) + string("Images/buttons/Restart.png"), restartButtonPosition, nullptr));
	this->buttonsList.push(new Tile(string(PATH) + string("Images/fruits/apple.png"), appleCounterTilePosition, nullptr));

	if (!this->font.loadFromFile(string(PATH) + string("Images/fonts/Bungee-Regular.ttf"))) 
		throw "Error::Failed to load fonts";

	this->appleCounterText = Text("0", font, 14);
	this->appleCounterText.setPosition(appleCounterTextPosition);
	this->appleCounterText.setFillColor(Color::Black);
}

const Color Level::getBackgroundColor() {
	return Color::White;
}

void Level::checkClickedButtons() {
	Vector2f mouse = this->game->getWindow()->mapPixelToCoords(Mouse::getPosition(*this->game->getWindow()));

	FloatRect exitButtonBounds = this->buttonsList.getItem(0)->getBody().getGlobalBounds();
	FloatRect restartButtonBounds = this->buttonsList.getItem(1)->getBody().getGlobalBounds();

	if (exitButtonBounds.contains(mouse)) {
		this->game->setCurrentLevel(nullptr);

		View view(Vector2f(0.0f, 0.0f), Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
		view.setCenter(Vector2f(400.f,250.0f));

		this->game->getWindow()->setView(view);
	}

	if (restartButtonBounds.contains(mouse)) {
		this->player->setCurrentPosition(Vector2f(96, 38 * 32));
		this->setUpFruits();
		this->appleCounter = 0;
		this->appleCounterText.setString("0");
	}
}