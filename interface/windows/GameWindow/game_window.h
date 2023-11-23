#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class GameWindow {
public:
    GameWindow(sf::RenderWindow &window);

    void draw(sf::RenderWindow &window);

    bool handleEvent(sf::Event &event, sf::RenderWindow &window);

private:
    sf::Texture backgroundImageTexture;
    sf::Sprite backgroundImageSprite;
};

