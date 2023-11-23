#include "main_window.h"

MainWindow::MainWindow(sf::RenderWindow &window) {
    if (!mainScreenTexture.loadFromFile("assets/sprite/BackgroundImage/Main.png", sf::IntRect(0, 0, window.getSize().x, window.getSize().y))) {
        throw std::runtime_error("Can't load main screen texture");
    }

    mainScreenSprite = sf::Sprite(mainScreenTexture);

    if (!buttonStartGameTexture.loadFromFile("assets/sprite/Buttons/buttonStartGame.png")) {
        throw std::runtime_error("Can't load button start game texture");
    }

    buttonStartGameSprite = sf::Sprite(buttonStartGameTexture);
    buttonStartGameSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    buttonStartGameSprite.setPosition((window.getSize().x / 2.f) - 180, (window.getSize().y / 2.f));

}

void MainWindow::draw(sf::RenderWindow &window) {
    window.clear();
    window.draw(mainScreenSprite);
    window.draw(buttonStartGameSprite);
}

bool MainWindow::handleEvent(sf::Event &event, sf::RenderWindow &window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (buttonStartGameSprite.getGlobalBounds().contains(
                    window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                buttonStartGameSprite.setTextureRect(sf::IntRect(360 * 1, 0, 360, 109));
                return true;
            }
        }
    } else if (event.type == sf::Event::MouseMoved) {
        if (buttonStartGameSprite.getGlobalBounds().contains(
                window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            buttonStartGameSprite.setTextureRect(sf::IntRect(360 * 2, 0, 360, 109));
        } else {
            buttonStartGameSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
        }
    } else {
        buttonStartGameSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    }
    return false;
}