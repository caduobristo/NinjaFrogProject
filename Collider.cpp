#include "Collider.h"

Collider::Collider(): body(body){}

Collider::Collider(RectangleShape& body): body(body) {}

Collider::~Collider() {}

void Collider::move(float x, float y) {
	this->body.move(x, y);
}

bool Collider::checkCollision(Collider* other, Vector2f* direction, float push) {
	Vector2f otherPosition = other->getPosition();
	Vector2f otherHalfSize = other->getHalfSize();
	Vector2f position = this->getPosition();
	Vector2f halfSize = this->getHalfSize();

	float deltaX = otherPosition.x - position.x;
	float deltaY = otherPosition.y - position.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + halfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + halfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) {
		push = min(max(push,0.0f),1.0f);

		if (intersectX > intersectY) {
			if (deltaX > 0.0f) {
				this->move(intersectX * (1.0f - push), 0.0f);
				other->move(-intersectX * push,0.0f);

				direction->x = 1.0f;
				direction->y = 0.0f;
			}
			else {
				this->move(-intersectX * (1.0f - push), 0.0f);
				other->move(intersectX * push, 0.0f);

				direction->x = -1.0f;
				direction->y = 0.0f;
			}

		}
		else {
			if (deltaY > 0.0f) {
				this->move(0.0f,intersectY * (1.0f - push));
				other->move(0.0f ,-intersectY * push);

				direction->x = 0.0f;
				direction->y = 1.0f;
			}
			else {
				this->move(0.0f,-intersectY * (1.0f - push));
				other->move(0.0f,intersectY * push);

				direction->x = 0.0f;
				direction->y = -1.0f;
			}
		}

		return true;
	}

	return false;
}

Vector2f Collider::getPosition() {
	return this->body.getPosition();
}

Vector2f Collider::getHalfSize(){
	return this->body.getSize() / 2.0f;
}



