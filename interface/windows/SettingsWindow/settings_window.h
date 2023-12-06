#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../../input/input.h"
#include "../../../sources/game.h"

class SettingsWindow {
public:
    SettingsWindow(sf::RenderWindow &window);

    void draw(sf::RenderWindow &window);

    bool handleEvent(sf::Event &event, sf::RenderWindow &window);

    void onCheckboxClick();

    void onApplySettings();

    Game getGame() const;

private:
    Game game;

    int money_for_game_start = 1500;
    int money_for_win = 0;
    int money_per_loop = 200;
    int bonus_for_visit_start = 0;
    int jail_price = 50;
    int seconds_per_turn = 0;


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

    sdx::TextBox::Text text1 = sdx::TextBox::Text("", 100, 100);
    sdx::TextBox::Text text2 = sdx::TextBox::Text("", 100, 100);
    sdx::TextBox::Text text3 = sdx::TextBox::Text("", 100, 100);
    sdx::TextBox::Text text4 = sdx::TextBox::Text("", 100, 100);
    sdx::TextBox::Text text5 = sdx::TextBox::Text("", 100, 100);
    sdx::TextBox::Text text6 = sdx::TextBox::Text("", 100, 100);

    sdx::TextBox textBox1;
    sdx::TextBox textBox2;
    sdx::TextBox textBox3;
    sdx::TextBox textBox4;
    sdx::TextBox textBox5;
    sdx::TextBox textBox6;

    bool isActiveCheckbox = false;
};
