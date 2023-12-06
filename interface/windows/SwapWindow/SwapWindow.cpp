#include "SwapWindow.h"

void SwapWindow::loadBuyModeWindow(sf::RenderWindow &window) {
    if (!choosePlayerCardTexture.loadFromFile("assets/sprite/Card/FieldCard/choosePlayerCard.png") ||
        !swapCardTexture.loadFromFile("assets/sprite/Card/FieldCard/swapCard.png") ||
        !buttonChoosePlayerTexture.loadFromFile("assets/sprite/Buttons/buttonChoosePlayer.png") ||
        !buttonCancelTexture.loadFromFile("assets/sprite/Buttons/buttonCancel.png") ||
        !font1.loadFromFile("assets/fonts/Bionicle.ttf") ||
        !buttonSwapTexture.loadFromFile("assets/sprite/Buttons/buttonSwap.png") ||
        !font2.loadFromFile("assets/fonts/big-shot.ttf")) {
        throw std::runtime_error("Can't load sprite for SwapWindow");
    }

    choosePlayerCardSprite = sf::Sprite(choosePlayerCardTexture);
    choosePlayerCardSprite.setPosition((window.getSize().x / 2.f) - 64 * 5, (window.getSize().y / 2.f) - 128 * 4);
    choosePlayerCardSprite.setScale(5.f, 4.f);

    swapCardSprite = sf::Sprite(swapCardTexture);
    swapCardSprite.setPosition((window.getSize().x / 2.f) - 80 * 5, (window.getSize().y / 2.f) - 128 * 4);
    swapCardSprite.setScale(5.f, 4.f);

    buttonChoosePlayerSprite = sf::Sprite(buttonChoosePlayerTexture);
    buttonChoosePlayerSprite.setPosition((window.getSize().x / 2.f) - 270, window.getSize().y - 150);
    buttonChoosePlayerSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    buttonChoosePlayerSprite.setScale(0.6f, 0.6f);

    buttonSwapSprite = sf::Sprite(buttonSwapTexture);
    buttonSwapSprite.setPosition((window.getSize().x / 2.f) - 270, window.getSize().y - 150);
    buttonSwapSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    buttonSwapSprite.setScale(0.6f, 0.6f);

    buttonCancelSprite = sf::Sprite(buttonCancelTexture);
    buttonCancelSprite.setPosition((window.getSize().x / 2.f) + 50, window.getSize().y - 150);
    buttonCancelSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    buttonCancelSprite.setScale(0.6f, 0.6f);

}

void SwapWindow::setGame(Game &_game) {
    game = _game;
    playersSprite.clear();
    for (int i = 0; i < game.get_players().size(); i++) {
        playersSprite.push_back(game.get_players()[i]->get_sprite());
    }
}

bool SwapWindow::handleEvent(sf::Event &event, sf::RenderWindow &window) {
    auto point = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (buttonChoosePlayerSprite.getGlobalBounds().contains(point)) {
                isActiveTradeMode = true;
            }
            if (buttonCancelSprite.getGlobalBounds().contains(point)) {
                isActiveLargeMode = false;
                isActiveTradeMode = false;
                return true;
            }
            for (int i = 0; i < playersSprite.size(); i++) {
                if (playersSprite[i].getGlobalBounds().contains(point)) {
                    isActiveLargeMode = true;
                    indexPlayer = i;
                    player2 = game.get_players()[i];
                    currPlayer = game.get_players()[game.get_cur_player_id()];
                }
            }
        }
    } else if (event.type == sf::Event::MouseMoved) {
        buttonChoosePlayerSprite.getGlobalBounds().contains(point)
        ? buttonChoosePlayerSprite.setTextureRect({360 * 2, 0, 360, 109})
        : buttonChoosePlayerSprite.setTextureRect({0, 0, 360, 109});

        buttonSwapSprite.getGlobalBounds().contains(point)
        ? buttonSwapSprite.setTextureRect({360 * 2, 0, 360, 109})
        : buttonSwapSprite.setTextureRect({0, 0, 360, 109});

        buttonCancelSprite.getGlobalBounds().contains(point)
        ? buttonCancelSprite.setTextureRect({360 * 2, 0, 360, 109})
        : buttonCancelSprite.setTextureRect({0, 0, 360, 109});

    }
    return false;
}

void SwapWindow::draw(sf::RenderWindow &window, sf::Event &event) {
    if (isActiveTradeMode) {
        window.draw(swapCardSprite);
        window.draw(buttonSwapSprite);
        //Players

        sf::Sprite player1Sprite = currPlayer->get_sprite();
        sf::Sprite player2Sprite = player2->get_sprite();
        player1Sprite.setOrigin(42, 0);
        player1Sprite.setPosition(window.getSize().x / 2.f - 100, 400);
        player2Sprite.setPosition(window.getSize().x / 2.f + 100, 400);
        player1Sprite.setScale(4, 4);
        player2Sprite.setScale(4, 4);
        window.draw(player1Sprite);
        window.draw(player2Sprite);

        // Player's names

        sf::Text name1Text;
        sf::Text name2Text;
        std::string name1 = currPlayer->get_name();
        std::string name2 = player2->get_name();

        set_text(name1Text, font2, name1, 45, sf::Color::Black, sf::Text::Style::Regular,
                 (window.getSize().x / 2.f) - 130, 330);

        set_text(name2Text, font2, name2, 45, sf::Color::Black, sf::Text::Style::Regular,
                 (window.getSize().x / 2.f) - 130, 330);

        name1Text.setPosition(window.getSize().x / 2.f - 70 - name1Text.getGlobalBounds().width,330);
        name2Text.setPosition(window.getSize().x / 2.f + 100,330);
        window.draw(name1Text);
        window.draw(name2Text);
    } else {
        window.draw(choosePlayerCardSprite);
        window.draw(buttonChoosePlayerSprite);

        bool isIndexCurrPlayer = false;

        for (int i = 0; i < game.get_players().size(); i++) {
            if (i == game.get_cur_player_id()) {
                isIndexCurrPlayer = true;

            } else {
                if (isIndexCurrPlayer) {
                    playersSprite[i].setPosition(
                            (window.getSize().x / 2.f) - 47 / 2.f - 150 + 80 * (i - 1),
                            window.getSize().y - 250);
                    window.draw(playersSprite[i]);
                } else {
                    playersSprite[i].setPosition(
                            (window.getSize().x / 2.f) - 47 / 2.f - 150 + 80 * i,
                            window.getSize().y - 250);
                    window.draw(playersSprite[i]);
                }
            }
        }
        if (isActiveLargeMode) {
            sf::Sprite s = playersSprite[indexPlayer];
            s.setScale(4.f, 4.f);
            s.setPosition(window.getSize().x / 2.f - (47 / 2) * 4, window.getSize().y / 2.f - (76 / 2) * 4 + 50);
            window.draw(s);
            std::string name = game.get_players()[indexPlayer]->get_name();
            sf::Text nameText;
            set_text(nameText, font2, name, 60, sf::Color::Black, sf::Text::Style::Regular,
                     (window.getSize().x / 2.f) - 130, 330);
            window.draw(nameText);
        }
    }
    window.draw(buttonCancelSprite);

}