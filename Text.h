#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Vector2.h"


class TextInput {
public:
    TextInput(std::string text, sf::Color color, int fontSize, Vector2 position);
    ~TextInput();

    sf::Text returnText(std::string text);
    sf::Text inputText;
    sf::Font font;
};