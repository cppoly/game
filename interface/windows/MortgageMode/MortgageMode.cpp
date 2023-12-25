#include "MortgageMode.h"

void MortgageMode::loadBuyModeWindow(sf::RenderWindow &window) {
    if (!mortgageCardTexture.loadFromFile("assets/sprite/Card/FieldCard/mortgagePropertyCard.png")) {
        throw std::runtime_error("Can't load texture for mortgage mode");
    }


}

bool MortgageMode::handleEvent(sf::Event &event, sf::RenderWindow &window) {

}

void MortgageMode::draw(sf::RenderWindow &window, sf::Event &event) {

}

void MortgageMode::setGame(Game &_game, GameMove &_player) {

}
