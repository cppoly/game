#include "game_window.h"
GameWindow::GameWindow(sf::RenderWindow &window) {
    if (!backgroundImageTexture.loadFromFile("assets/sprite/BackgroundImage/playing_field.png")) {
        throw "Can't load background image for GameWindow";
    }

    backgroundImageSprite = sf::Sprite(backgroundImageTexture);
}

void GameWindow::draw(sf::RenderWindow &window) {
    window.clear();
    window.draw(backgroundImageSprite);
}