#include "EntityList.h"

EntityList::EntityList() {}

EntityList::~EntityList() {
	list.clear();
}

void EntityList::push(Entity* entity) {
	list.push(entity);
}

void EntityList::remove(Entity* entity) {
	this->list.remove(entity);
}

Entity* EntityList::getItem(int pos) { 
	return this->list.getItem(pos); 
}

void EntityList::draw(RenderWindow* window) {
	Element<Entity>* currentEntity = list.getFirstElement();

	for (int i = 0;i < list.getSize();i++) {
		currentEntity->getElementInfo()->draw(window);
		currentEntity = currentEntity->getNextElement();
	}
}

void EntityList::update() {
	Element<Entity>* currentEntity = list.getFirstElement();

	for (int i = 0;i < list.getSize();i++) {
		currentEntity->getElementInfo()->update();
		currentEntity = currentEntity->getNextElement();
	}
}

void EntityList::clear() {
	list.clear();
}

int EntityList::getSize() {
	return this->list.getSize();
}
