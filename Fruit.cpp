#include "Fruit.h"

Fruit::Fruit() :Entity() {
	this->player = nullptr;
	this->fruitList = nullptr;
	this->appleCounter = nullptr;
}

Fruit::Fruit(string texture, Vector2f pos, Player* player, EntityList* fruitList, int* appleCounter) : Entity(texture, pos) {
	this->player = player;
	this->fruitList = fruitList;
	this->appleCounter = appleCounter;
}

Fruit::~Fruit() {
	this->player = nullptr;
	this->fruitList = nullptr;
	this->appleCounter = nullptr;
}

void Fruit::update() {
	if (this->getCollider()->checkCollision(this->player->getCollider(), this->player->getDirection(), 1.0f)) {
		this->fruitList->remove(this);
		*this->appleCounter += 1;
	}
}