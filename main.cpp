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
