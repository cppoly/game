#include "main_window.h"

void MainWindow::loadMainWindow(sf::RenderWindow &window) {
    if (!mainScreenTexture.loadFromFile("assets/sprite/BackgroundImage/Main.png") ||
        !buttonExitTexture.loadFromFile("assets/sprite/Buttons/buttonExit.png")) {
        throw std::runtime_error("Can't load main screen texture");
    }

    mainScreenSprite = sf::Sprite(mainScreenTexture);

    mainScreenSprite.setScale(window.getSize().x / mainScreenSprite.getLocalBounds().width,
                              window.getSize().y / mainScreenSprite.getLocalBounds().height);
    if (!buttonStartGameTexture.loadFromFile("assets/sprite/Buttons/buttonStartGame.png")) {
        throw std::runtime_error("Can't load button start game texture");
    }

    buttonStartGameSprite = sf::Sprite(buttonStartGameTexture);
    buttonStartGameSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    buttonStartGameSprite.setPosition((window.getSize().x / 2.f) - 180, (window.getSize().y / 2.f));

    buttonExitSprite = sf::Sprite(buttonExitTexture);
    buttonExitSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    buttonExitSprite.setPosition((window.getSize().x / 2.f) - 180, (window.getSize().y / 2.f) + 150);

}

void MainWindow::draw(sf::RenderWindow &window) {
    window.clear();
    window.draw(mainScreenSprite);
    window.draw(buttonStartGameSprite);
    window.draw(buttonExitSprite);
}

int MainWindow::handleEvent(sf::Event &event, sf::RenderWindow &window) {
    auto point = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (buttonStartGameSprite.getGlobalBounds().contains(point)) {
                buttonStartGameSprite.setTextureRect(sf::IntRect(360 * 1, 0, 360, 109));
                return 1;
            }
            if (buttonExitSprite.getGlobalBounds().contains(point)) {
                return 2;
            }
        }
    } else if (event.type == sf::Event::MouseMoved) {
        buttonStartGameSprite.getGlobalBounds().contains(point)
        ? buttonStartGameSprite.setTextureRect(sf::IntRect(360 * 2, 0, 360, 109))
        : buttonStartGameSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));

        buttonExitSprite.getGlobalBounds().contains(point)
        ? buttonExitSprite.setTextureRect(sf::IntRect(360 * 2, 0, 360, 109))
        : buttonExitSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    }
    return 0;
}