#include "character_window.h"
#include <algorithm>
#include "../../text/text.h"

void CharacterWindow::loadCharacterWindow(sf::RenderWindow &window) {
    addedPlayersSprite.clear();
    players.clear();
    disabledPlayersIndex.clear();
    addedPlayersSprite.clear();
    playersCount = 0;
    isActiveSelectCharacterMode = false;
    indexActivePlayer = 0;

    playersTexture = std::vector<sf::Texture>{player1Texture, player2Texture, player3Texture,
                                              player4Texture, player5Texture, player6Texture};

    playersSprite = std::vector<sf::Sprite>{player1Sprite, player2Sprite, player3Sprite,
                                            player4Sprite, player5Sprite, player6Sprite};

    playersDisableTexture = std::vector<sf::Texture>{player1DisableTexture, player2DisableTexture,
                                                     player3DisableTexture,
                                                     player4DisableTexture, player5DisableTexture,
                                                     player6DisableTexture};

    playersMediumTexture = std::vector<sf::Texture>{player1MediumTexture, player2MediumTexture, player3MediumTexture,
                                                    player4MediumTexture, player5MediumTexture, player6MediumTexture};

    playersMediumSprite = std::vector<sf::Sprite>{player1MediumSprite, player2MediumSprite, player3MediumSprite,
                                                  player4MediumSprite, player5MediumSprite, player6MediumSprite};

    for (int i = 0; i < 6; i++) {
        if (!playersTexture[i].loadFromFile("assets/sprite/Players/Player" + std::to_string(i + 1) + ".png") ||
            !playersMediumTexture[i].loadFromFile(
                    "assets/sprite/MediumPlayer/Player" + std::to_string(i + 1) + ".png") ||
            !playersDisableTexture[i].loadFromFile(
                    "assets/sprite/DisactivePlayer/Player" + std::to_string(i + 1) + ".png")) {
            throw std::runtime_error("Can't load players texture");
        }
    }


    if (!backgroundTexture.loadFromFile("assets/sprite/BackgroundImage/Settings.png") ||
        !buttonAddPlayerTexture.loadFromFile("assets/sprite/Buttons/buttonAddPlayer.png") ||
        !buttonStartGameTexture.loadFromFile("assets/sprite/Buttons/buttonStartGame.png") ||
        !chosePlayerTexture.loadFromFile("assets/sprite/Card/ChosePlayerCard.png") ||
        !font1.loadFromFile("assets/fonts/Bionicle.ttf") ||
        !font2.loadFromFile("assets/fonts/Minecraft.otf") ||
        !playersLargeTexture.loadFromFile("assets/sprite/LargePlayer/Players.png")) {
        throw std::runtime_error("Can't load texture in Character Window");
    }


    set_text(titleChoseCharacterPage, font1, title, 90, sf::Color::White, sf::Text::Bold,
             (window.getSize().x / 2.f) - 350,
             100);
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(window.getSize().x / backgroundSprite.getLocalBounds().getSize().x,
                              window.getSize().y / backgroundSprite.getLocalBounds().getSize().y);

    buttonAddPlayerSprite = sf::Sprite(buttonAddPlayerTexture);
    buttonAddPlayerSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    buttonAddPlayerSprite.setPosition(
            (window.getSize().x / 2.f) - 450 - buttonAddPlayerSprite.getLocalBounds().getSize().x,
            window.getSize().y - 30 - buttonAddPlayerSprite.getLocalBounds().getSize().y);

    buttonStartGameSprite = sf::Sprite(buttonStartGameTexture);
    buttonStartGameSprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    buttonStartGameSprite.setPosition((window.getSize().x / 2.f) + 450,
                                      window.getSize().y - 30 - buttonAddPlayerSprite.getLocalBounds().getSize().y);

    chosePlayerSprite.setTexture(chosePlayerTexture);
    chosePlayerSprite.setPosition((window.getSize().x / 2.f) - 250,
                                  window.getSize().y - chosePlayerSprite.getLocalBounds().getSize().y - 150);

    for (int i = 0; i < playersSprite.size(); i++) {
        playersSprite[i].setTexture(playersTexture[i]);
        playersSprite[i].setPosition(
                (window.getSize().x / 2.f) - chosePlayerSprite.getLocalBounds().width / 2.f + 50 + 71 * i,
                window.getSize().y - 290);
        playersMediumSprite[i].setTexture(playersMediumTexture[i]);

    }

    player6MediumSprite = sf::Sprite(player6MediumTexture);
    player6MediumSprite.setPosition(300, 400);

    playersLargeSprite = sf::Sprite(playersLargeTexture);
    playersLargeSprite.setTextureRect(sf::IntRect(0, 0, 350, 400));

    // Input

    input.setPosition((window.getSize().x / 2.f) - 150, 360);
    input.setSize(300, 40);
    input.setBorder(2);
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
    if (isActiveSelectCharacterMode) {
        window.draw(activePlayerSprite);
    }

    for (int i = 0; i < addedPlayersSprite.size(); i++) {
        window.draw(addedPlayersSprite[i]);
        window.draw(addedPlayerNameText[i]);
    }

    input.draw(window);
    name.setText(input.getInput());
}

