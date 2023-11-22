#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "interface/windows/SettingsWindow/settings_window.h"
#include "interface/windows/MainWindow/main_window.h"
#include "interface/windows/CharactersWindow/character_window.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({1024, 1024}), "Monopoly", sf::Style::Default);


    bool isActiveMainScreen = true;
    bool isActiveSettings = false;
    bool isActiveCharacter = false;

    // Main Screen

    auto mainWindow = MainWindow(window);

    // Settings

    auto settingsWindow = SettingsWindow(window);

    // Character

    auto characterWindow = CharacterWindow(window);

    while (window.isOpen()) {
        sf::Event event{};

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed or sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))  {
                window.close();
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
