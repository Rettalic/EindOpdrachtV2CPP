#include "Enemy.h"

Enemy::Enemy(int windowW) {
    wW = windowW;
    position = new Vector2(posX, posY);
}

Enemy::~Enemy() { }

void Enemy::Move(float dt) {
    velocityX = moveSpeed;
    velocityY = -fallSpeed;
    Vector2* move = new Vector2(velocityX,-velocityY);
    *position = *position + *move;
    BorderCheck();

}

sf::CircleShape Enemy::Draw(float dt) {
    Move(dt);
    sf::CircleShape shape(enimSize);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(position->GetX(), position->GetY());
    return shape;
}

void Enemy::BorderCheck() {
    if (position->GetX() > wW)
    {
        velocityX = velocityX *-1;
        moveSpeed = moveSpeed *-1;
    }
    if (position->GetX() < 0.f)
    {
        velocityX = velocityX *-1;
        moveSpeed = moveSpeed *-1;
    }
}