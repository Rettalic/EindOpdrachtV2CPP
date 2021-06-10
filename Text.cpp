#include "Text.h"

Text::Text(std::string text, sf::Color color, int fontSize, Vector2 position)
{
    sf::Text inputText;
    sf::Font font;
    font.loadFromFile("../Font/Starjhol.ttf");
    inputText.setString(text);
    inputText.setFont(font);
    inputText.setCharacterSize(fontSize);
    inputText.setFillColor(color);
    inputText.setPosition(position.GetX(), position.GetY());
}

Text::~Text() {

}

sf::Text Text::returnText() {
    sf::Text returnText = inputText;
    return returnText;
}