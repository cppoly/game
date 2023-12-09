#include "AuctionWindow.h"


void AuctionWindow::loadBuyModeWindow(sf::RenderWindow &window) {
    if (!auctionCardTexture.loadFromFile("assets/sprite/Card/FieldCard/auctionCard.png") ||
        !okButtonTexture.loadFromFile("assets/sprite/Buttons/okButton.png") ||
        !font1.loadFromFile("assets/fonts/Bionicle.ttf") ||
        !font2.loadFromFile("assets/fonts/big-shot.ttf")) {
        throw std::runtime_error("Can't load texture to AuctionWindow");
    }

    auctionCardSprite = sf::Sprite(auctionCardTexture);
    auctionCardSprite.setPosition(((float) window.getSize().x / 2.f) - (300 * 2.5f),
                                  ((float) window.getSize().y / 2.f) - (200 * 2.5f));
    auctionCardSprite.setScale(2.5f, 2.5f);

    okButtonSprite = sf::Sprite(okButtonTexture);
    okButtonSprite.setPosition((window.getSize().x / 2.f) - 100, window.getSize().y - 130);
    okButtonSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    okButtonSprite.setScale(0.6f, 0.6f);


}

void AuctionWindow::setGame(Game &_game) {
    game = _game;
}

bool AuctionWindow::handleEvent(sf::Event &event, sf::RenderWindow &window) {
    auto point = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (okButtonSprite.getGlobalBounds().contains(point)) {
                int max = 0;
                for (int i = 0; i < inputs.size(); i++) {
                    int price = std::string(inputs[i].getInput()).size() != 0 ? std::stoi(std::string(inputs[i].getInput()))
                                                                         : std::stoi("0");
                    if (price > max) {
                        max = price;
                    }
                }
                return true;
            }
        }
    } else if (event.type == sf::Event::MouseMoved) {
        okButtonSprite.getGlobalBounds().contains(point)
        ? okButtonSprite.setTextureRect({360 * 2, 0, 360, 109})
        : okButtonSprite.setTextureRect({0, 0, 360, 109});
    }
    for (int i = 0; i < game.get_players().size(); i++) {
        inputs[i].handleEvent(event);
    }
    return false;
}

void AuctionWindow::draw(sf::RenderWindow &window, sf::Event &event) {
    window.draw(auctionCardSprite);
    window.draw(okButtonSprite);
    for (int i = 0; i < game.get_players().size(); i++) {
        sf::Text nameText;
        std::string name = game.get_players()[i]->get_name();
        set_text(nameText, font2, name, 30, sf::Color::Black, sf::Text::Style::Regular, 500 + (i % 3) * 370, 300 + (i / 3) * 350);
        window.draw(nameText);

        sf::Sprite player = sf::Sprite(game.get_players()[i]->get_sprite());
        player.setPosition(530 + (i % 3) * 370, 350 + (i / 3) * 350);
        player.setScale(2.5, 2.5);
        window.draw(player);

        inputs[i].setPosition(500 + (i % 3) * 370, 550 + (i / 3) * 350);
        inputs[i].setSize(200, 30);
        inputs[i].draw(window);

        prices[i].setText(inputs[i].getInput());

    }
}