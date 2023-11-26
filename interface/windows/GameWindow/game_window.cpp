#include "game_window.h"

GameWindow::GameWindow(sf::RenderWindow &window) {
    if (!backgroundImageTexture.loadFromFile("assets/sprite/BackgroundImage/playing_field.png") ||
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
        !laundryCardTexture.loadFromFile("assets/sprite/Card/FieldCard/fieldLaundromatCard.png") ||
        !porsheCardTexture.loadFromFile("assets/sprite/Card/FieldCard/fieldPorsheCard.png") ||
        !bmwCardTexture.loadFromFile("assets/sprite/Card/FieldCard/fieldBMWCard.png") ||
        !teslaCardTexture.loadFromFile("assets/sprite/Card/FieldCard/fieldTeslaCard.png") ||
        !audiCardTexture.loadFromFile("assets/sprite/Card/FieldCard/fieldAudiCard.png") ||
        !communityChestCardTexture.loadFromFile("assets/sprite/Card/FieldCard/CommunityChestCard.png") ||
        !taxCardTexture.loadFromFile("assets/sprite/Card/FieldCard/fieldTaxCard.png") ||
        !chanceCardTexture.loadFromFile("assets/sprite/Card/FieldCard/ChanceCard.png")) {
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

    myFieldsButtonSprite = sf::Sprite(myFieldsButtonTexture);
    myFieldsButtonSprite.setTextureRect({0, 0, 360, 109});
    myFieldsButtonSprite.setScale(0.8f, 0.8f);
    myFieldsButtonSprite.setPosition(50, 800);

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
    chanceCardSprite.setPosition((window.getSize().x / 2.f) - 64 * 5, (window.getSize().y / 2.f) - 128 * 4);
    chanceCardSprite.setScale(5.f, 4.f);

    communityChestCardSprite = sf::Sprite(communityChestCardTexture);
    communityChestCardSprite.setPosition((window.getSize().x / 2.f) - 64 * 5, (window.getSize().y / 2.f) - 128 * 4);
    communityChestCardSprite.setScale(5.f, 4.f);

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
    if (game.get_is_player_roll_dice()) {
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
    if (isActivePayBankMode) {
        payButtonSprite.setTextureRect({360, 0, 360, 109});
        bool pay = game.pay_bank(player.amount_to_pay);
        if (pay) {
            isActivePayBankMode = false;
        }
    }
}

void GameWindow::draw(sf::RenderWindow &window) {
    window.clear();
    window.draw(backgroundImageSprite);

    if (!isGameStarted) {
        backgroundImageSprite.setColor(sf::Color(255, 255, 255, 60));
        window.draw(startGameButtonSprite);
    } else {
        backgroundImageSprite.setColor(sf::Color(255, 255, 255, 255));

        drawPlayerInformation(window);

        if (isActiveMyFieldsMode) {
            drawMyFields(window);
        }

        // Draw player activity
        if (isActiveBuyMode) {
            drawBuyCard(window);
        } else if (isActiveDrawCardMode) {
            drawDrawCard(window);
        } else if (isActivePayBankMode) {
            drawPayBankCard(window);
        } else if (isActivePayPlayerMode) {
//            game.pay_player(player.player_to_pay, player.amount_to_pay);
        } else if (isActiveGoToJail) {
//            game.go_to_jail();
        } else {
            window.draw(completeTurnSprite);
            window.draw(rollDiceButtonSprite);
            drawPlayers(window);
            window.draw(myFieldsButtonSprite);
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
        drawRentStreetCard(window, field);
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
    } else if (field->get_type() == FieldTypes::UTILITY) {
        if (fieldName == "Laundromat") {
            window.draw(laundryCardSprite);
        } else {
            window.draw(vanCardSprite);
        }
    }

    window.draw(buyButtonSprite);
    window.draw(auctionButtonSprite);
    window.draw(fieldNameText);
    window.draw(priceText);
}

void GameWindow::drawDrawCard(sf::RenderWindow &window) {
    backgroundImageSprite.setColor(sf::Color(255, 255, 255, 60));

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

void GameWindow::drawDice(sf::RenderWindow &window) {
    dice1Sprite.setTextureRect(sf::IntRect(96 * (player.number_on_dice1 - 1), 0, 96, 96));
    dice2Sprite.setTextureRect(sf::IntRect(96 * (player.number_on_dice2 - 1), 0, 96, 96));
    window.draw(dice1Sprite);
    window.draw(dice2Sprite);

}

void GameWindow::drawMyFields(sf::RenderWindow &window) {
    auto currPlayer = game.get_players()[game.get_cur_player_id()];
    auto fields = currPlayer.get_fields();

    for (int i = 0; i < fields.size(); i++) {
        sf::Sprite field = sf::Sprite(cardsRentTexture[i]);
        field.setPosition(100 + 300 + i * 100, 400);
        window.draw(field);
    }
}

void GameWindow::drawRentStreetCard(sf::RenderWindow &window, ProfitableField *field) {
    auto street = dynamic_cast<Street *>(field);

    window.draw(cardsRentSprite[field->get_collection_type() - 1]);

    std::string rent = std::to_string(field->get_rent());
    std::string rentWith1House = "Rent with 1 house:   " + std::to_string(field->get_rent_vector()[0]);
    std::string rentWith2House = "Rent with 2 houses:  " + std::to_string(field->get_rent_vector()[1]);
    std::string rentWith3House = "Rent with 3 houses:  " + std::to_string(field->get_rent_vector()[2]);
    std::string rentWith4House = "Rent with 4 houses:  " + std::to_string(field->get_rent_vector()[3]);
    std::string rentWith1Hotel = "Rent with 1 hotel:   " + std::to_string(field->get_rent_vector()[4]);
    std::string rentWith2Hotel = "Rent with 2 hotels:  " + std::to_string(field->get_rent_vector()[5]);
    std::string mortgageValue = "Mortgage value:       " + std::to_string(field->get_mortgage_price());
    std::string redemptionValue = "Redemption value:     " + std::to_string(field->get_redemption_price());

    std::string price1House = std::to_string(street->get_house_price());
    std::string price1Hotel = std::to_string(street->get_hotel_price());


    sf::Text rentText;
    sf::Text rentWith1HouseText;
    sf::Text rentWith2HouseText;
    sf::Text rentWith3HouseText;
    sf::Text rentWith4HouseText;
    sf::Text rentWith1HotelText;
    sf::Text rentWith2HotelText;
    sf::Text mortgageValueText;
    sf::Text redemptionValueText;
    sf::Text price1HouseText;
    sf::Text price1HotelText;

    set_text(rentText, font1, rent, 50, sf::Color::Black, sf::Text::Style::Regular,
             window.getSize().x - 160, 320);

    set_text(rentWith1HouseText, font2, rentWith1House, 15, sf::Color::Black, sf::Text::Style::Regular,
             window.getSize().x - 330, 400);
    set_text(rentWith2HouseText, font2, rentWith2House, 15, sf::Color::Black, sf::Text::Style::Regular,
             window.getSize().x - 330, 430);
    set_text(rentWith3HouseText, font2, rentWith3House, 15, sf::Color::Black, sf::Text::Style::Regular,
             window.getSize().x - 330, 460);
    set_text(rentWith4HouseText, font2, rentWith4House, 15, sf::Color::Black, sf::Text::Style::Regular,
             window.getSize().x - 330, 490);
    set_text(rentWith1HotelText, font2, rentWith1Hotel, 15, sf::Color::Black, sf::Text::Style::Regular,
             window.getSize().x - 330, 520);
    set_text(rentWith2HotelText, font2, rentWith2Hotel, 15, sf::Color::Black, sf::Text::Style::Regular,
             window.getSize().x - 330, 550);
    set_text(mortgageValueText, font2, mortgageValue, 15, sf::Color::Black, sf::Text::Style::Regular,
             window.getSize().x - 330, 580);
    set_text(redemptionValueText, font2, redemptionValue, 15, sf::Color::Black, sf::Text::Style::Regular,
             window.getSize().x - 330, 610);
    set_text(price1HouseText, font2, price1House, 25, sf::Color::Black, sf::Text::Style::Regular,
             window.getSize().x - 250, 650);
    set_text(price1HotelText, font2, price1Hotel, 25, sf::Color::Black, sf::Text::Style::Regular,
             window.getSize().x - 250, 700);

    window.draw(rentText);
    window.draw(rentWith1HouseText);
    window.draw(rentWith2HouseText);
    window.draw(rentWith3HouseText);
    window.draw(rentWith4HouseText);
    window.draw(rentWith1HotelText);
    window.draw(rentWith2HotelText);
    window.draw(mortgageValueText);
    window.draw(redemptionValueText);
    window.draw(price1HouseText);
    window.draw(price1HotelText);

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
            sprite.setPosition(1354 + i * 30, 870);
        } else if (currPosition == 10) {
            sprite.setPosition(552, 870);
        } else {
            sprite.setPosition(1384 - i * 10 - game.get_players()[i].get_position() * 85, 870);
        }
    } else if (11 <= currPosition && currPosition <= 20) {
        sprite.setOrigin(0, 76);
        sprite.setRotation(90);
        sprite.setPosition(562, 963 - i * 10 - (currPosition - 10) * 85);

    } else if (21 <= currPosition && currPosition <= 30) {
        sprite.setOrigin(42, 76);
        sprite.setRotation(180);
        sprite.setPosition(534 + i * 10 + (currPosition - 20) * 85, 140);
    } else {

        sprite.setOrigin(0, 76);
        sprite.setRotation(-90);
        sprite.setPosition(1357, 117 + i * 10 + (currPosition - 30) * 85);
    }
    window.draw(sprite);
}

