#pragma once

#include "SFML/Graphics.hpp"

void set_text(sf::Text &text, sf::Font &font, std::string &str, int size, sf::Color color,
                              sf::Text::Style style, float x, float y);