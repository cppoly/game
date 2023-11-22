#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../input/input.hpp"


class SettingsWindow {
public:
    SettingsWindow(sf::RenderWindow &window);

    void draw(sf::RenderWindow &window);

    void handleEvent(sf::Event &event);
private:
    void set_text(sf::Text& text, sf::Font& font, std::string& str, int size, sf::Color color, sf::Text::Style style, float x, float y);

    sf::Font font1, font2;

    sf::Text titleSettingsPage;
    sf::Text settings1;
    sf::Text settings2;
    sf::Text settings3;
    sf::Text settings4;
    sf::Text settings5;

    sf::Texture settingsTexture;
    sf::Sprite settingsSprite;

    std::string title = "Settings";
    std::string settings1Name = "Money for game start";
    std::string settings2Name = "Money for game start";
    std::string settings3Name = "Money for game start";
    std::string settings4Name = "Money for game start";
    std::string settings5Name = "Money for game start";

    sdx::TextBox::Text text1 = sdx::TextBox::Text("", 0, 0);
    sdx::TextBox::Text text2 = sdx::TextBox::Text("", 0, 0);
    sdx::TextBox::Text text3 = sdx::TextBox::Text("", 0, 0);
    sdx::TextBox::Text text4 = sdx::TextBox::Text("", 0, 0);
    sdx::TextBox::Text text5 = sdx::TextBox::Text("", 0, 0);

    sdx::TextBox textBox1 = sdx::TextBox(450, 40, 1000, 400 + 0 * 50, 2);
    sdx::TextBox textBox2 = sdx::TextBox(450, 40, 1000, 400 + 1 * 50, 2);
    sdx::TextBox textBox3 = sdx::TextBox(450, 40, 1000, 400 + 2 * 50, 2);
    sdx::TextBox textBox4 = sdx::TextBox(450, 40, 1000, 400 + 3 * 50, 2);
    sdx::TextBox textBox5 = sdx::TextBox(450, 40, 1000, 400 + 4 * 50, 2);
};
