#include "game_window.h"
GameWindow::GameWindow(sf::RenderWindow &window ) {
    if (!backgroundImageTexture.loadFromFile("assets/sprite/BackgroundImage/playing_field.png")) {
        throw "Can't load background image for GameWindow";
    }

    backgroundImageSprite = sf::Sprite(backgroundImageTexture);
    backgroundImageSprite.setScale(window.getSize().x / backgroundImageSprite.getLocalBounds().getSize().x, window.getSize().y / backgroundImageSprite.getLocalBounds().getSize().y);



    for (int i = 0; i < game.get_players().size(); i++) {
        sf::Sprite p = game.get_players().se
        game.get_players()[i].get_sprite().setPosition(0, 0);
    }
}

bool GameWindow::handleEvent(sf::Event &event, sf::RenderWindow &window) {
    game.start_game();

    return false;
}

void GameWindow::draw(sf::RenderWindow &window) {
    window.clear();
    window.draw(backgroundImageSprite);
    for (int i = 0; i < game.get_players().size(); i++) {
        game.get_players()[i].get_sprite().setPosition(10, 10);
        window.draw(game.get_players()[i].get_sprite());
    }
}

void GameWindow::setGame(Game &game1) {
    game = game1;
}