#include "Player.h"

Player::Player(int windowW, int windowH) {
    wW = windowW;
    wH = windowH;
    posY = wH - bottemPos;
    position = new Vector2(posX, posY);
}

Player::~Player() {

}

void Player::Move(float dt) {
    float acceleration = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        acceleration += moveSpeed * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        acceleration += -moveSpeed * dt;
    }
    //velocity = (1/drag coefficient) * (e^-dragC/m*ΔT)*(dragC*velocity+mass*a)-(mass*a/dragC)
    velocity = (1/frictionCoef) * (std::pow(2.71828,-frictionCoef/mass*dt))*(frictionCoef*velocity+mass*acceleration)-(mass*acceleration/frictionCoef);
    Vector2* move = new Vector2(velocity,0);
    *position = *position + *move;
    borderCheck();
}

sf::CircleShape Player::Draw() {
    sf::CircleShape shape(playerSize);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(position->GetX(), position->GetY());
    return shape;
}

void Player::borderCheck() {
    if (position->GetX() > wW)
    {
        *position = *position + *new Vector2(-wW, 0);
    }
    if (position->GetX() < (0.f - playerSize * 2))
    {
        *position = *position + *new Vector2(wW, 0);
    }
}