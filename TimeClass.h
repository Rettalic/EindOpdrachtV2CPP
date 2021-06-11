#pragma once
#include <SFML/Graphics.hpp>




class TimeClass {
public:
    TimeClass();
    ~TimeClass();

    float deltaTime;
    sf::Clock clock;

    void UpdateDeltaTime();
};