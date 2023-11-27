#include "game_window.h"

GameWindow::GameWindow(sf::RenderWindow &window) {
    if (!backgroundImageTexture.loadFromFile("assets/sprite/BackgroundImage/playing_field.png") ||
        !playingFieldTexture.loadFromFile("assets/sprite/BackgroundImage/playingField.png") ||
        !startGameButtonTexture.loadFromFile("assets/sprite/Buttons/buttonStartGame.png") ||
        !completeTurnTexture.loadFromFile("assets/sprite/Buttons/buttonCompleteTurn.png") ||
        !rollDiceButtonTexture.loadFromFile("assets/sprite/Buttons/buttonRollDice.png") ||
        !buyButtonTexture.loadFromFile("assets/sprite/Buttons/buttonBuy.png") ||
        !auctionButtonTexture.loadFromFile("assets/sprite/Buttons/buttonAuction.png") ||
        !okButtonTexture.loadFromFile("assets/sprite/Buttons/okButton.png") ||
        !payButtonTexture.loadFromFile("assets/sprite/Buttons/payButton.png") ||
        !myFieldsButtonTexture.loadFromFile("assets/sprite/Buttons/buttonMyFields.png") ||
        !playerInformationCardTexture.loadFromFile("assets/sprite/Card/playerInformationCard.png") ||
        !dice1Texture.loadFromFile("assets/sprite/DicePack/DiceSprSheetX96.png") ||
        !dice2Texture.loadFromFile("assets/sprite/DicePack/DiceSprSheetX96.png") ||
        !fieldCardTexture.loadFromFile("assets/sprite/Card/FieldCard/fieldCard.png") ||
        !font1.loadFromFile("assets/fonts/Bionicle.ttf") ||
        !font2.loadFromFile("assets/fonts/big-shot.ttf") ||
        !vanCardTexture.loadFromFile("assets/sprite/Card/FieldCard/fieldVanCard.png") ||
        !myFieldsCardTexture.loadFromFile("assets/sprite/Card/FieldCard/myFieldsCard.png") ||
        !laundryCardTexture.loadFromFile("assets/sprite/Card/FieldCard/fieldLaundromatCard.png") ||
        !porsheCardTexture.loadFromFile("assets/sprite/Card/FieldCard/fieldPorsheCard.png") ||
        !bmwCardTexture.loadFromFile("assets/sprite/Card/FieldCard/fieldBMWCard.png") ||
        !teslaCardTexture.loadFromFile("assets/sprite/Card/FieldCard/fieldTeslaCard.png") ||
        !audiCardTexture.loadFromFile("assets/sprite/Card/FieldCard/fieldAudiCard.png") ||
        !communityChestCardTexture.loadFromFile("assets/sprite/Card/FieldCard/CommunityChestCard.png") ||
        !taxCardTexture.loadFromFile("assets/sprite/Card/FieldCard/fieldTaxCard.png") ||
        !chanceCardTexture.loadFromFile("assets/sprite/Card/FieldCard/ChanceCard.png") ||
        !payToPlayerCardTexture.loadFromFile("assets/sprite/Card/FieldCard/payPlayerCard.png") ||
        !loupeButtonTexture.loadFromFile("assets/sprite/Buttons/loupeButton.png")) {
        throw std::runtime_error("Can't load texture for GameWindow");
    }


    // Background
    backgroundImageSprite = sf::Sprite(backgroundImageTexture);
    backgroundImageSprite.setScale(window.getSize().x / backgroundImageSprite.getLocalBounds().getSize().x,
                                   window.getSize().y / backgroundImageSprite.getLocalBounds().getSize().y);

    playingFieldSprite = sf::Sprite(playingFieldTexture);
    playingFieldSprite.setOrigin(512, 512);
    playingFieldSprite.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);

    // Buttons
    startGameButtonSprite = sf::Sprite(startGameButtonTexture);
    startGameButtonSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    startGameButtonSprite.setPosition((window.getSize().x / 2.f) - 360 / 2,
                                      (window.getSize().y / 2.f) - 109 / 2);

    completeTurnSprite = sf::Sprite(completeTurnTexture);
    completeTurnSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    completeTurnSprite.setOrigin(360, 0);
    completeTurnSprite.setPosition(window.getSize().x - 50, 100);
    completeTurnSprite.setScale(0.8f, 0.8f);


    rollDiceButtonSprite = sf::Sprite(rollDiceButtonTexture);
    rollDiceButtonSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    rollDiceButtonSprite.setPosition(50, 100);
    rollDiceButtonSprite.setScale(0.8f, 0.8f);

    myFieldsButtonSprite = sf::Sprite(myFieldsButtonTexture);
    myFieldsButtonSprite.setTextureRect({0, 0, 360, 109});
    myFieldsButtonSprite.setScale(0.8f, 0.8f);
    myFieldsButtonSprite.setPosition(50, window.getSize().y - 100 - 109);

    buyButtonSprite = sf::Sprite(buyButtonTexture);
    buyButtonSprite.setPosition((window.getSize().x / 2.f) - 270, window.getSize().y - 150);
    buyButtonSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    buyButtonSprite.setScale(0.6f, 0.6f);

    auctionButtonSprite = sf::Sprite(auctionButtonTexture);
    auctionButtonSprite.setPosition((window.getSize().x / 2.f) + 50, window.getSize().y - 150);
    auctionButtonSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    auctionButtonSprite.setScale(0.6f, 0.6f);

    okButtonSprite = sf::Sprite(okButtonTexture);
    okButtonSprite.setPosition((window.getSize().x / 2.f) - 100, window.getSize().y - 150);
    okButtonSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    okButtonSprite.setScale(0.6f, 0.6f);

    payButtonSprite = sf::Sprite(payButtonTexture);
    payButtonSprite.setPosition((window.getSize().x / 2.f) - 100, window.getSize().y - 150);
    payButtonSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    payButtonSprite.setScale(0.6f, 0.6f);

    loupeButtonSprite = sf::Sprite(loupeButtonTexture);
    loupeButtonSprite.setPosition(50 + 180 - 54, 220);
    loupeButtonSprite.setTextureRect({0, 0, 52, 49});

    // Cards

    playerInformationCardSprite = sf::Sprite(playerInformationCardTexture);
    playerInformationCardSprite.setPosition(50, 300);

    for (int i = 0; i < cardsRentTexture.size(); i++) {

        if (!cardsRentTexture[i].loadFromFile(
                "assets/sprite/Card/RentCard/rent" + std::to_string(i + 1) + "Card.png")) {
            throw std::runtime_error("Can't load texture of rent card");
        }
        cardsRentSprite[i] = sf::Sprite(cardsRentTexture[i]);
        cardsRentSprite[i].setPosition(window.getSize().x - 50 - 300, 300);
        cardsRentSprite[i].setScale(1, 1.2f);
    }

    vanCardSprite = sf::Sprite(vanCardTexture);
    laundryCardSprite = sf::Sprite(laundryCardTexture);
    porsheCardSprite = sf::Sprite(porsheCardTexture);
    bmwCardSprite = sf::Sprite(bmwCardTexture);
    teslaCardSprite = sf::Sprite(teslaCardTexture);
    audiCardSprite = sf::Sprite(audiCardTexture);
    taxCardSprite = sf::Sprite(taxCardTexture);

    vanCardSprite.setPosition((window.getSize().x / 2.f) - 64 * 5, (window.getSize().y / 2.f) - 128 * 4);
    vanCardSprite.setScale(5.f, 4.f);

    laundryCardSprite.setPosition((window.getSize().x / 2.f) - 64 * 5, (window.getSize().y / 2.f) - 128 * 4);
    laundryCardSprite.setScale(5.f, 4.f);

    porsheCardSprite.setPosition((window.getSize().x / 2.f) - 64 * 5, (window.getSize().y / 2.f) - 128 * 4);
    porsheCardSprite.setScale(5.f, 4.f);

    bmwCardSprite.setPosition((window.getSize().x / 2.f) - 64 * 5, (window.getSize().y / 2.f) - 128 * 4);
    bmwCardSprite.setScale(5.f, 4.f);

    teslaCardSprite.setPosition((window.getSize().x / 2.f) - 64 * 5, (window.getSize().y / 2.f) - 128 * 4);
    teslaCardSprite.setScale(5.f, 4.f);

    audiCardSprite.setPosition((window.getSize().x / 2.f) - 64 * 5, (window.getSize().y / 2.f) - 128 * 4);
    audiCardSprite.setScale(5.f, 4.f);

    taxCardSprite.setPosition((window.getSize().x / 2.f) - 64 * 5, (window.getSize().y / 2.f) - 128 * 4);
    taxCardSprite.setScale(5.f, 4.f);

    dice1Sprite = sf::Sprite(dice1Texture);
    dice1Sprite.setPosition(100, 600);

    dice2Sprite = sf::Sprite(dice2Texture);
    dice2Sprite.setPosition(200, 600);

    fieldCardSprite = sf::Sprite(fieldCardTexture);
    fieldCardSprite.setPosition((window.getSize().x / 2.f) - 64 * 5, (window.getSize().y / 2.f) - 128 * 4);
    fieldCardSprite.setScale(5.f, 4.f);

    chanceCardSprite = sf::Sprite(chanceCardTexture);
    chanceCardSprite.setPosition(((float) window.getSize().x / 2.f) - 64 * 5,
                                 ((float) window.getSize().y / 2.f) - 128 * 4);
    chanceCardSprite.setScale(5.f, 4.f);

    communityChestCardSprite = sf::Sprite(communityChestCardTexture);
    communityChestCardSprite.setPosition(((float) window.getSize().x / 2.f) - 64 * 5,
                                         ((float) window.getSize().y / 2.f) - 128 * 4);
    communityChestCardSprite.setScale(5.f, 4.f);

    myFieldsCardSprite = sf::Sprite(myFieldsCardTexture);
    myFieldsCardSprite.setPosition(((float) window.getSize().x / 2.f) - (300 * 2.5f),
                                   ((float) window.getSize().y / 2.f) - (200 * 2.5f));
    myFieldsCardSprite.setScale(2.5f, 2.5f);

    payToPlayerCardSprite = sf::Sprite(payToPlayerCardTexture);
    payToPlayerCardSprite.setPosition((window.getSize().x / 2.f) - 64 * 5, (window.getSize().y / 2.f) - 128 * 4);
    payToPlayerCardSprite.setScale(5.f, 4.f);

}

