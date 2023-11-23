#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../../../sources/game.h"
#include <vector>

#define MAX_PLAYERS_COUNT 6

class CharacterWindow {
public:
    CharacterWindow(sf::RenderWindow &window);

    void draw(sf::RenderWindow &window);

    bool handleEvent(sf::Event &event, sf::RenderWindow &window);

private:
    int playersCount = 0;
    bool isActiveSelectCharacterMode = true;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    std::string title = "Choose players";

    sf::Text titleChoseCharacterPage;
    sf::Font font1;

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

    sf::Texture player1LargeTexture;

    sf::Sprite player1Sprite;
    sf::Sprite player2Sprite;
    sf::Sprite player3Sprite;
    sf::Sprite player4Sprite;
    sf::Sprite player5Sprite;
    sf::Sprite player6Sprite;

    sf::Sprite player1LargeSprite;
//    sf::Texture activePlayerTexture;
    sf::Sprite activePlayerSprite;


    std::vector<sf::Texture> playersTexture;
    std::vector<sf::Sprite> playersSprite;
};

