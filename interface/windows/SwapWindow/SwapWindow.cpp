#include "SwapWindow.h"

void SwapWindow::loadBuyModeWindow(sf::RenderWindow &window) {
    if (!choosePlayerCardTexture.loadFromFile("assets/sprite/Card/FieldCard/choosePlayerCard.png") ||
        !swapCardTexture.loadFromFile("assets/sprite/Card/FieldCard/swapCard.png") ||
        !buttonChoosePlayerTexture.loadFromFile("assets/sprite/Buttons/buttonChoosePlayer.png")) {
        throw std::runtime_error("Can't load sprite for SwapWindow");
    }

    choosePlayerCardSprite = sf::Sprite(choosePlayerCardTexture);
    choosePlayerCardSprite.setPosition((window.getSize().x / 2.f) - 64 * 5, (window.getSize().y / 2.f) - 128 * 4);
    choosePlayerCardSprite.setScale(5.f, 4.f);

    swapCardSprite = sf::Sprite(swapCardTexture);
    swapCardSprite.setPosition((window.getSize().x / 2.f) - 64 * 5, (window.getSize().y / 2.f) - 128 * 4);
    swapCardSprite.setScale(5.f, 4.f);

    buttonChoosePlayerSprite = sf::Sprite(buttonChoosePlayerTexture);
    buttonChoosePlayerSprite.setPosition((window.getSize().x / 2.f) - 100, window.getSize().y - 150);
    buttonChoosePlayerSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    buttonChoosePlayerSprite.setScale(0.6f, 0.6f);

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
                return true;
            }
        }
        for (int i = 0; i < playersSprite.size(); i++) {
            if (playersSprite[i].getGlobalBounds().contains(point)) {
                isActiveLarge
            }
        }
    } else if (event.type == sf::Event::MouseMoved) {
        buttonChoosePlayerSprite.getGlobalBounds().contains(point)
        ? buttonChoosePlayerSprite.setTextureRect({360 * 2, 0, 360, 109})
        : buttonChoosePlayerSprite.setTextureRect({0, 0, 360, 109});
    }
    return false;
}

void SwapWindow::draw(sf::RenderWindow &window, sf::Event &event) {
    window.draw(choosePlayerCardSprite);
    window.draw(buttonChoosePlayerSprite);

    for (int i = 0; i < playersSprite.size(); i++) {
        if (i != game.get_cur_player_id()) {
            sf::Sprite s = sf::Sprite(game.get_players()[i]->get_sprite());
            s.setPosition(
                    (window.getSize().x / 2.f) - 42 / 2.f -250 + 71 * i,
                    window.getSize().y - 290);
            window.draw(s);
        }
    }
}