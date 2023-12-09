#pragma once

#include <iostream>
#include<SFML/Graphics.hpp>
#include "../../../sources/game.h"
#include "../../text/text.h"
#include "../../rent_card/RentCards.h"

class BuyModeWindow {
public:
    BuyModeWindow() = default;

    void loadBuyModeWindow(sf::RenderWindow& window);

    void draw(sf::RenderWindow &window, sf::Event& event);

    int handleEvent(sf::Event &event, sf::RenderWindow &window);

    void setGame(Game& _game);

private:
    Game game;

    // Fonts

    sf::Font font1;
    sf::Font font2;

    // Field Card

    sf::Texture fieldCardTexture;
    sf::Sprite fieldCardSprite;

    // Rent Cards

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

    // Buttons

    sf::Texture buyButtonTexture;
    sf::Sprite buyButtonSprite;

    sf::Texture auctionButtonTexture;
    sf::Sprite auctionButtonSprite;

};

