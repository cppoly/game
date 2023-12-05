#include "MyFieldsWindow.h"

void MyFieldsWindow::loadBuyModeWindow(sf::RenderWindow &window) {
    if (!okButtonTexture.loadFromFile("assets/sprite/Buttons/okButton.png") ||
        !font1.loadFromFile("assets/fonts/Bionicle.ttf") ||
        !font2.loadFromFile("assets/fonts/big-shot.ttf") ||
        !myFieldsCardTexture.loadFromFile("assets/sprite/Card/FieldCard/myFieldsCard.png")) {
        throw std::runtime_error("Can't load texture for GameWindow");
    }

    for (int i = 0; i < cardsRentTexture.size(); i++) {
        if (!cardsRentTexture[i].loadFromFile(
                "assets/sprite/Card/RentCard/rent" + std::to_string(i + 1) + "Card.png")) {
            throw std::runtime_error("Can't load texture of rent card");
        }
        cardsRentSprite[i] = sf::Sprite(cardsRentTexture[i]);
        cardsRentSprite[i].setPosition(window.getSize().x - 50 - 300, 300);
        cardsRentSprite[i].setScale(1, 1.2f);
    }

    okButtonSprite = sf::Sprite(okButtonTexture);
    okButtonSprite.setPosition((window.getSize().x / 2.f) - 100, window.getSize().y - 150);
    okButtonSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    okButtonSprite.setScale(0.6f, 0.6f);

    myFieldsCardSprite = sf::Sprite(myFieldsCardTexture);
    myFieldsCardSprite.setPosition(((float) window.getSize().x / 2.f) - (300 * 2.5f),
                                   ((float) window.getSize().y / 2.f) - (200 * 2.5f));
    myFieldsCardSprite.setScale(2.5f, 2.5f);

}

void MyFieldsWindow::setGame(Game &_game) {
    game = _game;
}

bool MyFieldsWindow::handleEvent(sf::Event &event, sf::RenderWindow &window) {
    auto point = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (okButtonSprite.getGlobalBounds().contains(point)) {
                return true;
            }
        }
    } else if (event.type == sf::Event::MouseMoved) {
        okButtonSprite.getGlobalBounds().contains(point)
        ? okButtonSprite.setTextureRect({360 * 2, 0, 360, 109})
        : okButtonSprite.setTextureRect({0, 0, 360, 109});
    }
    return false;
}

void MyFieldsWindow::draw(sf::RenderWindow &window, sf::Event &event) {
    myFieldsCardSprite.setColor({255, 255, 255, 255});
    window.draw(myFieldsCardSprite);
    window.draw(okButtonSprite);

    auto fields = game.get_players()[game.get_cur_player_id()]->get_fields();

    for (int i = 0; i < fields.size(); i++) {
        if (fields[i]->get_type() == FieldTypes::STREET) {
            auto rentCardSprite = new sf::Sprite(cardsRentTexture[fields[i]->get_collection_type() - 1]);
            drawRentStreetCard(window, fields[i], cardsRentSprite[fields[i]->get_collection_type() - 1],
                               (float) (200 + 300 * 0.7 * i + 100), 100.f + 450.f * (i / 6), 0.5f,
                               0.5f, font2);
        } else if (fields[i]->get_type() == FieldTypes::STATION) {
            auto rentCardSprite = new sf::Sprite(cardsRentSprite[2]);
            drawRentStationCard(window, fields[i], *rentCardSprite, 200 + 300 * 0.7 * i + 100, 100 + 450 * (i / 6), 0.5f, 0.5f, font2);
        } else {
            auto rentCardSprite = new sf::Sprite(cardsRentSprite[1]);
            drawRentUtilityCard(window, fields[i], *rentCardSprite, 200 + 300 * 0.7 * i + 100, 100 + 450 * (i / 6), 0.5f, 0.5f, font2);
        }
    }
}

