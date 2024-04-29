#include "Checkpoint.h"
#include "Game.h"

Checkpoint::Checkpoint() :Entity() {
	this->player = nullptr;
	this->game = nullptr;
}

Checkpoint::Checkpoint(string texture, Vector2f pos, Player* player, Game* game) : Entity(texture, pos) {
	this->player = player;
	this->game = game;
}

Checkpoint::~Checkpoint() {}

void Checkpoint::update() {
	if (this->getCollider()->checkCollision(this->player->getCollider(), this->player->getDirection(), 1.0f)) {
		this->player->onCollision();

		if (this->game->getCurrentLevel()->getBackgroundColor() == Color(220, 174, 193, 1)) 
			this->game->setCurrentLevel(new SecondLevel(this->game));
		else {
			this->game->setCurrentLevel(nullptr);

			View view(Vector2f(0.0f, 0.0f), Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
			view.setCenter(Vector2f(400.f, 250.0f));

			this->game->getWindow()->setView(view);
		}

	}
}
