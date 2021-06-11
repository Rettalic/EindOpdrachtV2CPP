#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Vector2.h"

class Enemy {
public:
    Enemy(int windowW);
    ~Enemy();
    void Move(float dt);
    sf::CircleShape Draw(float dt);
    void BorderCheck();
    Vector2* position;
    float velocityX;
    float velocityY;
    float frictionCoef = 1;
    float mass = 1;
    int enimSize = 16;

private:
    int wW;
    float posX = rand() % 1280;
    float posY = -40;
    float moveSpeed = rand() % 25;
    float fallSpeed = rand() % 25;
    float minSpeed = 10;
    sf::CircleShape shape;
};
