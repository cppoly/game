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

    void draw(sf::RenderWindow &window, sf::Event& event);

    bool handleEvent(sf::Event &event, sf::RenderWindow &window);

    void onStartGame(sf::RenderWindow& window);

    void onRollDice(sf::RenderWindow& window);

    void onCompleteTurn(sf::RenderWindow& window);

    void onBuyClick(sf::RenderWindow& window);

    void onOkClick(sf::RenderWindow&window);

    void onPayButtonClick(sf::RenderWindow& window);

    void setGame(Game& game1);

    void drawPlayers(sf::RenderWindow& window);

    void drawPlayer(sf::RenderWindow& window, int currPosition, int numberPlayer);

    void drawDice(sf::RenderWindow& window);

    void drawPlayerInformation(sf::RenderWindow& window);

    void drawBuyCard(sf::RenderWindow& window);

    void drawDrawCard(sf::RenderWindow& window);

    void drawPayBankCard(sf::RenderWindow& window);

    void drawMyFields(sf::RenderWindow& window, sf::Event& event, std::vector<ProfitableField*>& field);

    void drawRentStreetCard(sf::RenderWindow& window, ProfitableField * field, sf::Sprite& rentCardSprite, float x, float y, float scaleX, float ScaleY);

    void drawRentStationCard(sf::RenderWindow& window, ProfitableField* field, float x, float y, float scaleX, float ScaleY);

    void drawRentUtilityCard(sf::RenderWindow& window, ProfitableField* field, float x, float y, float scaleX, float ScaleY);

private:
    bool isGameStarted = false;
    bool isRollDice = false;
    bool isActiveMyFieldsMode = false;
    bool isActiveZoomMode = false;

    bool isActiveDoNothing = false;
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

    sf::Texture myFieldsButtonTexture;
    sf::Sprite myFieldsButtonSprite;

    sf::Texture payToPlayerCardTexture;
    sf::Sprite payToPlayerCardSprite;

    sf::Texture loupeButtonTexture;
    sf::Sprite loupeButtonSprite;

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

    sf::Texture myFieldsCardTexture;
    sf::Sprite myFieldsCardSprite;
    // Card Rent

    sf::Texture cardRent1Texture;
    sf::Texture cardRent2Texture;
    sf::Texture cardRent3Texture;
    sf::Texture cardRent4Texture;
    sf::Texture cardRent5Texture;
    sf::Texture cardRent6Texture;
    sf::Texture cardRent7Texture;
    sf::Texture cardRent8Texture;

    sf::Sprite cardRent1Sprite;
    sf::Sprite cardRent2Sprite;
    sf::Sprite cardRent3Sprite;
    sf::Sprite cardRent4Sprite;
    sf::Sprite cardRent5Sprite;
    sf::Sprite cardRent6Sprite;
    sf::Sprite cardRent7Sprite;
    sf::Sprite cardRent8Sprite;

    std::vector<sf::Texture> cardsRentTexture = {cardRent1Texture, cardRent2Texture, cardRent3Texture,
                                                 cardRent4Texture, cardRent5Texture, cardRent6Texture,
                                                 cardRent7Texture, cardRent8Texture, };
    std::vector<sf::Sprite> cardsRentSprite = {cardRent1Sprite, cardRent2Sprite, cardRent3Sprite,
                                               cardRent4Sprite, cardRent5Sprite, cardRent6Sprite,
                                               cardRent7Sprite, cardRent8Sprite, };

    // Card Utility

    sf::Texture laundryCardTexture;
    sf::Sprite laundryCardSprite;

    sf::Texture vanCardTexture;
    sf::Sprite vanCardSprite;

    // Card Station

    sf::Texture porsheCardTexture;
    sf::Sprite porsheCardSprite;

    sf::Texture bmwCardTexture;
    sf::Sprite bmwCardSprite;

    sf::Texture teslaCardTexture;
    sf::Sprite teslaCardSprite;

    sf::Texture audiCardTexture;
    sf::Sprite audiCardSprite;

    sf::Texture taxCardTexture;
    sf::Sprite taxCardSprite;

    // Fonts

    sf::Font font1;
    sf::Font font2;

    Game game;
};

