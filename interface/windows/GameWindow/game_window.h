#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "../../../sources/game.h"
#include <vector>
#include "../../text/text.h"
#include <algorithm>
#include "../../rent_card/RentCards.h"
#include "../BuyModeWindow/buy_mode_window.h"
#include "../MyFieldsWindow/MyFieldsWindow.h"
#include "../PayWindow/PayWindow.h"
#include "../DrawCardWindow/DrawCardWindow.h"
#include "../SwapWindow/SwapWindow.h"

class GameWindow {
public:
    explicit GameWindow(sf::RenderWindow &window);

    void draw(sf::RenderWindow &window, sf::Event& event);

    bool handleEvent(sf::Event &event, sf::RenderWindow &window);

    void onStartGame();

    void onRollDice();

    void onCompleteTurn();

    void onZoomButtonClick();

    void setGame(Game& game1);

    void zoomCurrPlayer(sf::RenderWindow& window);

    void drawPlayers(sf::RenderWindow& window);

    void drawPlayer(sf::RenderWindow& window, int currPosition, int numberPlayer);

    void drawDice(sf::RenderWindow& window);

    void drawPlayerInformation(sf::RenderWindow& window);

private:
    BuyModeWindow buyPage;
    MyFieldsWindow myFieldsPage;
    PayWindow payPage;
    DrawCardWindow drawCardPage;
    SwapWindow swapPage;

    bool isGameStarted = false;
    bool isRollDice = false;
    bool isActiveMyFieldsMode = false;
    bool isActiveZoomMode = false;
    bool isActiveSwapMode = false;

    bool isActiveBuyMode = false;
    bool isActiveDrawCardMode = false;
    bool isActivePayPlayerMode = false;
    bool isActivePayBankMode = false;
    bool isActiveGoToJail = false;

    Card card;

    GameMove player;
    sf::Text currPlayerName;
    sf::Text currPlayerCapacity;
    sf::Text currAmountJailCards;

    sf::Texture backgroundImageTexture;
    sf::Sprite backgroundImageSprite;

    sf::Texture playingFieldTexture;
    sf::Sprite playingFieldSprite;

    // Buttons

    sf::Texture startGameButtonTexture;
    sf::Sprite startGameButtonSprite;

    sf::Texture completeTurnTexture;
    sf::Sprite completeTurnSprite;

    sf::Texture rollDiceButtonTexture;
    sf::Sprite rollDiceButtonSprite;

    sf::Texture myFieldsButtonTexture;
    sf::Sprite myFieldsButtonSprite;

    sf::Texture loupeButtonTexture;
    sf::Sprite loupeButtonSprite;

    sf::Texture swapButtonTexture;
    sf::Sprite swapButtonSprite;

    // Dices

    sf::Texture dice1Texture;
    sf::Texture dice2Texture;

    sf::Sprite dice1Sprite;
    sf::Sprite dice2Sprite;

    // Cards

    sf::Texture playerInformationCardTexture;
    sf::Sprite playerInformationCardSprite;

    // Fonts

    sf::Font font1;
    sf::Font font2;

    Game game;
};

