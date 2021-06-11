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
    int enimSize = 16;

private:
    int wW;
    float posX = rand() % 1280;
    float posY = -10;
    float moveSpeed = (rand() % 25) * 0.002;
    float fallSpeed = (rand() % 25) * 0.002;
    sf::CircleShape shape;
};
