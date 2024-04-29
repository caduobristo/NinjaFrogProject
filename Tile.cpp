#include "Tile.h"

Tile::Tile():Entity(){
	this->player = nullptr;
}

Tile::Tile(string texture, Vector2f pos, Player* player): Entity(texture, pos) {
	this->player = player;
}

Tile::~Tile(){}

void Tile::update() {
	if (this->player != nullptr && this->getCollider()->checkCollision(this->player->getCollider(), this->player->getDirection(), 1.0f))
		this->player->onCollision();
}

