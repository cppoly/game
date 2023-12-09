#include "game_window.h"

GameWindow::GameWindow(sf::RenderWindow &window) {
    if (!backgroundImageTexture.loadFromFile("assets/sprite/BackgroundImage/playing_field.png") ||
        !playingFieldTexture.loadFromFile("assets/sprite/BackgroundImage/playingField.png") ||
        !startGameButtonTexture.loadFromFile("assets/sprite/Buttons/buttonStartGame.png") ||
        !completeTurnTexture.loadFromFile("assets/sprite/Buttons/buttonCompleteTurn.png") ||
        !rollDiceButtonTexture.loadFromFile("assets/sprite/Buttons/buttonRollDice.png") ||
        !playerInformationCardTexture.loadFromFile("assets/sprite/Card/playerInformationCard.png") ||
        !dice1Texture.loadFromFile("assets/sprite/DicePack/DiceSprSheetX96.png") ||
        !dice2Texture.loadFromFile("assets/sprite/DicePack/DiceSprSheetX96.png") ||
        !font1.loadFromFile("assets/fonts/Bionicle.ttf") ||
        !font2.loadFromFile("assets/fonts/big-shot.ttf") ||
        !myFieldsButtonTexture.loadFromFile("assets/sprite/Buttons/buttonMyFields.png") ||
        !swapButtonTexture.loadFromFile("assets/sprite/Buttons/buttonSwap.png") ||
        !loupeButtonTexture.loadFromFile("assets/sprite/Buttons/loupeButton.png")) {
        throw std::runtime_error("Can't load texture for GameWindow");
    }

    buyPage.loadBuyModeWindow(window);
    myFieldsPage.loadBuyModeWindow(window);
    payPage.loadBuyModeWindow(window);
    drawCardPage.loadBuyModeWindow(window);
    swapPage.loadBuyModeWindow(window);
    auctionPage.loadBuyModeWindow(window);

    // Background

    backgroundImageSprite = sf::Sprite(backgroundImageTexture);
    backgroundImageSprite.setScale((float) window.getSize().x / backgroundImageSprite.getLocalBounds().getSize().x,
                                   (float) window.getSize().y / backgroundImageSprite.getLocalBounds().getSize().y);

    playingFieldSprite = sf::Sprite(playingFieldTexture);
    playingFieldSprite.setOrigin(512, 512);
    playingFieldSprite.setPosition((float) window.getSize().x / 2.f, (float) window.getSize().y / 2.f);

    // Buttons

    startGameButtonSprite = sf::Sprite(startGameButtonTexture);
    startGameButtonSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    startGameButtonSprite.setPosition(((float) window.getSize().x / 2.f - 360 / 2),
                                      ((float) window.getSize().y / 2.f) - 109 / 2);

    completeTurnSprite = sf::Sprite(completeTurnTexture);
    completeTurnSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    completeTurnSprite.setOrigin(360, 0);
    completeTurnSprite.setPosition((float) window.getSize().x - 50, 100);
    completeTurnSprite.setScale(0.8f, 0.8f);


    rollDiceButtonSprite = sf::Sprite(rollDiceButtonTexture);
    rollDiceButtonSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    rollDiceButtonSprite.setPosition(50, 100);
    rollDiceButtonSprite.setScale(0.8f, 0.8f);

    myFieldsButtonSprite = sf::Sprite(myFieldsButtonTexture);
    myFieldsButtonSprite.setTextureRect({0, 0, 360, 109});
    myFieldsButtonSprite.setScale(0.8f, 0.8f);
    myFieldsButtonSprite.setPosition(50, (float) window.getSize().y - 150 - 109);

    loupeButtonSprite = sf::Sprite(loupeButtonTexture);
    loupeButtonSprite.setPosition(50 + 180 - 54, 220);
    loupeButtonSprite.setTextureRect({0, 0, 52, 49});

    swapButtonSprite = sf::Sprite(swapButtonTexture);
    swapButtonSprite.setTextureRect({0, 0, 360, 109});
    swapButtonSprite.setScale(0.8f, 0.8f);
    swapButtonSprite.setPosition(50, (float) window.getSize().y - 50 - 109);

    // Cards

    playerInformationCardSprite = sf::Sprite(playerInformationCardTexture);
    playerInformationCardSprite.setPosition(50, 300);

    dice1Sprite = sf::Sprite(dice1Texture);
    dice1Sprite.setPosition(100, 600);

    dice2Sprite = sf::Sprite(dice2Texture);
    dice2Sprite.setPosition(200, 600);
}

