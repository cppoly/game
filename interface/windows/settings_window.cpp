//
// Created by Максим Хованский on 22.11.2023.
//

#include "settings_window.h"

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
    if (!font1.loadFromFile("assets/fonts/Minecraft.otf") || !font2.loadFromFile("assets/fonts/Bionicle.ttf")) {
        throw std::runtime_error("Can't load fonts");
    }

    if (!settingsTexture.loadFromFile("assets/sprite/Settings.png")) {
        throw std::runtime_error("Can't load settings texture");
    }
    settingsSprite = sf::Sprite(settingsTexture);

    set_text(titleSettingsPage, font2, title, 90, sf::Color::White, sf::Text::Bold, (window.getSize().x / 2.f) - 200,
             100);
    set_text(settings1, font1, settings1Name, 40, sf::Color::White, sf::Text::Bold, 300, 400 + 0 * 50);
    set_text(settings2, font1, settings2Name, 40, sf::Color::White, sf::Text::Bold, 300, 400 + 1 * 50);
    set_text(settings3, font1, settings3Name, 40, sf::Color::White, sf::Text::Bold, 300, 400 + 2 * 50);
    set_text(settings4, font1, settings4Name, 40, sf::Color::White, sf::Text::Bold, 300, 400 + 3 * 50);
    set_text(settings5, font1, settings5Name, 40, sf::Color::White, sf::Text::Bold, 300, 400 + 4 * 50);

    text1.setSize(5);

}

void SettingsWindow::draw(sf::RenderWindow &window) {
    window.clear();

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

void SettingsWindow::handleEvent(sf::Event &event) {
    textBox1.handleEvent(event);
    textBox2.handleEvent(event);
    textBox3.handleEvent(event);
    textBox4.handleEvent(event);
    textBox5.handleEvent(event);
}