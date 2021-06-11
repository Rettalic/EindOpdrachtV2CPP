#pragma  once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Vector2.h"
#include "time.h"


class Player {
public:
    Player(int windowW, int windowH);
    ~Player();
    void Move(float dt);
    void borderCheck();
    sf::CircleShape Draw();
    Vector2* position;
    float velocity;
    float frictionCoef = 0.6;
    float mass = 1;
    float extraSpeed = 1.0;
    int playerSize = 30;

private:
    float posX = 1280/2;
    float posY = 100;
    float bottemPos = 60;
    float moveSpeed = 800;
    sf::CircleShape shape;
    int wW;
    int wH;
};