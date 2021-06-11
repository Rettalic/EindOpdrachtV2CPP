#pragma  once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Vector2.h"
#include "time.h"

class Player {
public:
    Player(int windowW, int windowH);
    ~Player();

    void Move(float dt); //delta time
    void borderCheck();

    sf::CircleShape Draw();
    Vector2* position;

    float velocity;
    float friction = 0.6;
    float mass = 1;
    float extraSpeed = 1.4;
    int playerSize = 30;

private:
    float posX = 1280/2;
    float posY = 100;

    float bottomPos = 60;
    float moveSpeed = 800;

    sf::CircleShape shape;

    int wW;
    int wH;
};