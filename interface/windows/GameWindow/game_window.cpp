#include "game_window.h"

GameWindow::GameWindow(sf::RenderWindow &window) {
    if (!backgroundImageTexture.loadFromFile("assets/sprite/BackgroundImage/playing_field.png") ||
        !startGameButtonTexture.loadFromFile("assets/sprite/Buttons/buttonStartGame.png") ||
        !completeTurnTexture.loadFromFile("assets/sprite/Buttons/buttonCompleteTurn.png") ||
        !rollDiceButtonTexture.loadFromFile("assets/sprite/Buttons/buttonRollDice.png") ||
        !playerInformationCardTexture.loadFromFile("assets/sprite/playerInformationCard.png") ||
        !dice1Texture.loadFromFile("assets/sprite/DicePack/DiceSprSheetX96.png") ||
        !dice2Texture.loadFromFile("assets/sprite/DicePack/DiceSprSheetX96.png") ||
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
    completeTurnSprite.setPosition(window.getSize().x - 50 - 360, 100);
    completeTurnSprite.setScale(0.8f, 0.8f);


    rollDiceButtonSprite = sf::Sprite(rollDiceButtonTexture);
    rollDiceButtonSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    rollDiceButtonSprite.setPosition(50, 100);
    rollDiceButtonSprite.setScale(0.8f, 0.8f);

    // Cards

    playerInformationCardSprite = sf::Sprite(playerInformationCardTexture);
    playerInformationCardSprite.setPosition(50, 300);

    dice1Sprite = sf::Sprite(dice1Texture);
    dice1Sprite.setPosition(100, 600);

    dice2Sprite = sf::Sprite(dice2Texture);
    dice2Sprite.setPosition(200, 600);

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
        window.draw(playerInformationCardSprite);
        window.draw(currPlayerSprite);


        std::string s = game.get_players()[game.get_cur_player_id()].get_name();
        set_text(currPlayerName, font1, s, 60, sf::Color::Black, sf::Text::Style::Bold, 60, 310);
        window.draw(currPlayerName);

        std::string capacity = std::to_string(game.get_players()[game.get_cur_player_id()].get_money()) + "$";
        set_text(currPlayerCapacity, font1, capacity, 40, sf::Color::Black, sf::Text::Style::Regular, 60,
                 370);
        window.draw(currPlayerCapacity);

        if (isRollDice) {
            dice1Sprite.setTextureRect(sf::IntRect(96 * (player.number_on_dice1 - 1), 0, 96, 96));
            dice2Sprite.setTextureRect(sf::IntRect(96 * (player.number_on_dice2 - 1), 0, 96, 96));
            window.draw(dice1Sprite);
            window.draw(dice2Sprite);
        }

        for (int i = 0; i < game.get_players().size(); i++) {
            if (i == game.get_cur_player_id() && isRollDice) {
                sf::Sprite sprite = game.get_players()[i].get_sprite();
                int currPosition = player.new_position;
                if (0 <= currPosition && currPosition <= 10) {
                    if(currPosition == 0) {
                        sprite.setPosition(1354 + i * 30, 870);
                    } else if (currPosition == 10) {
                        sprite.setPosition(552, 870);
                    }
                    else {
                        sprite.setPosition(1384 - i * 10 - game.get_players()[i].get_position() * 85, 870);
                    }
                } else if (11 <= currPosition && currPosition <= 20) {
                    sprite.setPosition(562, 870 - i * 10 - (currPosition - 10) * 85);
                } else if (21 <= currPosition && currPosition <= 30) {
                    sprite.setPosition(539 + i * 10 +(currPosition - 20) * 85, 100);
                } else {
                    sprite.setPosition(1354, 60 + i*10 + (currPosition - 30) * 85);
                }

                window.draw(sprite);
                continue;
            }
            sf::Sprite sprite = game.get_players()[i].get_sprite();
            int currPosition = game.get_players()[i].get_position();

            if (0 <= currPosition && currPosition <= 10) {
                if(currPosition == 0) {
                    sprite.setPosition(1354 + i * 30, 870);
                } else if (currPosition == 10) {
                    sprite.setPosition(552, 870);
                }
                else {
                    sprite.setPosition(1384 - i * 10 - game.get_players()[i].get_position() * 85, 870);
                }
            } else if (11 <= currPosition && currPosition <= 20) {
                sprite.setPosition(562, 870 - i * 10 - (currPosition - 10) * 85);
            } else if (21 <= currPosition && currPosition <= 30) {
                sprite.setPosition(539 + i * 10 +(currPosition - 20) * 85, 100);
            } else {
                sprite.setPosition(1354, 60 + i*10 + (currPosition - 30) * 85);
            }
            window.draw(sprite);
        }
    }
}


void GameWindow::setGame(Game &game1) {
    game = game1;
}