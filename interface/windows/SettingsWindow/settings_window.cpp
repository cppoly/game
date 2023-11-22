#include "settings_window.h"
#include "../../../sources/game.h"

void SettingsWindow::set_text(sf::Text &text, sf::Font &font, std::string &str, int size, sf::Color color,
                              sf::Text::Style style, float x, float y) {
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setStyle(style);
    text.setPosition(x, y);
}

SettingsWindow::SettingsWindow(sf::RenderWindow &window) {
    if (!font1.loadFromFile("assets/fonts/big-shot.ttf") || !font2.loadFromFile("assets/fonts/Bionicle.ttf")) {
        throw std::runtime_error("Can't load fonts");
    }

    if (!settingsTexture.loadFromFile("assets/sprite/Settings.png")) {
        throw std::runtime_error("Can't load settings texture");
    }

    if (!checkboxTexture.loadFromFile("assets/sprite/Checkbox.png")) {
        throw std::runtime_error("Can't load checkbox texture");
    }

    if (!buttonApplyTexture.loadFromFile("assets/sprite/buttonApplySettings.png")) {
        throw std::runtime_error("Can't load button Apply Settings texture");
    }

    settingsSprite = sf::Sprite(settingsTexture);

    checkboxSprite = sf::Sprite(checkboxTexture);
    checkboxSprite.setTextureRect(sf::Rect(0, 0, 52, 49));
    checkboxSprite.setPosition(900, 338 + 6 * 100);

    buttonApplySprite = sf::Sprite(buttonApplyTexture);
    buttonApplySprite.setTextureRect(sf::Rect(0, 0, 360, 109));
    buttonApplySprite.setPosition(1500, 950);

    set_text(titleSettingsPage, font2, title, 90, sf::Color::White, sf::Text::Bold, (window.getSize().x / 2.f) - 200,
             100);
    set_text(settings1, font1, settings1Name, 40, sf::Color::Black, sf::Text::Bold, 240, 300 + 0 * 100);
    set_text(settings2, font1, settings2Name, 40, sf::Color::Black, sf::Text::Bold, 240, 300 + 1 * 100);
    set_text(settings3, font1, settings3Name, 40, sf::Color::Black, sf::Text::Bold, 240, 300 + 2 * 100);
    set_text(settings4, font1, settings4Name, 40, sf::Color::Black, sf::Text::Bold, 240, 300 + 3 * 100);
    set_text(settings5, font1, settings5Name, 40, sf::Color::Black, sf::Text::Bold, 240, 300 + 4 * 100);
    set_text(settings6, font1, settings6Name, 40, sf::Color::Black, sf::Text::Bold, 240, 300 + 5 * 100);
    set_text(settings7, font1, settings7Name, 40, sf::Color::Black, sf::Text::Bold, 240, 340 + 6 * 100);
}

void SettingsWindow::draw(sf::RenderWindow &window) {
    window.clear();

    text1.setText(textBox1.getInput());
    text2.setText(textBox2.getInput());
    text3.setText(textBox3.getInput());
    text4.setText(textBox4.getInput());
    text5.setText(textBox5.getInput());
    text6.setText(textBox6.getInput());

    window.draw(settingsSprite);

    textBox1.draw(window);
    textBox2.draw(window);
    textBox3.draw(window);
    textBox4.draw(window);
    textBox5.draw(window);
    textBox6.draw(window);

    window.draw(titleSettingsPage);
    window.draw(settings1);
    window.draw(settings2);
    window.draw(settings3);
    window.draw(settings4);
    window.draw(settings5);
    window.draw(settings6);
    window.draw(settings7);
    window.draw(checkboxSprite);
    window.draw(buttonApplySprite);
}

bool SettingsWindow::handleEvent(sf::Event &event, sf::RenderWindow &window) {

    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (checkboxSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                if (isActiveCheckbox) {
                    checkboxSprite.setTextureRect(sf::IntRect(0, 0, 52, 49));
                    isActiveCheckbox = false;
                } else {
                    checkboxSprite.setTextureRect(sf::IntRect(52, 0, 52, 49));
                    isActiveCheckbox = true;
                }
            }

            if (buttonApplySprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                buttonApplySprite.setTextureRect(sf::IntRect(360, 0, 360, 109));


                money_for_game_start =
                        std::string(textBox1.getInput()).size() != 0 ? std::stoi(std::string(textBox1.getInput()))
                                                                     : money_for_game_start;
                money_for_win =
                        std::string(textBox2.getInput()).size() != 0 ? std::stoi(std::string(textBox2.getInput()))
                                                                     : money_for_win;
                money_per_loop =
                        std::string(textBox3.getInput()).size() != 0 ? std::stoi(std::string(textBox3.getInput()))
                                                                     : money_per_loop;
                bonus_for_visit_start =
                        std::string(textBox4.getInput()).size() != 0 ? std::stoi(std::string(textBox4.getInput()))
                                                                     : bonus_for_visit_start;
                jail_price = std::string(textBox5.getInput()).size() != 0 ? std::stoi(std::string(textBox5.getInput()))
                                                                          : jail_price;
                seconds_per_turn =
                        std::string(textBox6.getInput()).size() != 0 ? std::stoi(std::string(textBox6.getInput()))
                                                                     : seconds_per_turn;


                game = Game(money_for_game_start, money_for_win, money_per_loop, bonus_for_visit_start,
                            isActiveCheckbox, jail_price, seconds_per_turn);
                return true;
            }
        }
    } else if (event.type == sf::Event::MouseMoved) {
        if (buttonApplySprite.getGlobalBounds().contains(
                window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            buttonApplySprite.setTextureRect(sf::IntRect(360 * 2, 0, 360, 109));
        } else {
            buttonApplySprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
        }
    } else {
        buttonApplySprite.setTextureRect(sf::IntRect(0, 0, 360, 109));
    }

    textBox1.handleEvent(event);
    textBox2.handleEvent(event);
    textBox3.handleEvent(event);
    textBox4.handleEvent(event);
    textBox5.handleEvent(event);
    textBox6.handleEvent(event);
    return false;
}

Game SettingsWindow::getGame() const {
    return game;
}