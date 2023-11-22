#include "character_window.h"

void set_text(sf::Text &text, sf::Font &font, std::string &str, int size, sf::Color color,
              sf::Text::Style style, float x, float y) {
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setStyle(style);
    text.setPosition(x, y);
}

CharacterWindow::CharacterWindow(sf::RenderWindow &window) {

    playersTexture = std::vector<sf::Texture>{player1Texture, player2Texture, player3Texture,
                                              player4Texture, player5Texture, player6Texture};

    playersSprite = std::vector<sf::Sprite>{player1Sprite, player2Sprite, player3Sprite,
                                            player4Sprite, player5Sprite, player6Sprite};


    for (int i = 0; i < 6; i++) {
        if (!playersTexture[i].loadFromFile("assets/sprite/Player" + std::to_string(i+1) + ".png")) {
            throw std::runtime_error("Can't load players texture");
        }
    }

    if (!backgroundTexture.loadFromFile("assets/sprite/Settings.png") ||
        !buttonAddPlayerTexture.loadFromFile("assets/sprite/buttonAddPlayer.png") ||
        !buttonStartGameTexture.loadFromFile("assets/sprite/buttonStartGame.png") ||
        !chosePlayerTexture.loadFromFile("assets/sprite/ChosePlayerCard.png") ||
        !font1.loadFromFile("assets/fonts/Bionicle.ttf")) {
        throw std::runtime_error("Can't load texture in Character Window");
    }


    set_text(titleChoseCharacterPage, font1, title, 90, sf::Color::White, sf::Text::Bold,
             (window.getSize().x / 2.f) - 350,
             100);
    backgroundSprite.setTexture(backgroundTexture);

    buttonAddPlayerSprite = sf::Sprite(buttonAddPlayerTexture);
    buttonAddPlayerSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    buttonAddPlayerSprite.setPosition(300, 950);

    buttonStartGameSprite = sf::Sprite(buttonStartGameTexture);
    buttonStartGameSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    buttonStartGameSprite.setPosition(window.getSize().x - 660, 950);

    chosePlayerSprite.setTexture(chosePlayerTexture);
    chosePlayerSprite.setPosition((window.getSize().x / 2.f) - 250, 200);

    for (int i = 0; i < playersSprite.size(); i++) {
        playersSprite[i].setTexture(playersTexture[i]);
        playersSprite[i].setPosition(760 + 71 * i, 750);
    }

    activePlayerSprite.setPosition(100, 100);
}

void CharacterWindow::draw(sf::RenderWindow &window) {
    window.clear();
    window.draw(backgroundSprite);
    window.draw(buttonAddPlayerSprite);
    window.draw(buttonStartGameSprite);
    window.draw(chosePlayerSprite);
    window.draw(titleChoseCharacterPage);
    for (int i = 0; i < 6; i++) {
        window.draw(playersSprite[i]);
    }
    window.draw(activePlayerSprite);
}

bool CharacterWindow::handleEvent(sf::Event &event, sf::RenderWindow &window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (buttonStartGameSprite.getGlobalBounds().contains(
                    window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                buttonStartGameSprite.setTextureRect(sf::IntRect(360 * 1, 0, 360, 109));
            } else if (buttonAddPlayerSprite.getGlobalBounds().contains(
                    window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                buttonAddPlayerSprite.setTextureRect(sf::IntRect(360, 0, 360, 109));
            } else {
                for (int i = 0; i < 6; i++) {
                    if (playersSprite[i].getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                        activePlayerSprite.setTexture(playersTexture[i]);

                    }
                }
            }
        }

    } else if (event.type == sf::Event::MouseMoved) {
        if (buttonStartGameSprite.getGlobalBounds().contains(
                window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            buttonStartGameSprite.setTextureRect(sf::IntRect(360 * 2, 0, 360, 109));
        } else if (buttonAddPlayerSprite.getGlobalBounds().contains(
                window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            buttonAddPlayerSprite.setTextureRect(sf::IntRect(360 * 2, 0, 360, 109));
        } else {
            buttonAddPlayerSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
            buttonStartGameSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
        }
    } else {
        buttonStartGameSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
        buttonAddPlayerSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    }
    return false;

}

