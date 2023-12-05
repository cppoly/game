#pragma once

#include <iostream>
#include "../../../sources/game.h"
#include "SFML/Graphics.hpp"
#include "../../text/text.h"
#include "../../../sources/cards.h"

class DrawCardWindow {
public:
    DrawCardWindow() = default;

    void loadBuyModeWindow(sf::RenderWindow& window);

    void draw(sf::RenderWindow &window, sf::Event& event);

    bool handleEvent(sf::Event &event, sf::RenderWindow &window);

    void setGame(Game& _game, Card& _card);

private:
    Game game;
    Card card;

    // Fonts

    sf::Font font1;
    sf::Font font2;

    // Sprites

    sf::Texture okButtonTexture;
    sf::Sprite okButtonSprite;

    sf::Texture communityChestCardTexture;
    sf::Sprite communityChestCardSprite;

    sf::Texture chanceCardTexture;
    sf::Sprite chanceCardSprite;
};
