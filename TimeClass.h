#pragma once
#include <SFML/Graphics.hpp>

class TimeClass {
public:
    float dt;
    sf::Clock clock;
    TimeClass();
    ~TimeClass();
    void UpdateDT();
};