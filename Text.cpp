#include "Text.h"

TextInput::TextInput(std::string text, sf::Color color, int fontSize, Vector2 position)
{
    font = sf::Font();
    font.loadFromFile("../textures/ARCADE_I.ttf"); //load file van project, specifieke map
    inputText = sf::Text();

    inputText.setString(text);
    inputText.setFont(font);
    inputText.setFillColor(color);
    inputText.setCharacterSize(fontSize);
    inputText.setPosition(position.GetX(), position.GetY());
}

TextInput::~TextInput() { }

sf::Text TextInput::returnText(std::string text) {
    inputText.setString(text);
    sf::Text returnText = inputText;
    return returnText;
}