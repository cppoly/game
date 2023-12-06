#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../../../sources/game.h"
#include "../../../sources/player.h"
#include "../../text/text.h"
#include "../MyFieldsWindow/MyFieldsWindow.h"
#include "../../input/input.h"

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
    MyFieldsWindow fieldsCurrPage;
    MyFieldsWindow fieldsPlayer2Page;

    bool isActiveLargeMode = false;
    bool isActiveTradeMode = false;
    bool isActiveFields1Mode = false;
    bool isActiveFields2Mode = false;

    Player* currPlayer;
    Player* player2;

    // Input

    sdx::TextBox::Text fieldNumber1 = sdx::TextBox::Text("", 100, 100);
    sdx::TextBox::Text fieldNumber2 = sdx::TextBox::Text("", 100, 100);
    sdx::TextBox input1;
    sdx::TextBox input2;

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

    sf::Texture fieldsTexture;
    sf::Sprite fields1Sprite;
    sf::Sprite fields2Sprite;

    sf::Sprite playersLargeSprite;
    sf::Sprite activePlayerSprite;

    std::vector<sf::Sprite> playersSprite;

};
