#include "Trap.h"

Trap::Trap() :Entity() {
	this->player = nullptr;
}

Trap::Trap(string texture, Vector2f pos, Player* player) : Entity(texture, pos) {
	this->player = player;
}

Trap::~Trap() {}

void Trap::update() {
	if (this->getCollider()->checkCollision(this->player->getCollider(), this->player->getDirection(), 1.0f)) {
		this->player->onCollision();
		this->player->setCurrentPosition(Vector2f(96, 38 * 32));
	}
}
