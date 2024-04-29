#include "Game.h"

Game::Game() {
    this->currentLevel = nullptr;

    this->window = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Game!");
    this->window->setFramerateLimit(120);
    this->mainMenu.setGame(this);

    View view(Vector2f(0.f, 0.f), Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));

    while (this->window->isOpen()){
        Event event;
        
        while (this->window->pollEvent(event)){
            if (event.type == Event::Closed)
                this->window->close();
        }
        
        if (this->currentLevel == nullptr) {
            this->window->clear();

            this->mainMenu.draw();
            this->mainMenu.update();
        }
        else {
            this->window->setView(view);
            this->window->clear(this->currentLevel->getBackgroundColor());

            this->currentLevel->draw();
            this->currentLevel->update(&view);
        }

        this->window->display();
    }
}

Game::~Game(){
    delete window;
}

void Game::setCurrentLevel(Level* level) {
    this->currentLevel = level;
}

Level* Game::getCurrentLevel() {
    return this->currentLevel;
}

RenderWindow* Game::getWindow() {
    return this->window;
}
