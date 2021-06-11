#include "Text.h"

TextInput::TextInput(std::string text, sf::Color color, int fontSize, Vector2 position)
{
    inputText = sf::Text();
    font = sf::Font();
    font.loadFromFile("../textures/ARCADE_I.ttf");
    inputText.setString(text);
    inputText.setFont(font);
    inputText.setCharacterSize(fontSize);
    inputText.setFillColor(color);
    inputText.setPosition(position.GetX(), position.GetY());
}

TextInput::~TextInput() {

}

sf::Text TextInput::returnText(std::string text) {
    inputText.setString(text);
    sf::Text returnText = inputText;
    return returnText;
}