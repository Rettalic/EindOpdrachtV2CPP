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
    float sizeEnemy = 10.0f;

private:
    int windowWidth;
    float posX = rand() % 1280;
    float posY = -10;

    float moveSpeed = rand() % 50;
    float downSpeed = rand() % 50;

    int   minSpeed = 25;

    sf::CircleShape shape;
};