bool GameWindow::handleEvent(sf::Event &event, sf::RenderWindow &window) {
    auto point = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (startGameButtonSprite.getGlobalBounds().contains(point)) {
                if (!isGameStarted) {
                    onStartGame(window);
                }
            }
            if (myFieldsButtonSprite.getGlobalBounds().contains(point)) {
                if (!isActiveMyFieldsMode) {
                    isActiveMyFieldsMode = true;
                }
            }
//            auto p = [&](ProfitableField& x){ return x.getGlobalBounds().contains(point); };

            if (isActiveMyFieldsMode)  {
                isActiveZoomCardMode = true;
            }

            if (isActiveZoomCardMode) {
                isActiveZoomCardMode = false;
            }
            if (loupeButtonSprite.getGlobalBounds().contains(point)) {
                onZoomButtonClick(window);
            }
            if (completeTurnSprite.getGlobalBounds().contains(point)) {
                onCompleteTurn(window);
            }
            if (rollDiceButtonSprite.getGlobalBounds().contains(point)) {
                onRollDice(window);
            }
            if (buyButtonSprite.getGlobalBounds().contains(point)) {
                if (isActiveBuyMode) {
                    onBuyClick(window);
                }
            }
            if (okButtonSprite.getGlobalBounds().contains(point)) {
                if (isActiveDrawCardMode) {
                    onOkClick(window);
                } else if (isActiveMyFieldsMode && !isActiveZoomCardMode) {
                    isActiveMyFieldsMode = false;
                }

            }
            if (payButtonSprite.getGlobalBounds().contains(point)) {
                onPayButtonClick(window);
            }
        }
    } else if (event.type == sf::Event::MouseMoved) {
        startGameButtonSprite.getGlobalBounds().contains(point)
        ? startGameButtonSprite.setTextureRect({360 * 2, 0, 360, 109})
        : startGameButtonSprite.setTextureRect({0, 0, 360, 109});

        buyButtonSprite.getGlobalBounds().contains(point)
        ? buyButtonSprite.setTextureRect(sf::IntRect(360 * 2, 0, 360, 109))
        : buyButtonSprite.setTextureRect({0, 0, 360, 109});

        auctionButtonSprite.getGlobalBounds().contains(point)
        ? auctionButtonSprite.setTextureRect({360 * 2, 0, 360, 109})
        : auctionButtonSprite.setTextureRect({0, 0, 360, 109});

        okButtonSprite.getGlobalBounds().contains(point)
        ? okButtonSprite.setTextureRect({360 * 2, 0, 360, 109})
        : okButtonSprite.setTextureRect({0, 0, 360, 109});

        payButtonSprite.getGlobalBounds().contains(point)
        ? payButtonSprite.setTextureRect({360 * 2, 0, 360, 109})
        : payButtonSprite.setTextureRect({0, 0, 360, 109});

        myFieldsButtonSprite.getGlobalBounds().contains(point)
        ? myFieldsButtonSprite.setTextureRect({360 * 2, 0, 360, 109})
        : myFieldsButtonSprite.setTextureRect({0, 0, 360, 109});

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

    return false;
}

