#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../../../sources/game.h"

class CharacterWindow {
public:
    CharacterWindow(sf::RenderWindow &window);

    void draw(sf::RenderWindow &window);

    void handleEvent(sf::Event &event, sf::RenderWindow &window);

private:
    int playersCount = 0;

};

