#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../../../sources/game.h"
#include "../../text/text.h"

class PayWindow {
public:
    PayWindow() = default;

    void loadBuyModeWindow(sf::RenderWindow& window);

    void draw(sf::RenderWindow &window, sf::Event& event);

    bool handleEvent(sf::Event &event, sf::RenderWindow &window);

    void setGame(Game& _game, GameMove& _player);

    void setType(int _type);

private:
    Game game;
    GameMove player;
    int type;

    // Fonts

    sf::Font font1;
    sf::Font font2;

    // Cards

    sf::Texture taxCardTexture;
    sf::Sprite taxCardSprite;


    sf::Texture payToPlayerCardTexture;
    sf::Sprite payToPlayerCardSprite;

    // Buttons

    sf::Texture payButtonTexture;
    sf::Sprite payButtonSprite;

};

