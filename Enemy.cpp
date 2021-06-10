#include "Enemy.h"

Enemy::Enemy(int windowW) {
    windowWidth = windowW;
}

Enemy::~Enemy() {

}

void Enemy::Move(float dt) {
    if (downSpeed <= minSpeed)
    {
        downSpeed = rand() % 50;
    }
    if (moveSpeed == 0)
    {
        moveSpeed = rand() % 50;
    }

    posY += downSpeed * dt;
    posX += moveSpeed * dt;
    position = new Vector2(posX, posY);
}

sf::CircleShape Enemy::Draw(float dt) {
    Move(dt);
    sf::CircleShape shape(sizeEnemy);
    shape.setFillColor(sf::Color::Red);
    BorderCheck();
    shape.setPosition(posX, posY);
    return shape;
}

void Enemy::BorderCheck() {
    if (posX > windowWidth)
    {
        moveSpeed = moveSpeed *-1;
    }
    if (posX < 0.f)
    {
        moveSpeed = moveSpeed *-1;
    }
}