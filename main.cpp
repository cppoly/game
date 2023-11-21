#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "sources/player.h"
#include "sources/game.h"
#include "interface/input/input.hpp"

void set_text(sf::Text& text, sf::Font& font, std::string& str, int size, sf::Color color, sf::Text::Style style, float x, float y) {
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setStyle(style);
    text.setPosition(x, y);
}


int main() {
    sf::RenderWindow window(sf::VideoMode({1024, 1024}), "Monopoly", sf::Style::Fullscreen);

    sf::Font font1, font2;
    if (!font1.loadFromFile("assets/fonts/Minecraft.otf") || !font2.loadFromFile("assets/fonts/Bionicle.ttf")) {
        return EXIT_FAILURE;
    }


    //Main Screen

    sf::Texture mainScreenTexture;
    if (!mainScreenTexture.loadFromFile("assets/sprite/Main.png")) {
        return EXIT_FAILURE;
    }

    sf::Sprite mainScreenSprite(mainScreenTexture);

    sf::Texture buttonStartGameTexture;
    if (!buttonStartGameTexture.loadFromFile("assets/sprite/buttonStartGame.png")) {
        return EXIT_FAILURE;
    }

    sf::Sprite buttonStartGameSprite(buttonStartGameTexture);
    buttonStartGameSprite.setTextureRect(sf::IntRect(0, 0, 400, 175));
    buttonStartGameSprite.setPosition((window.getSize().x / 2.f) - 200, (window.getSize().y / 2.f) - 82.5);

    bool isActiveMainScreen = true;
    bool isActiveSettings = false;

    // Settings

    sf::Texture settingsTexture;
    if (!settingsTexture.loadFromFile("assets/sprite/Settings.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite settingsSprite(settingsTexture);

    sf::Text titleSettingsPage;

    sf::Text settings1;
    sf::Text settings2;
    sf::Text settings3;
    sf::Text settings4;
    sf::Text settings5;

//    titleSettingsPage.setFont(font2);
//    titleSettingsPage.setString("Settings");
//    titleSettingsPage.setCharacterSize(90);
//    titleSettingsPage.setFillColor(sf::Color::White);
//    titleSettingsPage.setStyle(sf::Text::Bold);
//    titleSettingsPage.setPosition((window.getSize().x / 2.f) - 200, 100);

    std::string title ="Settings";
    std::string settings1Name = "Money for game start";
    std::string settings2Name = "Money for game start";
    std::string settings3Name = "Money for game start";
    std::string settings4Name = "Money for game start";
    std::string settings5Name = "Money for game start";


    set_text(titleSettingsPage, font2, title, 90, sf::Color::White, sf::Text::Bold, (window.getSize().x / 2.f) - 200, 100 );
    set_text(settings1, font1, settings1Name, 40, sf::Color::White, sf::Text::Bold, 300, 400 + 0 * 50);
    set_text(settings2, font1, settings2Name, 40, sf::Color::White, sf::Text::Bold, 300, 400 + 1 * 50);
    set_text(settings3, font1, settings3Name, 40, sf::Color::White, sf::Text::Bold, 300, 400 + 2 * 50);
    set_text(settings4, font1, settings4Name, 40, sf::Color::White, sf::Text::Bold, 300, 400 + 3 * 50);
    set_text(settings5, font1, settings5Name, 40, sf::Color::White, sf::Text::Bold, 300, 400 + 4 * 50);


    int money_for_game_start = 1500;
    int money_for_win = 0;
    int money_per_loop = 200;
    int bonus_for_visit_start = 0;
    bool is_free_parking = true;
    int jail_price = 50;
    int seconds_per_turn = 0;


    sdx::TextBox textBox1 = sdx::TextBox(450, 40, 1000, 400 + 0 * 50, 2);
    sdx::TextBox::Text text1("", 0, 0);
    sdx::TextBox textBox2 = sdx::TextBox(450, 40, 1000, 400 + 1 * 50, 2);
    sdx::TextBox::Text text2("", 0, 0);
    sdx::TextBox textBox3 = sdx::TextBox(450, 40, 1000, 400 + 2 * 50, 2);
    sdx::TextBox::Text text3("", 0, 0);
    sdx::TextBox textBox4 = sdx::TextBox(450, 40, 1000, 400 + 3 * 50, 2);
    sdx::TextBox::Text text4("", 0, 0);
    sdx::TextBox textBox5 = sdx::TextBox(450, 40, 1000, 400 + 4 * 50, 2);
    sdx::TextBox::Text text5("", 0, 0);

    text1.setSize(5);

    // Players

    std::vector<sf::Texture> playersTexture(3);
    std::vector<sf::Sprite> playersSprite;
    std::vector<Player> players;

    for (int i = 0; i < playersTexture.size(); i++) {
        if (!playersTexture[i].loadFromFile("assets/sprite/Player" + std::to_string(i + 1) + ".png")) {
            return EXIT_FAILURE;
        }
        sf::Sprite sprite1(playersTexture[i]);
        if (i == 2) {
            Player player(sprite1, "Alyona", 1500, 11, 0);
            players.push_back(player);
            playersSprite.push_back(sprite1);
            continue;
        }
        Player player(sprite1, "Alyona", 1500, 1, 0);
        players.push_back(player);
        playersSprite.push_back(sprite1);

    }

//    sf::View view1;
//    view1.reset(sf::FloatRect(724.f, 724.f, 300.f, 300.f));

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            switch (event.type) {
                case (sf::Event::Closed):
                    window.close();
                case (sf::Event::KeyPressed):
                    if (event.key.code == sf::Keyboard::Escape) window.close();
                default:
                    break;
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (buttonStartGameSprite.getGlobalBounds().contains(
                            window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                        buttonStartGameSprite.setTextureRect(sf::IntRect(400 * 1, 0, 400, 175));
                        isActiveMainScreen = false;
                        isActiveSettings = true;
                    }
                }
            } else if (event.type == sf::Event::MouseMoved) {
                if (buttonStartGameSprite.getGlobalBounds().contains(
                        window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    buttonStartGameSprite.setTextureRect(sf::IntRect(400 * 2, 0, 400, 175));
                } else {
                    buttonStartGameSprite.setTextureRect(sf::IntRect(0, 0, 400, 175));
                }
            } else {
                buttonStartGameSprite.setTextureRect(sf::IntRect(0, 0, 400, 175));
            }
            textBox1.handleEvent(event);
            textBox2.handleEvent(event);
            textBox3.handleEvent(event);
            textBox4.handleEvent(event);
            textBox5.handleEvent(event);
        }


        if (isActiveMainScreen) {
            window.clear();
            window.draw(mainScreenSprite);
            window.draw(buttonStartGameSprite);
        } else if (isActiveSettings) {
            text1.setText(textBox1.getInput());

            text2.setText(textBox2.getInput());

            text3.setText(textBox3.getInput());

            text4.setText(textBox4.getInput());

            text5.setText(textBox5.getInput());

            window.draw(settingsSprite);

            textBox1.draw(window);
            window.draw(text1.get());

            textBox2.draw(window);
            window.draw(text2.get());

            textBox3.draw(window);
            window.draw(text3.get());

            textBox4.draw(window);
            window.draw(text4.get());

            textBox5.draw(window);
            window.draw(text5.get());

            window.draw(titleSettingsPage);
            window.draw(settings1);
            window.draw(settings2);
            window.draw(settings3);
            window.draw(settings4);
            window.draw(settings5);
        }
        window.display();
    }

    return 0;
}
