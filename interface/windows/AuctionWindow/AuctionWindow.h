#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../../../sources/game.h"
#include "../../input/input.h"
#include "../../text/text.h"

class AuctionWindow {
public:
    AuctionWindow() = default;

    void loadBuyModeWindow(sf::RenderWindow& window);

    void draw(sf::RenderWindow &window, sf::Event& event);

    bool handleEvent(sf::Event &event, sf::RenderWindow &window);

    void setGame(Game& _game);
private:
    Game game;

    // Fonts

    sf::Font font1;
    sf::Font font2;

    sf::Texture auctionCardTexture;
    sf::Sprite auctionCardSprite;

    sf::Texture okButtonTexture;
    sf::Sprite okButtonSprite;

    sdx::TextBox::Text price1 = sdx::TextBox::Text("", 100, 100);
    sdx::TextBox::Text price2 = sdx::TextBox::Text("", 100, 100);
    sdx::TextBox::Text price3 = sdx::TextBox::Text("", 100, 100);
    sdx::TextBox::Text price4 = sdx::TextBox::Text("", 100, 100);
    sdx::TextBox::Text price5 = sdx::TextBox::Text("", 100, 100);
    sdx::TextBox::Text price6 = sdx::TextBox::Text("", 100, 100);

    sdx::TextBox input1;
    sdx::TextBox input2;
    sdx::TextBox input3;
    sdx::TextBox input4;
    sdx::TextBox input5;
    sdx::TextBox input6;

    std::vector<sdx::TextBox::Text> prices = {price1, price2, price3, price4, price5, price6};
    std::vector<sdx::TextBox> inputs = {input1, input2, input3, input4, input5, input6};
};

