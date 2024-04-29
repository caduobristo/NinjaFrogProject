#include "BasicEnemy.h"

BasicEnemy::BasicEnemy() {
	this->player = nullptr;
	this->direction = 1;
	this->distance = 0;
}

BasicEnemy::BasicEnemy(string texture, Vector2f pos, Player* player, int direction, int distance) : Entity(texture, pos) {
	this->player = player;
	this->initialPos = pos;
	this->direction = direction;
	this->distance = distance;

	if (direction == -1)
		this->body.setScale(-1,1);
}

BasicEnemy::~BasicEnemy() {
	this->player = nullptr;
}

void BasicEnemy::update() {
	this->move();

	if (this->getCollider()->checkCollision(this->player->getCollider(), this->player->getDirection(), 1.0f)) {
		this->player->onCollision();
		this->player->setCurrentPosition(Vector2f(96, 38 * 32));
	}
}

void BasicEnemy::move() {
	if (abs(this->initialPos.x - this->body.getPosition().x) >= (this->distance * 32)) {
		this->direction *= -1;
		this->body.setScale(this->body.getScale().x * -1, 1);
	}

	this->body.move(Vector2f(1.5f * direction,0));
}

