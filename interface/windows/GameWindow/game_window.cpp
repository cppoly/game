#include "game_window.h"

GameWindow::GameWindow(sf::RenderWindow &window) {
    if (!backgroundImageTexture.loadFromFile("assets/sprite/BackgroundImage/playing_field.png")) {
        throw "Can't load background image for GameWindow";
    }

    backgroundImageSprite = sf::Sprite(backgroundImageTexture);
    backgroundImageSprite.setScale(window.getSize().x / backgroundImageSprite.getLocalBounds().getSize().x,
                                   window.getSize().y / backgroundImageSprite.getLocalBounds().getSize().y);


}

bool GameWindow::handleEvent(sf::Event &event, sf::RenderWindow &window) {
//    for (int i = 0; i < game.get_players().size(); i++) {
//        game.get_players()[i].get_sprite().setPosition(100, i * 100);
//    }
    return false;
}

void GameWindow::draw(sf::RenderWindow &window) {
    window.clear();
    window.draw(backgroundImageSprite);
    game.start_game();

    GameMove player = game.player_move();

    for (int i = 0; i < game.get_players().size(); i++) {

        if (i != game.get_cur_player_id()) {
            sf::Sprite sprite = game.get_players()[i].get_sprite();
            sprite.setPosition(1350 + i * 30 - game.get_players()[i].get_position() * 50, 870);
            window.draw(sprite);
        } else {
            sf::Sprite sprite = game.get_players()[i].get_sprite();

            sprite.setPosition(1350 + i * 30 - player.new_position * 50, 870);

            window.draw(sprite);
        }
//        window.draw(sprite);
    }
}


void GameWindow::setGame(Game &game1) {
    game = game1;
}