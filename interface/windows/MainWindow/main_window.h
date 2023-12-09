#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class MainWindow {
public:
    MainWindow() = default;

    void loadMainWindow(sf::RenderWindow& window);

    void draw(sf::RenderWindow &window);

    int handleEvent(sf::Event &event, sf::RenderWindow &window);

private:
    sf::Texture mainScreenTexture;
    sf::Sprite mainScreenSprite;

    sf::Texture buttonStartGameTexture;
    sf::Sprite buttonStartGameSprite;

    sf::Texture buttonExitTexture;
    sf::Sprite buttonExitSprite;
};
