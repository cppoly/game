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

    void setGame(Game& game1);


private:
    bool isGameStarted = false;
    bool isRollDice = false;
    bool isActiveBuyMode = false;

    GameMove player;
    sf::Sprite currPlayerSprite;
    sf::Text currPlayerName;
    sf::Text currPlayerCapacity;


    sf::Texture backgroundImageTexture;
    sf::Sprite backgroundImageSprite;

    sf::Texture startGameButtonTexture;
    sf::Sprite startGameButtonSprite;

    sf::Texture completeTurnTexture;
    sf::Sprite completeTurnSprite;

    sf::Texture rollDiceButtonTexture;
    sf::Sprite rollDiceButtonSprite;

    sf::Texture playerInformationCardTexture;
    sf::Sprite playerInformationCardSprite;

    // Dices
    sf::Texture dice1Texture;
    sf::Texture dice2Texture;

    sf::Sprite dice1Sprite;
    sf::Sprite dice2Sprite;

    // Cards

    sf::Texture fieldCardTexture;
    sf::Sprite fieldCardSprite;

    // Fonts

    sf::Font font1;
    sf::Font font2;

    Game game;
};

