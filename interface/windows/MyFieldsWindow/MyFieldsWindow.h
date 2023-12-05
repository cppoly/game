#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../../../sources/game.h"
#include "../../rent_card/RentCards.h"

class MyFieldsWindow {
public:
    MyFieldsWindow() = default;

    void loadBuyModeWindow(sf::RenderWindow& window);

    void draw(sf::RenderWindow &window, sf::Event& event);

    bool handleEvent(sf::Event &event, sf::RenderWindow &window);

    void setGame(Game& _game);

private:
    Game game;

    // Fonts

    sf::Font font1;
    sf::Font font2;

    sf::Texture myFieldsCardTexture;
    sf::Sprite myFieldsCardSprite;

    sf::Texture okButtonTexture;
    sf::Sprite okButtonSprite;

    // Rent Card

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

};