bool GameWindow::handleEvent(sf::Event &event, sf::RenderWindow &window) {
    auto point = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (startGameButtonSprite.getGlobalBounds().contains(point)) {
                if (!isGameStarted) {
                    onStartGame();
                }
            }
            if (myFieldsButtonSprite.getGlobalBounds().contains(point)) {
                if (!isActiveMyFieldsMode) {
                    isActiveMyFieldsMode = true;
                }
            }
            if (swapButtonSprite.getGlobalBounds().contains(point)) {
                if (!isActiveSwapMode) {
                    isActiveSwapMode = true;
                }
            }
            if (loupeButtonSprite.getGlobalBounds().contains(point)) {
                onZoomButtonClick();
            }
            if (completeTurnSprite.getGlobalBounds().contains(point)) {
                onCompleteTurn();
            }
            if (rollDiceButtonSprite.getGlobalBounds().contains(point)) {
                onRollDice();
            }
        }
    } else if (event.type == sf::Event::MouseMoved) {
        startGameButtonSprite.getGlobalBounds().contains(point)
        ? startGameButtonSprite.setTextureRect({360 * 2, 0, 360, 109})
        : startGameButtonSprite.setTextureRect({0, 0, 360, 109});

        myFieldsButtonSprite.getGlobalBounds().contains(point)
        ? myFieldsButtonSprite.setTextureRect({360 * 2, 0, 360, 109})
        : myFieldsButtonSprite.setTextureRect({0, 0, 360, 109});

        swapButtonSprite.getGlobalBounds().contains(point)
        ? swapButtonSprite.setTextureRect({360 * 2, 0, 360, 109})
        : swapButtonSprite.setTextureRect({0, 0, 360, 109});

        if (completeTurnSprite.getGlobalBounds().contains(point)) {
            game.get_is_player_roll_dice()
            ? completeTurnSprite.setTextureRect(sf::IntRect(360 * 2, 0, 360, 109))
            : completeTurnSprite.setTextureRect(sf::IntRect(360 * 3, 0, 360, 109));
        } else {
            game.get_is_player_roll_dice()
            ? completeTurnSprite.setTextureRect({0, 0, 360, 109})
            : completeTurnSprite.setTextureRect({360 * 3, 0, 360, 109});
        }

        if (rollDiceButtonSprite.getGlobalBounds().contains(point)) {
            game.get_is_player_roll_dice()
            ? rollDiceButtonSprite.setTextureRect(sf::IntRect(360 * 3, 0, 360, 109))
            : rollDiceButtonSprite.setTextureRect(sf::IntRect(360 * 2, 0, 360, 109));
        } else {
            game.get_is_player_roll_dice()
            ? rollDiceButtonSprite.setTextureRect({360 * 3, 0, 360, 109})
            : rollDiceButtonSprite.setTextureRect({0, 0, 360, 109});
        }
    } else {
        if (game.get_is_player_roll_dice()) {
            completeTurnSprite.setTextureRect({0, 0, 360, 109});
            rollDiceButtonSprite.setTextureRect({360 * 3, 0, 360, 109});
        } else {
            completeTurnSprite.setTextureRect({360 * 3, 0, 360, 109});
            rollDiceButtonSprite.setTextureRect({0, 0, 360, 109});
        }
    }
    if (isActiveBuyMode) {
        if (buyPage.handleEvent(event, window) == 1) {
            game.buy_field();
            isActiveBuyMode = false;
            myFieldsPage.setGame(game, game.get_cur_player_id());
        } else if (buyPage.handleEvent(event, window) == 2) {
            isActiveAuctionMode = true;
            auctionPage.setGame(game);
        }
    }
    if (isActiveAuctionMode) {
        if (auctionPage.handleEvent(event, window)) {
            isActiveAuctionMode = false;
        }
    }
    if (isActiveMyFieldsMode) {
        if (myFieldsPage.handleEvent(event, window)) {
            isActiveMyFieldsMode = false;
        }
    }

    if (isActivePayBankMode) {
        if (payPage.handleEvent(event, window)) {
            bool pay = game.pay_bank(player.amount_to_pay);
            if (pay) {
                isActivePayBankMode = false;
            }
        }
    } else if (isActivePayPlayerMode) {
        if (payPage.handleEvent(event, window)) {
            bool pay = game.pay_player(player.player_to_pay, player.amount_to_pay);
            if (pay) {
                isActivePayPlayerMode = false;
            }
        }
    }
    if (isActiveDrawCardMode) {
        if (drawCardPage.handleEvent(event, window)) {
            isActiveDrawCardMode = false;
        }
    }
    if (isActiveSwapMode) {
        if (swapPage.handleEvent(event, window)) {
            isActiveSwapMode = false;
        }
    }
    return false;
}

void GameWindow::onStartGame() {
    startGameButtonSprite.setTextureRect(sf::IntRect(360, 0, 360, 109));
    isGameStarted = true;
    game.start_game();
    myFieldsPage.setGame(game, game.get_cur_player_id());
    swapPage.setGame(game);
}

