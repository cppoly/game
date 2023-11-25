#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "../../../sources/game.h"
#include <vector>
#include "../../text/text.h"

class GameWindow {
public:
    GameWindow(sf::RenderWindow &window);

    void draw(sf::RenderWindow &window);

    bool handleEvent(sf::Event &event, sf::RenderWindow &window);

    void onStartGame(sf::RenderWindow& window);

    void onRollDice(sf::RenderWindow& window);

    void onCompleteTurn(sf::RenderWindow& window);

    void onBuyClick(sf::RenderWindow& window);

    void onOkClick(sf::RenderWindow&window);

    void setGame(Game& game1);

    void drawPlayers(sf::RenderWindow& window);

    void drawPlayer(sf::RenderWindow& window, int currPosition, int numberPlayer);

private:
    bool isGameStarted = false;
    bool isRollDice = false;

    bool isActiveDoNothing = false;
    bool isActiveBuyMode = false;
    bool isActiveDrawCardMode = false;
    bool isActivePayPlayerMode = false;
    bool isActivePayBankMode = false;
    bool isActiveGoToJail = false;

    Card card;

    GameMove player;
//    sf::Sprite currPlayerSprite;
    sf::Text currPlayerName;
    sf::Text currPlayerCapacity;
    sf::Text currAmountJailCards;


    sf::Texture backgroundImageTexture;
    sf::Sprite backgroundImageSprite;

    // Buttons

    sf::Texture startGameButtonTexture;
    sf::Sprite startGameButtonSprite;

    sf::Texture completeTurnTexture;
    sf::Sprite completeTurnSprite;

    sf::Texture rollDiceButtonTexture;
    sf::Sprite rollDiceButtonSprite;

    sf::Texture buyButtonTexture;
    sf::Sprite buyButtonSprite;

    sf::Texture auctionButtonTexture;
    sf::Sprite auctionButtonSprite;

    sf::Texture payButtonTexture;
    sf::Sprite payButtonSprite;

    sf::Texture okButtonTexture;
    sf::Sprite okButtonSprite;

    // Dices

    sf::Texture dice1Texture;
    sf::Texture dice2Texture;

    sf::Sprite dice1Sprite;
    sf::Sprite dice2Sprite;

    // Cards

    sf::Texture fieldCardTexture;
    sf::Sprite fieldCardSprite;

    sf::Texture playerInformationCardTexture;
    sf::Sprite playerInformationCardSprite;

    sf::Texture chanceCardTexture;
    sf::Sprite chanceCardSprite;

    sf::Texture communityChestCardTexture;
    sf::Sprite communityChestCardSprite;


    // Fonts

    sf::Font font1;
    sf::Font font2;

    Game game;
};

