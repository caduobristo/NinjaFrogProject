#include "Menu.h"
#include "Game.h"

Menu::Menu() {
	this->game = nullptr;
	this->currentLevel = '1';

	this->initButtons();
	this->initFont();
	this->initTiles();
}

Menu::~Menu() {
	this->tileList.clear();
	this->buttonsList.clear();
}

void Menu::setGame(Game* game) {
	this->game = game;

	this->window = this->game->getWindow();
}

void Menu::draw() {
	this->tileList.draw(this->window);

	this->renderTitle();
	this->renderButtons();
}

void Menu::renderTitle() {  
	RectangleShape box(Vector2f(200, 48));
	Text text1("Ninja", font, 22);
	Text text2("Frog", font, 22);

	box.setOutlineThickness(1);
	box.setOutlineColor(Color::Black);
	box.setPosition(Vector2f(300, 73));

	text1.setPosition(Vector2f(325, 83));
	text1.setFillColor(Color(10, 5, 36));

	text2.setPosition(Vector2f(410, 83));
	text2.setFillColor(Color(31, 101, 34));

	this->window->draw(box);
	this->window->draw(text1);
	this->window->draw(text2);
}

void Menu::renderButtons() {
	RectangleShape levelBox(Vector2f(125, 40));
	Text text("Play", font, 16);

	text.setPosition(Vector2f(382, 187));
	text.setFillColor(Color::Black);

	this->window->draw(this->playButton);
	this->window->draw(text);

	levelBox.setSize(Vector2f(125, 40));
	levelBox.setPosition(Vector2f(333, 232));
	levelBox.setOutlineThickness(1);
	levelBox.setOutlineColor(Color::Black);

	string level = "Level ";
	level += this->currentLevel;

	text.setString(level);
	text.setPosition(Vector2f(362, 242));

	this->window->draw(levelBox);
	this->window->draw(text);
	
	text.setString("Exit");
	text.setPosition(Vector2f(373, 299));

	this->window->draw(this->exitButton);
	this->window->draw(text);

	this->window->draw(this->nextLevelButton);
	this->window->draw(this->previousLevelButton);

	this->buttonsList.getItem(0)->draw(window);
	this->buttonsList.getItem(1)->draw(window);
	this->buttonsList.getItem(2)->draw(window);
}

void Menu::update() {
	this->checkMouseIsOverButtons();
	
	if(Mouse::isButtonPressed(Mouse::Button::Left))
		this->checkClickedButtons();
}

void Menu::initButtons() {
	this->playButton = RectangleShape(Vector2f(125, 40));
	this->playButton.setPosition(Vector2f(333, 177));
	this->playButton.setOutlineThickness(1);
	this->playButton.setOutlineColor(Color::Black);

	this->nextLevelButton = RectangleShape(Vector2f(40, 40));
	this->nextLevelButton.setPosition(Vector2f(459, 232));
	this->nextLevelButton.setOutlineThickness(1);
	this->nextLevelButton.setOutlineColor(Color::Black);

	this->previousLevelButton = RectangleShape(Vector2f(40, 40));
	this->previousLevelButton.setPosition(Vector2f(292, 232));
	this->previousLevelButton.setOutlineThickness(1);
	this->previousLevelButton.setOutlineColor(Color::Black);

	this->exitButton = RectangleShape(Vector2f(125, 40));
	this->exitButton.setPosition(Vector2f(333, 288));
	this->exitButton.setOutlineThickness(1);
	this->exitButton.setOutlineColor(Color::Black);

	this->buttonsList.push(new Tile(string(PATH) + string("Images/buttons/Play.png"), Vector2f(365, 197), nullptr));
	this->buttonsList.push(new Tile(string(PATH) + string("Images/buttons/Next.png"), Vector2f(478, 252), nullptr));
	this->buttonsList.push(new Tile(string(PATH) + string("Images/buttons/Previous.png"), Vector2f(313, 252), nullptr));
}

void Menu::initFont() {
	if (!this->font.loadFromFile(string(PATH) + string("Images/fonts/Bungee-Regular.ttf"))) {
		throw "Error::Failed to load fonts";
	}
}

void Menu::initTiles() {
	for (float i = 0;i < 17;i++)
		for (float j = 0;j < 26;j++)
			this->tileList.push(new Tile(string(PATH) + string("Images/background/Purple.png"), Vector2f(j * 32, i * 32), nullptr));
}

void Menu::checkMouseIsOverButtons() {
	Vector2f mouse = this->window->mapPixelToCoords(Mouse::getPosition(*window));

	FloatRect playButtonBounds = this->playButton.getGlobalBounds();
	FloatRect nextLevelButtonBounds = this->nextLevelButton.getGlobalBounds();
	FloatRect previousLevelButtonBounds = this->previousLevelButton.getGlobalBounds();
	FloatRect exitButtonBounds = this->exitButton.getGlobalBounds();

	if(playButtonBounds.contains(mouse))
		playButton.setFillColor(Color(204,204,204));
	else
		playButton.setFillColor(Color::White);

	if (nextLevelButtonBounds.contains(mouse))
		nextLevelButton.setFillColor(Color(204, 204, 204));
	else
		nextLevelButton.setFillColor(Color::White);

	if (previousLevelButtonBounds.contains(mouse))
		previousLevelButton.setFillColor(Color(204, 204, 204));
	else
		previousLevelButton.setFillColor(Color::White);

	if (exitButtonBounds.contains(mouse))
		exitButton.setFillColor(Color(204, 204, 204));
	else
		exitButton.setFillColor(Color::White);
}

void Menu::checkClickedButtons() {
	Vector2f mouse = window->mapPixelToCoords(Mouse::getPosition(*window));

	FloatRect playButtonBounds = this->playButton.getGlobalBounds();
	FloatRect nextLevelButtonBounds = this->nextLevelButton.getGlobalBounds();
	FloatRect previousLevelButtonBounds = this->previousLevelButton.getGlobalBounds();
	FloatRect exitButtonBounds = this->exitButton.getGlobalBounds();

	if (playButtonBounds.contains(mouse))
		setLevel(currentLevel);

	if (nextLevelButtonBounds.contains(mouse))
		this->currentLevel = '2';

	if (previousLevelButtonBounds.contains(mouse))
		this->currentLevel = '1';

	if (exitButtonBounds.contains(mouse))
		this->window->close();
}

void Menu::setLevel(char level) {
	if (level == '1')
		game->setCurrentLevel(new FirstLevel(this->game));

	if (level == '2')
		game->setCurrentLevel(new SecondLevel(this->game));
}