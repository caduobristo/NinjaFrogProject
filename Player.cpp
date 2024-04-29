#include "Player.h"

Player::Player() {
	this->jumpHeight = 0.0f;
	this->canJump = false;
}

Player::Player(string texture, Vector2f pos): 
Entity(texture,pos) {
	this->jumpHeight = 0.0f;
	this->canJump = true;
}

Player::~Player() {

}

void Player::update() {
	if (Keyboard::isKeyPressed(Keyboard::D)) 
		this->velocity.x += SPEED;
	if(Keyboard::isKeyPressed(Keyboard::D) && !canJump)
		this->velocity.x += SPEED -4.5f;
	if (Keyboard::isKeyPressed(Keyboard::A))
		this->velocity.x -= SPEED;
	if (Keyboard::isKeyPressed(Keyboard::A) && !canJump)
		this->velocity.x -= SPEED -4.5f;

	if ((Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::W)) && this->canJump) {
		this->canJump = false;

		jumpHeight = 15.0f;
	}

	if (this->direction.y == 0) // Check if player is in the air
		canJump = false;

	if (jumpHeight > 0.0f)
		jumpHeight -= 0.5f;

	this->velocity.y += jumpHeight * -1;
	this->velocity.y += 3.5f; // Gravity

	this->move();

	this->velocity.x = 0.0f;
	this->velocity.y = 0.0f;
}

void Player::move() {
	this->body.move(this->velocity);
}

void Player::onCollision() {
	if (this->direction.x != 0.0f)
		velocity.x = 0.0f;

	if (this->direction.y != 0.0f) 
		velocity.y = 0.0f;

	if (this->direction.y < 0.0f) 
		canJump = true;
}

void Player::setCurrentPosition(Vector2f pos) {
	this->body.setPosition(pos);
}

Vector2f* Player::getDirection() {
	return &direction; 
}