bool CharacterWindow::handleEvent(sf::Event &event, sf::RenderWindow &window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (buttonStartGameSprite.getGlobalBounds().contains(
                    window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                return onStartGame();
            } else if (buttonAddPlayerSprite.getGlobalBounds().contains(
                    window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                onAddPlayer(window);

            } else {
                onChooseCharacter(window);
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
    input.handleEvent(event);
    return false;
}


bool CharacterWindow::onStartGame() {
    buttonStartGameSprite.setTextureRect(sf::IntRect(360 * 1, 0, 360, 109));
    if (playersCount >= 2) {
        for (int i = 0; i < addedPlayersSprite.size(); i++) {
            game.add_player(players[i], std::string(addedPlayerNameText[i].getString()));
        }
        return true;
    }
    return false;
}

void CharacterWindow::onAddPlayer(sf::RenderWindow &window) {
    if (isActiveSelectCharacterMode) {
        buttonAddPlayerSprite.setTextureRect(sf::IntRect(360, 0, 360, 109));
        sf::Text namePlayer = std::string(input.getInput()).size() != 0 ? sf::Text(input.getInput(), font2, 25)
                                                          : sf::Text(
                        sf::String("Player" + std::to_string(addedPlayersSprite.size() + 1)), font2, 25);
        namePlayer.setFillColor(sf::Color::Black);
        if (playersCount % 2 == 0) {
            playersMediumSprite[indexActivePlayer].setPosition(260, 250 + playersCount * 120);
            namePlayer.setPosition(270, 250 + playersCount * 120);
        } else {
            playersMediumSprite[indexActivePlayer].setPosition(window.getSize().x - 260 - 175,
                                                               250 + (playersCount - 1) * 120);
            namePlayer.setPosition(window.getSize().x - 270 - 153, 250 + (playersCount - 1) * 120);
        }
        addedPlayersSprite.push_back(playersMediumSprite[indexActivePlayer]);
        players.push_back(playersSprite[indexActivePlayer]);

        playersSprite[indexActivePlayer].setTexture(playersDisableTexture[indexActivePlayer]);

        addedPlayerNameText.push_back(namePlayer);

        isActiveSelectCharacterMode = false;
        playersCount++;
        disabledPlayersIndex.push_back(indexActivePlayer);
        input.clear();
    }
}

void CharacterWindow::onChooseCharacter(sf::RenderWindow &window) {
    for (int i = 0; i < 6; i++) {
        if (playersSprite[i].getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            if (std::find(disabledPlayersIndex.begin(), disabledPlayersIndex.end(), i) ==
                std::end(disabledPlayersIndex)) {
                activePlayerSprite = sf::Sprite(playersLargeTexture);
                activePlayerSprite.setTextureRect(sf::IntRect(350 * i, 0, 350, 400));
                activePlayerSprite.setPosition((window.getSize().x / 2.f) - 175, 310);
                isActiveSelectCharacterMode = true;
                indexActivePlayer = i;
                break;
            }
        }
    }
}

void CharacterWindow::setGame(Game &game1) {
    game = game1;
}

Game &CharacterWindow::getGame() {
    return game;
}
