#include "Player.h"

Player::Player(int windowWidth, int windowHeight) {
    wW = windowWidth;
    wH = windowHeight;
}

Player::~Player() {

}

void Player::Move(float dt, float destination) {
    float distance = destination - posX;
    float acceleration = distance/moveSpeed;
    posX += acceleration;
    posY = wH - bottomPos;
    position = new Vector2(posX, posY);
}

sf::CircleShape Player::Draw() {
    sf::CircleShape shape(playerSize);
    shape.setFillColor(sf::Color::Cyan);
    shape.setPosition(posX, posY);
    return shape;
}
