#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Vector2.h"

class Text {
public:
    Text(std::string text, sf::Color color, int fontSize, Vector2 position);
    ~Text();
    sf::Text returnText();
    sf::Text inputText;
};
