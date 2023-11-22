#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class MainWindow {
public:
    MainWindow(sf::RenderWindow &window);

    void draw(sf::RenderWindow &window);

    bool handleEvent(sf::Event &event, sf::RenderWindow &window);

private:
    sf::Texture mainScreenTexture;
    sf::Sprite mainScreenSprite;

    sf::Texture buttonStartGameTexture;
    sf::Sprite buttonStartGameSprite;

};
