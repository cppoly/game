#include "text.h"

void set_text(sf::Text &text, sf::Font &font, std::string &str, int size, sf::Color color,
              sf::Text::Style style, float x, float y) {
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setStyle(style);
    text.setPosition(x, y);
}