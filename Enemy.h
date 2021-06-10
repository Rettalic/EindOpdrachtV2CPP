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
    int sizeEnemy = 14;

private:
    int windowWidth;
    float posX = rand() % 1280; // Waar spawn je de Enemies op de X as
    float posY = -30;

    float moveSpeed = rand() % 75;
    float downSpeed = rand() % 75;

    int   minSpeed = 20;

    sf::CircleShape shape;
};



