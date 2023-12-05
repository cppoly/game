#include "DrawCardWindow.h"

void DrawCardWindow::loadBuyModeWindow(sf::RenderWindow &window) {
    if (!okButtonTexture.loadFromFile("assets/sprite/Buttons/okButton.png") ||
        !font1.loadFromFile("assets/fonts/Bionicle.ttf") ||
        !font2.loadFromFile("assets/fonts/big-shot.ttf") ||
        !communityChestCardTexture.loadFromFile("assets/sprite/Card/FieldCard/CommunityChestCard.png") ||
        !chanceCardTexture.loadFromFile("assets/sprite/Card/FieldCard/ChanceCard.png")) {
        throw std::runtime_error("Can't load texture for GameWindow");
    }

    okButtonSprite = sf::Sprite(okButtonTexture);
    okButtonSprite.setPosition((window.getSize().x / 2.f) - 100, window.getSize().y - 150);
    okButtonSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    okButtonSprite.setScale(0.6f, 0.6f);

    chanceCardSprite = sf::Sprite(chanceCardTexture);
    chanceCardSprite.setPosition(((float) window.getSize().x / 2.f) - 64 * 5,
                                 ((float) window.getSize().y / 2.f) - 128 * 4);
    chanceCardSprite.setScale(5.f, 4.f);

    communityChestCardSprite = sf::Sprite(communityChestCardTexture);
    communityChestCardSprite.setPosition(((float) window.getSize().x / 2.f) - 64 * 5,
                                         ((float) window.getSize().y / 2.f) - 128 * 4);
    communityChestCardSprite.setScale(5.f, 4.f);

}

void DrawCardWindow::setGame(Game &_game, Card &_card) {
    game = _game;
    card = _card;
}

bool DrawCardWindow::handleEvent(sf::Event &event, sf::RenderWindow &window) {
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

void DrawCardWindow::draw(sf::RenderWindow &window, sf::Event &event) {
    auto currPlayer = game.get_players()[game.get_cur_player_id()];
    auto field = dynamic_cast<Field *>(game.get_fields()[currPlayer->get_position()]);

    if (field->get_type() == FieldTypes::CHANCE) {
        window.draw(chanceCardSprite);
        auto chanceField = dynamic_cast<Chance *>(field);
        std::string name = card.get_name();
        sf::Text nameText;
        set_text(nameText, font1, name, 50, sf::Color::Black, sf::Text::Style::Regular,
                 (window.getSize().x / 2.f) - 100, (window.getSize().y / 2.f));
        window.draw(nameText);
    } else {
        window.draw(communityChestCardSprite);
        window.draw(chanceCardSprite);
        auto chanceField = dynamic_cast<CommunityChest *>(field);
        std::string name = card.get_name();
        sf::Text nameText;
        set_text(nameText, font1, name, 50, sf::Color::Black, sf::Text::Style::Regular,
                 (window.getSize().x / 2.f) - 100, (window.getSize().y / 2.f));
        window.draw(nameText);
    }
    window.draw(okButtonSprite);

}