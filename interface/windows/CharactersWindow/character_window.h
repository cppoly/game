#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../../../sources/game.h"
#include <vector>
#include "../../input/input.hpp"

#define MAX_PLAYERS_COUNT 6

class CharacterWindow {
public:
    CharacterWindow(sf::RenderWindow &window);

    void draw(sf::RenderWindow &window);

    bool handleEvent(sf::Event &event, sf::RenderWindow &window);

private:
    int playersCount = 0;
    bool isActiveSelectCharacterMode = false;
    bool isAddedPlayer = false;
    int indexActivePlayer = 0;
    std::vector<int> disabledPlayersIndex;
    std::vector<sf::Text> addedPlayerNameText;


    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    std::string title = "Choose players";

    sf::Text titleChoseCharacterPage;
    sf::Font font1;
    sf::Font font2;

    sf::Texture buttonAddPlayerTexture;
    sf::Sprite buttonAddPlayerSprite;

    sf::Texture buttonStartGameTexture;
    sf::Sprite buttonStartGameSprite;

    sf::Texture chosePlayerTexture;
    sf::Sprite chosePlayerSprite;

    sf::Texture player1Texture;
    sf::Texture player2Texture;
    sf::Texture player3Texture;
    sf::Texture player4Texture;
    sf::Texture player5Texture;
    sf::Texture player6Texture;

    sf::Texture playersLargeTexture;

    sf::Sprite player1Sprite;
    sf::Sprite player2Sprite;
    sf::Sprite player3Sprite;
    sf::Sprite player4Sprite;
    sf::Sprite player5Sprite;
    sf::Sprite player6Sprite;

    sf::Texture player1DisableTexture;
    sf::Texture player2DisableTexture;
    sf::Texture player3DisableTexture;
    sf::Texture player4DisableTexture;
    sf::Texture player5DisableTexture;
    sf::Texture player6DisableTexture;

    sf::Texture player1MediumTexture;
    sf::Texture player2MediumTexture;
    sf::Texture player3MediumTexture;
    sf::Texture player4MediumTexture;
    sf::Texture player5MediumTexture;
    sf::Texture player6MediumTexture;

    sf::Sprite player1MediumSprite;
    sf::Sprite player2MediumSprite;
    sf::Sprite player3MediumSprite;
    sf::Sprite player4MediumSprite;
    sf::Sprite player5MediumSprite;
    sf::Sprite player6MediumSprite;


    sf::Sprite playersLargeSprite;
    sf::Sprite activePlayerSprite;


    std::vector<sf::Texture> playersTexture;
    std::vector<sf::Sprite> playersSprite;

    std::vector<sf::Texture> playersMediumTexture;
    std::vector<sf::Sprite> playersMediumSprite;

    std::vector<sf::Texture> playersDisableTexture;

    std::vector<sf::Sprite> addedPlayersSprite;

    // Input

    sdx::TextBox::Text name = sdx::TextBox::Text("", 100, 100);
    sdx::TextBox input;

};

