#include "Boss.h"

Boss::Boss() {
	this->player = nullptr;
	this->window = nullptr;
}

Boss::Boss(string texture, Vector2f pos, Player* player, RenderWindow* window) : Entity(texture, pos) {
	this->player = player;
	this->window = window;
	this->body.setScale(-1,1);
	this->projectile = new Projectile(
		string(PATH) + string("Images/enemies/Bullet.png"), Vector2f(this->body.getPosition().x -16, this->body.getPosition().y), this->player
	);
}

Boss::~Boss() {
	this->player = nullptr;
	delete projectile;
}

void Boss::update() {
	if (this->getCollider()->checkCollision(this->player->getCollider(), this->player->getDirection(), 1.0f)) {
		this->player->onCollision();
		this->player->setCurrentPosition(Vector2f(96, 38 * 32));
	}

	this->projectile->draw(this->window);
	this->projectile->update();

	if (abs(this->body.getPosition().x - this->projectile->getBody().getPosition().x) >= 32 * 32)
		this->projectile->setPos(Vector2f(this->body.getPosition().x - 16, this->body.getPosition().y));
}
