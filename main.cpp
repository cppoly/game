#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "interface/windows/SettingsWindow/settings_window.h"
#include "interface/windows/MainWindow/main_window.h"
#include "interface/windows/CharactersWindow/character_window.h"
#include "interface/windows/GameWindow/game_window.h"
#include "sources/game.h"

int main() {
    sf::RenderWindow window(
            sf::VideoMode(
                    sf::VideoMode::getDesktopMode().width,
                    sf::VideoMode::getDesktopMode().height),
            "Monopoly"
            );


    bool isActiveMainScreen = true;
    bool isActiveSettings = false;
    bool isActiveCharacter = false;
    bool isActiveGame = false;

    // Main Screen

    MainWindow mainWindow;
    mainWindow.loadMainWindow(window);

    // Settings

    SettingsWindow settingsWindow;
    settingsWindow.loadSettingsWindow(window);

    // Character

    CharacterWindow characterWindow;
    characterWindow.loadCharacterWindow(window);

    // Game

    GameWindow gameWindow;
    gameWindow.loadGameWindow(window);

    while (window.isOpen()) {
        sf::Event event{};

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed or sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))  {
                window.close();
                break;
            }

            if (isActiveMainScreen) {
                if (mainWindow.handleEvent(event, window)) {
                    isActiveMainScreen = false;
                    isActiveSettings = true;
                }
            } else if (isActiveSettings) {
                if (settingsWindow.handleEvent(event, window)) {
                    isActiveSettings = false;
                    isActiveCharacter = true;
                    Game game = settingsWindow.getGame();
                    characterWindow.setGame(game);
                }
            } else if (isActiveCharacter) {
                if (characterWindow.handleEvent(event, window)) {
                    isActiveCharacter = false;
                    isActiveGame = true;
                    Game game = characterWindow.getGame();
                    gameWindow.setGame(game);
                }
            } else if (isActiveGame) {
                if (gameWindow.handleEvent(event, window)) {
                    isActiveGame = false;
                    isActiveMainScreen = true;
                    mainWindow.loadMainWindow(window);
                    settingsWindow.loadSettingsWindow(window);
                    characterWindow.loadCharacterWindow(window);
                    gameWindow.loadGameWindow(window);
                }
            }
        }

        window.clear();
        if (isActiveMainScreen) {
            mainWindow.draw(window);
        } else if (isActiveSettings) {
            settingsWindow.draw(window);
        } else if (isActiveCharacter) {
            characterWindow.draw(window);
        } else if (isActiveGame) {
            gameWindow.draw(window, event);
        }
        window.display();
    }

    return 0;
}
