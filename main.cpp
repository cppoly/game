#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "sources/player.h"
#include "sources/game.h"
#include "interface/input/input.hpp"
#include "interface/windows/SettingsWindow/settings_window.h"
#include "interface/windows/MainWindow/main_window.h"
#include "interface/windows/CharactersWindow/character_window.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({1024, 1024}), "Monopoly", sf::Style::Fullscreen);


    bool isActiveMainScreen = true;
    bool isActiveSettings = false;
    bool isActiveCharacter = false;

    //Main Screen
    auto mainWindow = MainWindow(window);

    // Settings

    auto settingsWindow = SettingsWindow(window);

    // Character

    auto characterWindow = CharacterWindow(window);

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

//    sf::View view1;
//    view1.reset(sf::FloatRect(724.f, 724.f, 300.f, 300.f));

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

            if (mainWindow.handleEvent(event, window)) {
                isActiveMainScreen = false;
                isActiveSettings = true;
            } else if (settingsWindow.handleEvent(event, window)) {
                isActiveSettings = false;
                isActiveCharacter = true;
            } else if (characterWindow.handleEvent(event, window)) {
                isActiveSettings = false;
            }
        }

        if (isActiveMainScreen) {
            mainWindow.draw(window);
        } else if (isActiveSettings) {
            settingsWindow.draw(window);
        } else if (isActiveCharacter) {
            characterWindow.draw(window);
        }
        window.display();
    }

    return 0;
}