void GameWindow::onStartGame(sf::RenderWindow &window) {
    startGameButtonSprite.setTextureRect(sf::IntRect(360, 0, 360, 109));
    isGameStarted = true;
    game.start_game();
}

void GameWindow::onCompleteTurn(sf::RenderWindow &window) {
    if (game.get_is_player_roll_dice() && !isActiveMyFieldsMode) {
        completeTurnSprite.setTextureRect(sf::IntRect(360, 0, 360, 109));
        int id = game.next_turn();
        isRollDice = false;
        isActiveBuyMode = false;
        isActiveDrawCardMode = false;
        isActiveGoToJail = false;
        isActivePayBankMode = false;
        isActivePayPlayerMode = false;
    }
}

void GameWindow::onRollDice(sf::RenderWindow &window) {
    if (!game.get_is_player_roll_dice()) {
        rollDiceButtonSprite.setTextureRect(sf::IntRect(360, 0, 360, 109));
        player = game.player_move();
        isRollDice = true;
        if (player.funcs == GameFieldTypes::YOU_CAN_BUY) {
            isActiveBuyMode = true;
        } else if (player.funcs == GameFieldTypes::YOU_CAN_BUY) {
            isActiveBuyMode = true;
        } else if (player.funcs == GameFieldTypes::PAY_BANK) {
            isActivePayBankMode = true;
        } else if (player.funcs == GameFieldTypes::PAY_PLAYER) {
            isActivePayPlayerMode = true;
        } else if (player.funcs == GameFieldTypes::DRAW_CARD) {
            card = game.draw_card();
            isActiveDrawCardMode = true;
        } else if (player.funcs == GameFieldTypes::GO_TO_JAIL) {
            isActiveGoToJail = true;
        } else {
            isActiveDoNothing = true;
        }
    }
}

