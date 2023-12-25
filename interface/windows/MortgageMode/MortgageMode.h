#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../../../sources/game.h"

class MortgageMode {
public:
    MortgageMode() = default;

    void loadBuyModeWindow(sf::RenderWindow& window);

    void draw(sf::RenderWindow &window, sf::Event& event);

    bool handleEvent(sf::Event &event, sf::RenderWindow &window);

    void setGame(Game& _game, GameMove& _player);

private:
    Game game;

    sf::Font font1;
    sf::Font font2;

    sf::Texture mortgageCardTexture;
    sf::Sprite mortgageCardSprite;

};

