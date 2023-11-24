#include "game_window.h"

GameWindow::GameWindow(sf::RenderWindow &window) {
    if (!backgroundImageTexture.loadFromFile("assets/sprite/BackgroundImage/playing_field.png") ||
        !startGameButtonTexture.loadFromFile("assets/sprite/Buttons/buttonStartGame.png") ||
        !completeTurnTexture.loadFromFile("assets/sprite/Buttons/buttonCompleteTurn.png") ||
        !rollDiceButtonTexture.loadFromFile("assets/sprite/Buttons/buttonRollDice.png") ||
        !font1.loadFromFile("assets/fonts/Bionicle.ttf")) {
        throw std::runtime_error("Can't load texture for GameWindow");
    }



    // Background
    backgroundImageSprite = sf::Sprite(backgroundImageTexture);
    backgroundImageSprite.setScale(window.getSize().x / backgroundImageSprite.getLocalBounds().getSize().x,
                                   window.getSize().y / backgroundImageSprite.getLocalBounds().getSize().y);

    // Buttons
    startGameButtonSprite = sf::Sprite(startGameButtonTexture);
    startGameButtonSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    startGameButtonSprite.setPosition((window.getSize().x / 2.f) - 360 / 2,
                                      (window.getSize().y / 2.f) - 109 / 2);

    completeTurnSprite = sf::Sprite(completeTurnTexture);
    completeTurnSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    completeTurnSprite.setPosition(1400, 100);

    rollDiceButtonSprite = sf::Sprite(rollDiceButtonTexture);
    rollDiceButtonSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    rollDiceButtonSprite.setPosition(200, 100);
}

bool GameWindow::handleEvent(sf::Event &event, sf::RenderWindow &window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (startGameButtonSprite.getGlobalBounds().contains(
                    window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                startGameButtonSprite.setTextureRect(sf::IntRect(360, 0, 360, 109));
                isGameStarted = true;

                game.start_game();
//                player = game.player_move();

            } else if (completeTurnSprite.getGlobalBounds().contains(
                    window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                completeTurnSprite.setTextureRect(sf::IntRect(360, 0, 360, 109));
                int id = game.next_turn();
//                std::cout << id << game.get_cur_player_id();
//                if (id != game.get_cur_player_id()) {
//                    player = std::fintgame.get_players();
//                }
                    isRollDice = false;

            } else if (rollDiceButtonSprite.getGlobalBounds().contains(
                    window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                rollDiceButtonSprite.setTextureRect(sf::IntRect(360, 0, 360, 109));

                player = game.player_move();
                isRollDice = true;
            }

        }
    } else if (event.type == sf::Event::MouseMoved) {
        if (startGameButtonSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            startGameButtonSprite.setTextureRect(sf::IntRect(360 * 2, 0, 360, 109));
        } else if (completeTurnSprite.getGlobalBounds().contains(
                window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            completeTurnSprite.setTextureRect(sf::IntRect(360 * 2, 0, 360, 109));
        } else if (rollDiceButtonSprite.getGlobalBounds().contains(
                window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            rollDiceButtonSprite.setTextureRect(sf::IntRect(360 * 2, 0, 360, 109));
        } else {
            completeTurnSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
            rollDiceButtonSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
        }
    }
    return false;
}

void GameWindow::draw(sf::RenderWindow &window) {
    window.clear();
    window.draw(backgroundImageSprite);
    if (!isGameStarted) {
        backgroundImageSprite.setColor(sf::Color(255, 255, 255, 60));
        window.draw(startGameButtonSprite);
    } else {
        backgroundImageSprite.setColor(sf::Color(255, 255, 255, 255));
        window.draw(completeTurnSprite);
        window.draw(rollDiceButtonSprite);

        if (isRollDice) {
            for (int i = 0; i < game.get_players().size(); i++) {
                if (i != game.get_cur_player_id()) {
                    sf::Sprite sprite = game.get_players()[i].get_sprite();
                    sprite.setPosition(1350 + i * 30 - game.get_players()[i].get_position() * 50, 870);
                    window.draw(sprite);
                } else {

                    sf::Sprite sprite = game.get_players()[i].get_sprite();
                    std::string s = game.get_players()[i].get_name();
                    set_text(currPlayerName, font1, s, 100, sf::Color::Black, sf::Text::Style::Bold, 1000, 100);
                    sprite.setPosition(1350 + i * 30 - player.new_position * 50, 870);

                    window.draw(currPlayerName);
                    window.draw(sprite);
                }
            }
        } else {
            for (int i = 0; i < game.get_players().size(); i++) {
                if (i != game.get_cur_player_id()) {
                    sf::Sprite sprite = game.get_players()[i].get_sprite();
                    sprite.setPosition(1350 + i * 30 - game.get_players()[i].get_position() * 50, 870);
                    window.draw(sprite);
                } else {
                    sf::Sprite sprite = game.get_players()[i].get_sprite();
                    std::string s = game.get_players()[i].get_name();
                    set_text(currPlayerName, font1, s, 100, sf::Color::Black, sf::Text::Style::Bold, 1000, 100);
                    sprite.setPosition(1350 + i * 30 - game.get_players()[i].get_position() * 50, 870);

                    window.draw(currPlayerName);
                    window.draw(sprite);

                }
            }
        }
    }
}


void GameWindow::setGame(Game &game1) {
    game = game1;
}