void GameWindow::onBuyClick(sf::RenderWindow &window) {
    game.buy_field();
    isActiveBuyMode = false;
}

void GameWindow::onOkClick(sf::RenderWindow &window) {
    okButtonSprite.setTextureRect({360, 0, 360, 109});
    isActiveDrawCardMode = false;
    // TODO
}

void GameWindow::onPayButtonClick(sf::RenderWindow &window) {
    payButtonSprite.setTextureRect({360, 0, 360, 109});
    if (isActivePayBankMode) {
        bool pay = game.pay_bank(player.amount_to_pay);
        if (pay) {
            isActivePayBankMode = false;
        }
    } else if (isActivePayPlayerMode) {
        bool pay = game.pay_player(player.player_to_pay, player.amount_to_pay);
        if (pay) {
            isActivePayPlayerMode = false;
        }
    }
}

void GameWindow::onZoomButtonClick(sf::RenderWindow &window) {
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
    auto currPosition = game.get_players()[game.get_cur_player_id()].get_position();
    sf::Sprite currPlayerSprite = game.get_players()[game.get_cur_player_id()].get_sprite();

    sf::View view;
    view.setSize(window.getSize().x / 3.f, window.getSize().y / 3.f);

    if (currPosition == 0) {
        view.setCenter(1354 - (currPosition % 11), 870);
        currPlayerSprite.setPosition(1354 - (currPosition % 10), 870);
    } else if (currPosition % 10 == 0) {
        view.setCenter(552, 870);
        currPlayerSprite.setPosition(552, 870);
    } else {
        view.setCenter(1384 - currPlayerId * 10 - (currPosition % 10) * 85, 870);
        currPlayerSprite.setPosition(1384 - currPlayerId * 10 - (currPosition % 10) * 85, 870);
    }

    loupeButtonSprite.setPosition(view.getCenter().x - 300, view.getCenter().y- 160);
    playingFieldSprite.setRotation((float)(-90 * (currPosition / 11)));
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
            auto fields = game.get_players()[game.get_cur_player_id()].get_fields();
            currField = fields;
            drawMyFields(window, event, fields);
        } else {
            drawPlayerInformation(window);
            if (isActiveBuyMode) {
                drawBuyCard(window);
            } else if (isActiveDrawCardMode) {
                drawDrawCard(window);
            } else if (isActivePayBankMode) {
                drawPayBankCard(window);
            } else if (isActivePayPlayerMode) {
                drawPayPlayerCard(window);
            } else if (isActiveGoToJail) {
//              game.go_to_jail();
            } else {
                window.draw(completeTurnSprite);
                window.draw(rollDiceButtonSprite);
                window.draw(loupeButtonSprite);
                drawPlayers(window);
                window.draw(myFieldsButtonSprite);
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
    std::string s = game.get_players()[game.get_cur_player_id()].get_name();
    set_text(currPlayerName, font1, s, 60, sf::Color::Black, sf::Text::Style::Bold, 60, 310);
    window.draw(currPlayerName);

    // Player capacity
    std::string capacity = std::to_string(game.get_players()[game.get_cur_player_id()].get_money()) + "$";
    set_text(currPlayerCapacity, font2, capacity, 40, sf::Color::Black, sf::Text::Style::Regular, 60,
             400);
    window.draw(currPlayerCapacity);

    // Player jail cards
    std::string amountJailCards = "Count of jail cards: " + std::to_string(
            game.get_players()[game.get_cur_player_id()].get_amount_of_jail_cards());
    set_text(currAmountJailCards, font2, amountJailCards, 20, sf::Color::Black, sf::Text::Style::Regular, 60, 470);
    window.draw(currAmountJailCards);

    if (isRollDice) {
        drawDice(window);
    }
}

void GameWindow::drawBuyCard(sf::RenderWindow &window) {
    backgroundImageSprite.setColor(sf::Color(255, 255, 255, 60));
    playingFieldSprite.setColor({255, 255, 255, 60});

    auto currPlayer = game.get_players()[game.get_cur_player_id()];
    auto field = dynamic_cast<ProfitableField *>(game.get_fields()[currPlayer.get_position()]);

    std::string price = std::to_string(field->get_price());
    sf::Text priceText;

    std::string fieldName = field->get_name();
    sf::Text fieldNameText;

    set_text(priceText, font2, price, 50, sf::Color::Black, sf::Text::Style::Regular,
             (window.getSize().x / 2.f) - 50, 830);
    set_text(fieldNameText, font2, fieldName, 30, sf::Color::Black, sf::Text::Style::Regular,
             (window.getSize().x / 2.f) - 64 * 4, 230);

    if (field->get_type() == FieldTypes::STREET) {
        window.draw(fieldCardSprite);
        sf::Sprite rentCardSprite = sf::Sprite(cardsRentSprite[field->get_collection_type() - 1]);
        drawRentStreetCard(window, field, rentCardSprite, window.getSize().x - 50 - 300, 300, 1.f, 1.f);
    } else if (field->get_type() == FieldTypes::STATION) {
        if (fieldName == "Porshe") {
            window.draw(porsheCardSprite);
        } else if (fieldName == "BMW") {
            window.draw(bmwCardSprite);
        } else if (fieldName == "Tesla") {
            window.draw(teslaCardSprite);
        } else {
            window.draw(audiCardSprite);
        }
        drawRentStationCard(window, field, window.getSize().x - 50 - 300, 300, 1.f, 1.f);
    } else if (field->get_type() == FieldTypes::UTILITY) {
        if (fieldName == "Laundromat") {
            window.draw(laundryCardSprite);
        } else {
            window.draw(vanCardSprite);
        }
        drawRentUtilityCard(window, field, window.getSize().x - 50 - 300, 300, 1.f, 1.f);
    }
    window.draw(buyButtonSprite);
    window.draw(auctionButtonSprite);
    window.draw(fieldNameText);
    window.draw(priceText);
}

void GameWindow::drawDrawCard(sf::RenderWindow &window) {
    backgroundImageSprite.setColor(sf::Color(255, 255, 255, 60));
    playingFieldSprite.setColor({255, 255, 255, 60});

    auto currPlayer = game.get_players()[game.get_cur_player_id()];
    auto field = dynamic_cast<Field *>(game.get_fields()[currPlayer.get_position()]);

    if (field->get_type() == FieldTypes::CHANCE) {
        window.draw(chanceCardSprite);
    } else {
        window.draw(communityChestCardSprite);
    }
    window.draw(okButtonSprite);
}

void GameWindow::drawPayBankCard(sf::RenderWindow &window) {
    backgroundImageSprite.setColor(sf::Color(255, 255, 255, 60));
    playingFieldSprite.setColor({255, 255, 255, 60});

    auto currPlayer = game.get_players()[game.get_cur_player_id()];
    auto field = dynamic_cast<Tax *>(game.get_fields()[currPlayer.get_position()]);

    std::string price = std::to_string(field->get_price());
    sf::Text priceText;
    set_text(priceText, font2, price, 50, sf::Color::Black, sf::Text::Style::Regular,
             (window.getSize().x / 2.f) - 50, 830);

    window.draw(taxCardSprite);
    window.draw(priceText);
    window.draw(payButtonSprite);
}

void GameWindow::drawPayPlayerCard(sf::RenderWindow &window) {
    window.draw(payToPlayerCardSprite);
    window.draw(payButtonSprite);
    sf::Sprite playerToPaySprite = game.get_players()[player.player_to_pay].get_sprite();
    playerToPaySprite.setPosition(window.getSize().x, window.getSize().y);
}

void GameWindow::drawDice(sf::RenderWindow &window) {
    dice1Sprite.setTextureRect(sf::IntRect(96 * (player.number_on_dice1 - 1), 0, 96, 96));
    dice2Sprite.setTextureRect(sf::IntRect(96 * (player.number_on_dice2 - 1), 0, 96, 96));
    window.draw(dice1Sprite);
    window.draw(dice2Sprite);

}

void GameWindow::drawMyFields(sf::RenderWindow &window, sf::Event &event, std::vector<ProfitableField *> &fields) {
    backgroundImageSprite.setColor(sf::Color(255, 255, 255, 60));
    playingFieldSprite.setColor({255, 255, 255, 60});

    window.draw(myFieldsCardSprite);
    for (int i = 0; i < fields.size(); i++) {
        if (fields[i]->get_type() == FieldTypes::STREET) {
            sf::Sprite rentCardSprite = sf::Sprite(cardsRentSprite[fields[i]->get_collection_type() - 1]);

            myFieldsCardSprite.setColor({255, 255, 255, 255});
                drawRentStreetCard(window, fields[i], cardsRentSprite[fields[i]->get_collection_type() - 1], (float)(200 + 300 * 0.7 * i + 100), 100.f + 450.f * (i / 7), 0.5f,
                                   0.5f);
                window.draw(okButtonSprite);

        } else if (fields[i]->get_type() == FieldTypes::STATION) {
            drawRentStationCard(window, fields[i], 200 + 300 * 0.7 * i + 100, 100 + 450 * (i / 7), 0.5f, 0.5f);
            window.draw(okButtonSprite);
        } else {
            drawRentUtilityCard(window, fields[i], 200 + 300 * 0.7 * i + 100, 100 + 450 * (i / 7), 0.5f, 0.5f);
            window.draw(okButtonSprite);
        }
    }
}

void
GameWindow::drawRentStreetCard(sf::RenderWindow &window, ProfitableField *field, sf::Sprite &rentCardSprite, float x,
                               float y, float scaleX,
                               float scaleY) {
    auto street = dynamic_cast<Street *>(field);
//    sf::Sprite rentCardSprite = sf::Sprite(cardsRentSprite[field->get_collection_type() - 1]);
    rentCardSprite.setPosition(x, y);
    rentCardSprite.setScale(scaleX, 1.2 * scaleY);
    window.draw(rentCardSprite);

    std::string name = field->get_name();
    std::string rent = "Rent:  " + std::to_string(field->get_rent());
    std::string rentWith1House = "Rent with 1 house:   " + std::to_string(field->get_rent_vector()[0]);
    std::string rentWith2House = "Rent with 2 houses:  " + std::to_string(field->get_rent_vector()[1]);
    std::string rentWith3House = "Rent with 3 houses:  " + std::to_string(field->get_rent_vector()[2]);
    std::string rentWith4House = "Rent with 4 houses:  " + std::to_string(field->get_rent_vector()[3]);
    std::string rentWith1Hotel = "Rent with 1 hotel:   " + std::to_string(field->get_rent_vector()[4]);
    std::string mortgageValue = "Mortgage value:       " + std::to_string(field->get_mortgage_price());
    std::string redemptionValue = "Redemption value:     " + std::to_string(field->get_redemption_price());

    std::string price1House = std::to_string(street->get_house_price());
    std::string price1Hotel = std::to_string(street->get_hotel_price());

    sf::Text nameText;
    sf::Text rentText;
    sf::Text rentWith1HouseText;
    sf::Text rentWith2HouseText;
    sf::Text rentWith3HouseText;
    sf::Text rentWith4HouseText;
    sf::Text rentWith1HotelText;
    sf::Text mortgageValueText;
    sf::Text redemptionValueText;
    sf::Text price1HouseText;
    sf::Text price1HotelText;

    set_text(nameText, font2, name, (int) (15 * scaleX), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (100 * scaleY * 1.1));
    set_text(rentText, font2, rent, (int) (15 * scaleX), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (130 * scaleY * 1.1));
    set_text(rentWith1HouseText, font2, rentWith1House, (int) (15 * scaleX), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (160 * scaleY * 1.1));
    set_text(rentWith2HouseText, font2, rentWith2House, (int) (15 * scaleX), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (190 * scaleY * 1.1));
    set_text(rentWith3HouseText, font2, rentWith3House, (int) (15 * scaleX), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (220 * scaleY * 1.1));
    set_text(rentWith4HouseText, font2, rentWith4House, (int) (15 * scaleX), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (250 * scaleY * 1.1));
    set_text(rentWith1HotelText, font2, rentWith1Hotel, (int) (15 * scaleX), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (280 * scaleY * 1.1));
    set_text(mortgageValueText, font2, mortgageValue, (int) (15 * scaleX), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (310 * scaleY * 1.1));
    set_text(redemptionValueText, font2, redemptionValue, (int) (15 * scaleX), sf::Color::Black,
             sf::Text::Style::Regular,
             x + 20, y + (340 * scaleY * 1.1));
    set_text(price1HouseText, font2, price1House, (int) (25 * scaleX), sf::Color::Black, sf::Text::Style::Regular,
             x + 100, y + (350 * scaleY * 1.2));
    set_text(price1HotelText, font2, price1Hotel, (int) (25 * scaleX), sf::Color::Black, sf::Text::Style::Regular,
             x + 100, y + (400 * scaleY * 1.2));

    window.draw(nameText);
    window.draw(rentText);
    window.draw(rentWith1HouseText);
    window.draw(rentWith2HouseText);
    window.draw(rentWith3HouseText);
    window.draw(rentWith4HouseText);
    window.draw(rentWith1HotelText);
    window.draw(mortgageValueText);
    window.draw(redemptionValueText);
    window.draw(price1HouseText);
    window.draw(price1HotelText);
}

void GameWindow::drawRentStationCard(sf::RenderWindow &window, ProfitableField *field, float x, float y, float scaleX,
                                     float scaleY) {
    sf::Sprite rentCard = sf::Sprite(cardsRentTexture[2]);
    rentCard.setPosition(x, y);
    rentCard.setScale(scaleX, 1.2 * scaleY);
    window.draw(rentCard);
    auto station = dynamic_cast<Station *>(field);

    std::string name = station->get_name();
    std::string rentWith1Station = "Rent:   " + std::to_string(station->get_rent_vector()[0]);
    std::string rentWith2Station = "If 2 are owned:  " + std::to_string(station->get_rent_vector()[1]);
    std::string rentWith3Station = "If 3 are owned:  " + std::to_string(station->get_rent_vector()[2]);
    std::string rentWith4Station = "If 4 are owned:  " + std::to_string(station->get_rent_vector()[3]);
    std::string mortgageValue = "Mortgage value:       " + std::to_string(station->get_mortgage_price());
    std::string redemptionValue = "Redemption value:     " + std::to_string(station->get_redemption_price());

    sf::Text nameText;
    sf::Text rentWith1StationText;
    sf::Text rentWith2StationText;
    sf::Text rentWith3StationText;
    sf::Text rentWith4StationText;
    sf::Text mortgageValueText;
    sf::Text redemptionValueText;

    set_text(rentWith1StationText, font2, rentWith1Station, (int) (15 * scaleX), sf::Color::Black,
             sf::Text::Style::Regular,
             x + 20, y + (scaleY * 100 * 1.1));
    set_text(rentWith1StationText, font2, rentWith1Station, (int) (15 * scaleX), sf::Color::Black,
             sf::Text::Style::Regular,
             x + 20, y + (scaleY * 130 * 1.1));
    set_text(rentWith2StationText, font2, rentWith2Station, (int) (scaleX * 15), sf::Color::Black,
             sf::Text::Style::Regular,
             x + 20, y + (scaleY * 160 * 1.1));
    set_text(rentWith3StationText, font2, rentWith3Station, (int) (scaleX * 15), sf::Color::Black,
             sf::Text::Style::Regular,
             x + 20, y + (scaleY * 190 * 1.1));
    set_text(rentWith4StationText, font2, rentWith4Station, (int) (scaleX * 15), sf::Color::Black,
             sf::Text::Style::Regular,
             x + 20, y + (scaleY * 220 * 1.1));
    set_text(mortgageValueText, font2, mortgageValue, (int) (scaleX * 15), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (scaleY * 250 * 1.1));
    set_text(redemptionValueText, font2, redemptionValue, (int) (scaleX * 15), sf::Color::Black,
             sf::Text::Style::Regular,
             x + 20, y + (scaleY * 280 * 1.1));

    window.draw(rentWith1StationText);
    window.draw(rentWith2StationText);
    window.draw(rentWith3StationText);
    window.draw(rentWith4StationText);
    window.draw(mortgageValueText);
    window.draw(redemptionValueText);
}

void GameWindow::drawRentUtilityCard(sf::RenderWindow &window, ProfitableField *field, float x, float y, float scaleX,
                                     float scaleY) {
    sf::Sprite rentCard = sf::Sprite(cardsRentTexture[1]);
    rentCard.setPosition(x, y);
    rentCard.setScale(scaleX, 1.2f * scaleY);
    window.draw(rentCard);
    auto utility = dynamic_cast<Utility *>(field);

    std::string name = field->get_name();
    std::string utility1 = "If one \"Utility\" is owned,\nrent is 4 times amount\nshown on dice";
    std::string utility2 = "If both \"Utilities\" are\nowned, rent is 10\ntimes the amount\nshown on dice";
    std::string mortgageValue = "Mortgage value:       " + std::to_string(utility->get_mortgage_price());
    std::string redemptionValue = "Redemption value:     " + std::to_string(utility->get_redemption_price());

    sf::Text nameText;
    sf::Text utility1Text;
    sf::Text utility2Text;
    sf::Text mortgageValueText;
    sf::Text redemptionValueText;

    set_text(nameText, font2, name, (int) (scaleX * 15), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (scaleY * 100 * 1.1));
    set_text(utility1Text, font2, utility1, (int) (scaleX * 15), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (scaleY * 130 * 1.1));
    set_text(utility2Text, font2, utility2, (int) (scaleX * 15), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (scaleY * 220 * 1.1));
    set_text(mortgageValueText, font2, mortgageValue, (int) (scaleX * 15), sf::Color::Black, sf::Text::Style::Regular,
             x + 20, y + (scaleY * 300 * 1.1));
    set_text(redemptionValueText, font2, redemptionValue, (int) (scaleX * 15), sf::Color::Black,
             sf::Text::Style::Regular,
             x + 20, y + (scaleY * 330 * 1.1));

    window.draw(nameText);
    window.draw(utility1Text);
    window.draw(utility2Text);
    window.draw(mortgageValueText);
    window.draw(redemptionValueText);
}

void GameWindow::drawPlayers(sf::RenderWindow &window) {
    for (int i = 0; i < game.get_players().size(); i++) {
        if (i == game.get_cur_player_id() && isRollDice) {
            drawPlayer(window, player.new_position, i);
            continue;
        }
        drawPlayer(window, game.get_players()[i].get_position(), i);
    }
}

void GameWindow::drawPlayer(sf::RenderWindow &window, int currPosition, int i) {
    sf::Sprite sprite = game.get_players()[i].get_sprite();
    if (0 <= currPosition && currPosition <= 10) {
        if (currPosition == 0) {
            sprite.setPosition((float)(1354 + i * 30), 870);
        } else if (currPosition == 10) {
            sprite.setPosition(552, 870);
        } else {
            sprite.setPosition((float)(1384 - i * 10 - game.get_players()[i].get_position() * 85), 870);
        }
    } else if (11 <= currPosition && currPosition <= 20) {
        sprite.setOrigin(0, 76);
        sprite.setRotation(90);
        sprite.setPosition(562, (float)(963 - i * 10 - (currPosition - 10) * 85));

    } else if (21 <= currPosition && currPosition <= 30) {
        sprite.setOrigin(42, 76);
        sprite.setRotation(180);
        sprite.setPosition((float)(534 + i * 10 + (currPosition - 20) * 85), 140);
    } else {

        sprite.setOrigin(0, 76);
        sprite.setRotation(-90);
        sprite.setPosition(1357, (float)(117 + i * 10 + (currPosition - 30) * 85));
    }
    window.draw(sprite);
}

