#include "Projectile.h"

Projectile::Projectile() {
	this->player = nullptr;
}

Projectile::Projectile(string texture, Vector2f pos, Player* player) : Entity(texture, pos) {
	this->player = player;
	this->initialPos = pos;
}

Projectile::~Projectile() {
	this->player = nullptr;
}

void Projectile::update() {
	this->body.move(Vector2f(-4.f, 0.f));

	if (this->getCollider()->checkCollision(this->player->getCollider(), this->player->getDirection(), 1.0f)) {
		this->player->onCollision();
		this->player->setCurrentPosition(Vector2f(96, 38 * 32));
	}
}