#include "PayWindow.h"

void PayWindow::loadBuyModeWindow(sf::RenderWindow &window) {
    if (!payButtonTexture.loadFromFile("assets/sprite/Buttons/payButton.png") ||
        !font1.loadFromFile("assets/fonts/Bionicle.ttf") ||
        !font2.loadFromFile("assets/fonts/big-shot.ttf") ||
        !taxCardTexture.loadFromFile("assets/sprite/Card/FieldCard/fieldTaxCard.png") ||
        !payToPlayerCardTexture.loadFromFile("assets/sprite/Card/FieldCard/payPlayerCard.png")) {
        throw std::runtime_error("Can't load texture for GameWindow");
    }

    payButtonSprite = sf::Sprite(payButtonTexture);
    payButtonSprite.setPosition((window.getSize().x / 2.f) - 100, window.getSize().y - 150);
    payButtonSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    payButtonSprite.setScale(0.6f, 0.6f);

    taxCardSprite = sf::Sprite(taxCardTexture);

    taxCardSprite.setPosition((window.getSize().x / 2.f) - 64 * 5, (window.getSize().y / 2.f) - 128 * 4);
    taxCardSprite.setScale(5.f, 4.f);

    payToPlayerCardSprite = sf::Sprite(payToPlayerCardTexture);
    payToPlayerCardSprite.setPosition((window.getSize().x / 2.f) - 64 * 5, (window.getSize().y / 2.f) - 128 * 4);
    payToPlayerCardSprite.setScale(5.f, 4.f);

}

void PayWindow::setGame(Game &_game, GameMove& _player) {
    game = _game;
    player = _player;
}

void PayWindow::setType(int _type) {
    type = _type;
}

bool PayWindow::handleEvent(sf::Event &event, sf::RenderWindow &window) {
    auto point = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (payButtonSprite.getGlobalBounds().contains(point)) {
                return true;
            }
        }
    } else if (event.type == sf::Event::MouseMoved) {
        payButtonSprite.getGlobalBounds().contains(point)
        ? payButtonSprite.setTextureRect({360 * 2, 0, 360, 109})
        : payButtonSprite.setTextureRect({0, 0, 360, 109});
    }
    return false;
}

void PayWindow::draw(sf::RenderWindow &window, sf::Event &event) {
    if (type == 0) {
        window.draw(payToPlayerCardSprite);
        window.draw(payButtonSprite);
        sf::Sprite playerToPaySprite = game.get_players()[player.player_to_pay]->get_sprite();
        playerToPaySprite.setPosition(window.getSize().x / 2.f - 21 * 4.f, window.getSize().y / 2.f - 38 * 4.f);
        playerToPaySprite.setScale(4.f, 4.f);

        std::string amountToPay = std::to_string(player.amount_to_pay);
        sf::Text amountToPayText;
        set_text(amountToPayText, font2, amountToPay, 50, sf::Color::Black, sf::Text::Style::Regular,
                 (window.getSize().x / 2.f) - 30, 830);
        window.draw(amountToPayText);
        window.draw(playerToPaySprite);
    } else if (type == 1) {
        auto currPlayer = game.get_players()[game.get_cur_player_id()];
        auto field = dynamic_cast<Tax *>(game.get_fields()[currPlayer->get_position()]);
        std::string price = std::to_string(field->get_price());
        sf::Text priceText;
        set_text(priceText, font2, price, 50, sf::Color::Black, sf::Text::Style::Regular,
                 (window.getSize().x / 2.f) - 50, 830);
        window.draw(taxCardSprite);
        window.draw(priceText);
        window.draw(payButtonSprite);
    }
}