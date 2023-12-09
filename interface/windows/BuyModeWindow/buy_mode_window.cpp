#include "buy_mode_window.h"

void BuyModeWindow::loadBuyModeWindow(sf::RenderWindow &window) {
    if (!fieldCardTexture.loadFromFile("assets/sprite/Card/FieldCard/fieldCard.png") ||
        !font1.loadFromFile("assets/fonts/Bionicle.ttf") ||
        !font2.loadFromFile("assets/fonts/big-shot.ttf") ||
        !vanCardTexture.loadFromFile("assets/sprite/Card/FieldCard/fieldVanCard.png") ||
        !laundryCardTexture.loadFromFile("assets/sprite/Card/FieldCard/fieldLaundromatCard.png") ||
        !porsheCardTexture.loadFromFile("assets/sprite/Card/FieldCard/fieldPorsheCard.png") ||
        !bmwCardTexture.loadFromFile("assets/sprite/Card/FieldCard/fieldBMWCard.png") ||
        !teslaCardTexture.loadFromFile("assets/sprite/Card/FieldCard/fieldTeslaCard.png") ||
        !audiCardTexture.loadFromFile("assets/sprite/Card/FieldCard/fieldAudiCard.png") ||
        !buyButtonTexture.loadFromFile("assets/sprite/Buttons/buttonBuy.png") ||
        !auctionButtonTexture.loadFromFile("assets/sprite/Buttons/buttonAuction.png")) {

        throw std::runtime_error("Can't load texture for Buy page");
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


    fieldCardSprite = sf::Sprite(fieldCardTexture);
    fieldCardSprite.setPosition((window.getSize().x / 2.f) - 64 * 5, (window.getSize().y / 2.f) - 128 * 4);
    fieldCardSprite.setScale(5.f, 4.f);


    vanCardSprite = sf::Sprite(vanCardTexture);
    laundryCardSprite = sf::Sprite(laundryCardTexture);
    porsheCardSprite = sf::Sprite(porsheCardTexture);
    bmwCardSprite = sf::Sprite(bmwCardTexture);
    teslaCardSprite = sf::Sprite(teslaCardTexture);
    audiCardSprite = sf::Sprite(audiCardTexture);

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


    buyButtonSprite = sf::Sprite(buyButtonTexture);
    buyButtonSprite.setPosition((window.getSize().x / 2.f) - 270, window.getSize().y - 150);
    buyButtonSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    buyButtonSprite.setScale(0.6f, 0.6f);

    auctionButtonSprite = sf::Sprite(auctionButtonTexture);
    auctionButtonSprite.setPosition((window.getSize().x / 2.f) + 50, window.getSize().y - 150);
    auctionButtonSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    auctionButtonSprite.setScale(0.6f, 0.6f);

}

void BuyModeWindow::setGame(Game &_game) {
    game = _game;
}

int BuyModeWindow::handleEvent(sf::Event &event, sf::RenderWindow &window) {
    auto point = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (buyButtonSprite.getGlobalBounds().contains(point)) {
                return 1;
            } else if (auctionButtonSprite.getGlobalBounds().contains(point)) {
                return 2;
            }
        }
    } else if (event.type == sf::Event::MouseMoved) {
        buyButtonSprite.getGlobalBounds().contains(point)
        ? buyButtonSprite.setTextureRect(sf::IntRect(360 * 2, 0, 360, 109))
        : buyButtonSprite.setTextureRect({0, 0, 360, 109});

        auctionButtonSprite.getGlobalBounds().contains(point)
        ? auctionButtonSprite.setTextureRect({360 * 2, 0, 360, 109})
        : auctionButtonSprite.setTextureRect({0, 0, 360, 109});
    }
    return 0;
}

void BuyModeWindow::draw(sf::RenderWindow &window, sf::Event &event) {
    auto currPlayer = game.get_players()[game.get_cur_player_id()];
    auto field = dynamic_cast<ProfitableField *>(game.get_fields()[currPlayer->get_position()]);

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
        drawRentStreetCard(window, field, rentCardSprite, window.getSize().x - 50 - 300, 300, 1.f, 1.f, font2);
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

        sf::Sprite rentCardSprite = sf::Sprite(cardsRentSprite[2]);

        drawRentStationCard(window, field, rentCardSprite, window.getSize().x - 50 - 300, 300, 1.f, 1.f, font2);
    } else if (field->get_type() == FieldTypes::UTILITY) {
        if (fieldName == "Laundromat") {
            window.draw(laundryCardSprite);
        } else {
            window.draw(vanCardSprite);
        }
        sf::Sprite rentCardSprite = sf::Sprite(cardsRentSprite[1]);

        drawRentUtilityCard(window, field, rentCardSprite, window.getSize().x - 50 - 300, 300, 1.f, 1.f, font2);
    }
    window.draw(buyButtonSprite);
    window.draw(auctionButtonSprite);
    window.draw(fieldNameText);
    window.draw(priceText);
}
