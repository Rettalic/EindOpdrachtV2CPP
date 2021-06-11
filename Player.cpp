#include "Player.h"

Player::Player(int windowWidth, int windowH) {
    wW = windowWidth;
    wH = windowH;
    posY = wH - bottomPos;
    position = new Vector2(posX, posY);
}

Player::~Player() {

}

void Player::Move(float dt) {
    float acceleration = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        acceleration += moveSpeed * dt * extraSpeed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        acceleration += -moveSpeed * dt * extraSpeed;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        velocity = 0;
        acceleration = 0;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
    extraSpeed = 3.0;

    }
    else{
     extraSpeed = 1.0;
    }


   //Deze formule komt uit de les van Vincent
    velocity = (1/friction) * (std::pow(2.71828,-friction/mass*dt))*(friction*velocity+mass*acceleration)-(mass*acceleration/friction);
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
        *position = *position + *new Vector2(-wW, 0); //brengt speler naar andere kant van scherm waardoor het lijkt alsof je teleporteerd
    }
    if (position->GetX() < (0.f - playerSize * 2))
    {
        *position = *position + *new Vector2(wW, 0);
    }
}