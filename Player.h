#pragma  once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "time.h"
#include "Vector2.h"

class Player {
public:
    Player(int windowWidth, int windowHeight);
    ~Player();

    void Move(float dt, float destination);
    sf::CircleShape Draw();
    Vector2* position;
    int playerSize = 20;

private:
    float posX = 200;
    float posY = 800;
    float bottomPos = 50;
    float moveSpeed = 500;
    sf::CircleShape shape;
    int wW;
    int wH;
};


