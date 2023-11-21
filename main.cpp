#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "sources/player.h"
#include "sources/game.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({1024, 1024}), "Monopoly", sf::Style::Fullscreen);

    sf::Font font;
    if (!font.loadFromFile("assets/fonts/Minecraft.otf")) {
        return EXIT_FAILURE;
    }

    //Main Screen

    int currentFrame = 0;
    sf::Texture mainScreenTexture;
    if (!mainScreenTexture.loadFromFile("assets/sprite/Main.png")) {
        return EXIT_FAILURE;
    }

    sf::Sprite mainScreenSprite(mainScreenTexture);

    sf::Texture buttonStartGameTexture;
    if (!buttonStartGameTexture.loadFromFile("assets/sprite/buttonStartGame.png")) {
        return EXIT_FAILURE;
    }

    sf::Sprite buttonStartGameSprite(buttonStartGameTexture);
    buttonStartGameSprite.setTextureRect(sf::IntRect(0, 0, 400, 175));
    buttonStartGameSprite.setPosition((window.getSize().x / 2.f) - 200, (window.getSize().y / 2.f) - 82.5);

    bool isActiveMainScreen = true;
    bool isActiveSettings = false;

    // Settings

    sf::Texture settingsTexture;
    if (!settingsTexture.loadFromFile("assets/sprite/Settings.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite settingsSprite(settingsTexture);


    // Players

    std::vector<sf::Texture> playersTexture(3);
    std::vector<sf::Sprite> playersSprite;
    std::vector<Player> players;

    for (int i = 0; i < playersTexture.size(); i++) {
        if (!playersTexture[i].loadFromFile("assets/sprite/Player" + std::to_string(i + 1) + ".png")) {
            return EXIT_FAILURE;
        }
        sf::Sprite sprite1(playersTexture[i]);
        if (i == 2) {
            Player player(sprite1, "Alyona", 1500, 11, 0);
            players.push_back(player);
            playersSprite.push_back(sprite1);
            continue;
        }
        Player player(sprite1, "Alyona", 1500, 1, 0);
        players.push_back(player);
        playersSprite.push_back(sprite1);

    }

//    Player player1(file_path1, "Alyona", 1500, 1, 0);
//    Player player2(file_path2, "Max", 1500, 1, 0);
//    Player player3(file_path3, "Evgeny", 1500, 1, 0);

//    Game game(1500, -1, 200, 0, true, 50, 0, players);

    sf::View view1;
    view1.reset(sf::FloatRect(724.f, 724.f, 300.f, 300.f));


    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            switch (event.type) {
                case (sf::Event::Closed):
                    window.close();
                case (sf::Event::KeyPressed):
                    if (event.key.code == sf::Keyboard::Escape) window.close();
                default:
                    break;
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (buttonStartGameSprite.getGlobalBounds().contains(
                            window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                        buttonStartGameSprite.setTextureRect(sf::IntRect(400 * 1, 0, 400, 175));
                        isActiveMainScreen = false;
                        isActiveSettings = true;
                    }
                }
            } else if (event.type == sf::Event::MouseMoved) {
                if (buttonStartGameSprite.getGlobalBounds().contains(
                        window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    buttonStartGameSprite.setTextureRect(sf::IntRect(400 * 2, 0, 400, 175));
                } else {
                    buttonStartGameSprite.setTextureRect(sf::IntRect(0, 0, 400, 175));
                }
            } else {
                buttonStartGameSprite.setTextureRect(sf::IntRect(0, 0, 400, 175));

            }
        }

        window.clear();
        if (isActiveMainScreen) {
            window.draw(mainScreenSprite);
            window.draw(buttonStartGameSprite);
        } else if (isActiveSettings) {
            window.clear();
            window.draw(settingsSprite);
        }
        window.display();
    }

    return 0;
}
