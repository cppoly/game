#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../input/input.hpp"


class SettingsWindow {
public:
    SettingsWindow(sf::RenderWindow &window);

    void draw(sf::RenderWindow &window);

    void handleEvent(sf::Event &event, sf::RenderWindow &window);
private:

    void set_text(sf::Text& text, sf::Font& font, std::string& str, int size, sf::Color color, sf::Text::Style style, float x, float y);

    sf::Font font1, font2;

    sf::Text titleSettingsPage;
    sf::Text settings1;
    sf::Text settings2;
    sf::Text settings3;
    sf::Text settings4;
    sf::Text settings5;
    sf::Text settings6;
    sf::Text settings7;

    sf::Texture settingsTexture;
    sf::Sprite settingsSprite;

    sf::Texture checkboxTexture;
    sf::Sprite checkboxSprite;

    sf::Texture buttonApplyTexture;
    sf::Sprite buttonApplySprite;

    std::string title = "Settings";
    std::string settings1Name = "Money for game start:";
    std::string settings2Name = "Money for winner:";
    std::string settings3Name = "Money per loop:";
    std::string settings4Name = "Bonus for visit start:";
    std::string settings5Name = "Jail price:";
    std::string settings6Name = "Seconds per turn:";
    std::string settings7Name = "Parking is free?";

    sdx::TextBox::Text text1 = sdx::TextBox::Text("", 0, 0);
    sdx::TextBox::Text text2 = sdx::TextBox::Text("", 0, 0);
    sdx::TextBox::Text text3 = sdx::TextBox::Text("", 0, 0);
    sdx::TextBox::Text text4 = sdx::TextBox::Text("", 0, 0);
    sdx::TextBox::Text text5 = sdx::TextBox::Text("", 0, 0);
    sdx::TextBox::Text text6 = sdx::TextBox::Text("", 0, 0);

    sdx::TextBox textBox1 = sdx::TextBox(400, 40, 900, 310 + 0 * 100, 2);
    sdx::TextBox textBox2 = sdx::TextBox(400, 40, 900, 310 + 1 * 100, 2);
    sdx::TextBox textBox3 = sdx::TextBox(400, 40, 900, 310 + 2 * 100, 2);
    sdx::TextBox textBox4 = sdx::TextBox(400, 40, 900, 310 + 3 * 100, 2);
    sdx::TextBox textBox5 = sdx::TextBox(400, 40, 900, 310 + 4 * 100, 2);
    sdx::TextBox textBox6 = sdx::TextBox(400, 40, 900, 310 + 5 * 100, 2);

    bool isActiveCheckbox = false;
    bool isApplySettings = false;

    sf::Clock animationClock;

};