void GameWindow::onCompleteTurn() {
    if (game.get_is_player_roll_dice() && !isActiveMyFieldsMode) {
        completeTurnSprite.setTextureRect(sf::IntRect(360, 0, 360, 109));
        int id = game.next_turn();
        myFieldsPage.setGame(game, game.get_cur_player_id());
        swapPage.setGame(game);
        isRollDice = false;
        isActiveBuyMode = false;
        isActiveDrawCardMode = false;
        isActiveGoToJail = false;
        isActivePayBankMode = false;
        isActivePayPlayerMode = false;
    }
}

void GameWindow::onRollDice() {
    if (!game.get_is_player_roll_dice()) {
        rollDiceButtonSprite.setTextureRect(sf::IntRect(360, 0, 360, 109));
        player = game.player_move();
        isRollDice = true;
        if (player.funcs == GameFieldTypes::YOU_CAN_BUY) {
            isActiveBuyMode = true;
            buyPage.setGame(game);
        } else if (player.funcs == GameFieldTypes::PAY_BANK) {
            isActivePayBankMode = true;
            payPage.setGame(game, player);
            payPage.setType(1);
        } else if (player.funcs == GameFieldTypes::PAY_PLAYER) {
            isActivePayPlayerMode = true;
            payPage.setGame(game, player);
            payPage.setType(0);
        } else if (player.funcs == GameFieldTypes::DRAW_CARD) {
            card = game.draw_card();
            isActiveDrawCardMode = true;
            drawCardPage.setGame(game, card);
        } else if (player.funcs == GameFieldTypes::GO_TO_JAIL) {
            isActiveGoToJail = true;
        }
    }
}

void GameWindow::onZoomButtonClick() {
    if (!isActiveZoomMode) {
        isActiveZoomMode = true;
        loupeButtonSprite.setTextureRect({52, 0, 52, 49});
    } else {
        isActiveZoomMode = false;
        loupeButtonSprite.setPosition(50 + 180 - 54, 220);
        loupeButtonSprite.setTextureRect({0, 0, 52, 49});
    }
}

void GameWindow::zoomCurrPlayer(sf::RenderWindow &window) {
    auto currPlayerId = game.get_cur_player_id();
    auto currPosition = game.get_players()[game.get_cur_player_id()]->get_position();
    sf::Sprite currPlayerSprite = game.get_players()[game.get_cur_player_id()]->get_sprite();

    sf::View view;
    view.setSize((float) window.getSize().x / 3.f, (float) window.getSize().y / 3.f);


    if (currPosition == 0) {
        view.setCenter((float) (1354 - (currPosition % 11)), 870);
        currPlayerSprite.setPosition((float) (1354 - (currPosition % 10)), 870);
    } else if (currPosition % 10 == 0) {
        view.setCenter(552, 870);
        currPlayerSprite.setPosition(552, 870);
    } else {
        view.setCenter((float) (1384 - currPlayerId * 10 - (currPosition % 10) * 85), 870);
        currPlayerSprite.setPosition((float) (1384 - currPlayerId * 10 - (currPosition % 10) * 85), 870);
    }

    loupeButtonSprite.setPosition(view.getCenter().x - 300, view.getCenter().y - 160);

    playingFieldSprite.setRotation((float) -90 * (currPosition / 11));
    window.setView(view);
    window.draw(loupeButtonSprite);
    window.draw(currPlayerSprite);
}

