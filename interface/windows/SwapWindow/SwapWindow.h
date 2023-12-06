#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../../../sources/game.h"
#include "../../../sources/player.h"
#include "../../text/text.h"

class SwapWindow {
public:
    SwapWindow() = default;

    void loadBuyModeWindow(sf::RenderWindow& window);

    void draw(sf::RenderWindow &window, sf::Event& event);

    bool handleEvent(sf::Event &event, sf::RenderWindow &window);

    void setGame(Game& _game);

private:
    Game game;
    int indexPlayer;
    bool isActiveLargeMode = false;
    bool isActiveTradeMode = false;
    Player* currPlayer;
    Player* player2;
    // Fonts

    sf::Font font1;
    sf::Font font2;

    sf::Texture choosePlayerCardTexture;
    sf::Sprite choosePlayerCardSprite;

    sf::Texture swapCardTexture;
    sf::Sprite swapCardSprite;

    sf::Texture buttonChoosePlayerTexture;
    sf::Sprite buttonChoosePlayerSprite;

    sf::Texture buttonCancelTexture;
    sf::Sprite buttonCancelSprite;

    sf::Texture buttonSwapTexture;
    sf::Sprite buttonSwapSprite;

    sf::Sprite playersLargeSprite;
    sf::Sprite activePlayerSprite;

    std::vector<sf::Sprite> playersSprite;

};
