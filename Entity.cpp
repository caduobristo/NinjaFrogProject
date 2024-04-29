#include "Entity.h"

Entity::Entity() {
	this->collider = nullptr;
}

Entity::Entity(const string texture, Vector2f pos) {
	if (!this->texture.loadFromFile(texture)) {
		throw "Error::Failed to load sprites";
	}

	this->texture.setSmooth(true);

	this->body.setTexture(&this->texture);
	this->body.setSize(Vector2f(float(this->texture.getSize().x),float(this->texture.getSize().y)));
	this->body.setPosition(pos);
	this->body.setOrigin(this->body.getSize() / 2.0f);

	this->collider = new Collider(this->body);
}

Entity::~Entity() {
	delete this->collider;
}
	
void Entity::draw(RenderWindow* window) {
	window->draw(body);
}

void Entity::update() {

}

void Entity::setPos(Vector2f pos) {
	this->body.setPosition(pos);
}

RectangleShape Entity::getBody() {
	return this->body;
}

Collider* Entity::getCollider() {
	return collider;
}