void GameWindow::draw(sf::RenderWindow &window, sf::Event &event) {
    window.clear();
    window.draw(backgroundImageSprite);
    window.draw(playingFieldSprite);

    if (!isGameStarted) {
        backgroundImageSprite.setColor(sf::Color(255, 255, 255, 60));
        playingFieldSprite.setColor(sf::Color(255, 255, 255, 60));
        window.draw(playingFieldSprite);
        window.draw(startGameButtonSprite);
    } else {
        window.setView(window.getDefaultView());
        backgroundImageSprite.setColor(sf::Color(255, 255, 255, 255));
        playingFieldSprite.setColor({255, 255, 255, 255});
        playingFieldSprite.setRotation(0);

        // Draw player activity

        if (isActiveZoomMode) {
            zoomCurrPlayer(window);
        } else if (isActiveMyFieldsMode) {
            backgroundImageSprite.setColor(sf::Color(255, 255, 255, 60));
            playingFieldSprite.setColor(sf::Color(255, 255, 255, 60));
            myFieldsPage.draw(window, event);
        } else if (isActiveSwapMode) {
            backgroundImageSprite.setColor(sf::Color(255, 255, 255, 60));
            playingFieldSprite.setColor(sf::Color(255, 255, 255, 60));
            swapPage.draw(window, event);
        } else if (isActiveAuctionMode) {
            backgroundImageSprite.setColor(sf::Color(255, 255, 255, 60));
            playingFieldSprite.setColor(sf::Color(255, 255, 255, 60));

            auctionPage.draw(window, event);
        } else {
            drawPlayerInformation(window);
            if (isActiveBuyMode) {
                backgroundImageSprite.setColor(sf::Color(255, 255, 255, 60));
                playingFieldSprite.setColor({255, 255, 255, 60});
                buyPage.draw(window, event);
            } else if (isActiveDrawCardMode) {
                backgroundImageSprite.setColor(sf::Color(255, 255, 255, 60));
                playingFieldSprite.setColor({255, 255, 255, 60});
                drawCardPage.draw(window, event);
            } else if (isActivePayBankMode | isActivePayPlayerMode) {
                backgroundImageSprite.setColor(sf::Color(255, 255, 255, 60));
                playingFieldSprite.setColor({255, 255, 255, 60});
                payPage.draw(window, event);
            } else if (isActiveGoToJail) {
                game.get_players()[game.get_cur_player_id()]->set_position(10);

                window.draw(completeTurnSprite);
                window.draw(rollDiceButtonSprite);
                window.draw(loupeButtonSprite);
                drawPlayers(window);

                window.draw(myFieldsButtonSprite);
            } else {
                window.draw(completeTurnSprite);
                window.draw(rollDiceButtonSprite);
                window.draw(loupeButtonSprite);
                drawPlayers(window);
                window.draw(myFieldsButtonSprite);
                window.draw(swapButtonSprite);
            }
        }
    }
}

void GameWindow::setGame(Game &game1) {
    game = game1;
}

void GameWindow::drawPlayerInformation(sf::RenderWindow &window) {
    window.draw(playerInformationCardSprite);

    // Player name
    std::string s = game.get_players()[game.get_cur_player_id()]->get_name();
    set_text(currPlayerName, font1, s, 60, sf::Color::Black, sf::Text::Style::Bold, 60, 310);
    window.draw(currPlayerName);

    // Player capacity
    std::string capacity = std::to_string(game.get_players()[game.get_cur_player_id()]->get_money()) + "$";
    set_text(currPlayerCapacity, font2, capacity, 40, sf::Color::Black, sf::Text::Style::Regular, 60,
             400);
    window.draw(currPlayerCapacity);

    // Player jail cards
    std::string amountJailCards = "Count of jail cards: " + std::to_string(
            game.get_players()[game.get_cur_player_id()]->get_amount_of_jail_cards());
    set_text(currAmountJailCards, font2, amountJailCards, 20, sf::Color::Black, sf::Text::Style::Regular, 60, 470);
    window.draw(currAmountJailCards);

    if (isRollDice) {
        drawDice(window);
    }
}

void GameWindow::drawDice(sf::RenderWindow &window) {
    dice1Sprite.setTextureRect(sf::IntRect(96 * (player.number_on_dice1 - 1), 0, 96, 96));
    dice2Sprite.setTextureRect(sf::IntRect(96 * (player.number_on_dice2 - 1), 0, 96, 96));
    window.draw(dice1Sprite);
    window.draw(dice2Sprite);

}

void GameWindow::drawPlayers(sf::RenderWindow &window) {
    for (int i = 0; i < game.get_players().size(); i++) {
        if (i == game.get_cur_player_id() && isRollDice) {
            drawPlayer(window, player.new_position, i);
            continue;
        }
        drawPlayer(window, game.get_players()[i]->get_position(), i);
    }
}

void GameWindow::drawPlayer(sf::RenderWindow &window, int currPosition, int i) {
    sf::Sprite sprite = game.get_players()[i]->get_sprite();
    if (0 <= currPosition && currPosition <= 10) {
        if (currPosition == 0) {
            sprite.setPosition((float) (1354 + i * 30), 870);
        } else if (currPosition == 10) {
            sprite.setPosition(552, 870);
        } else {
            sprite.setPosition((float) (1384 - i * 10 - game.get_players()[i]->get_position() * 85), 870);
        }
    } else if (11 <= currPosition && currPosition <= 20) {
        sprite.setOrigin(0, 76);
        sprite.setRotation(90);
        sprite.setPosition(562, (float) (963 - i * 10 - (currPosition - 10) * 85));

    } else if (21 <= currPosition && currPosition <= 30) {
        sprite.setOrigin(42, 76);
        sprite.setRotation(180);
        sprite.setPosition((float) (534 + i * 10 + (currPosition - 20) * 85), 140);
    } else {

        sprite.setOrigin(0, 76);
        sprite.setRotation(-90);
        sprite.setPosition(1357, (float) (117 + i * 10 + (currPosition - 30) * 85));
    }
    window.draw(sprite);
}

