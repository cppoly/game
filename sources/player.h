#pragma once

#include <vector>
#include <string>
#include "field.h"
#include "settings.h"
#include <SFML/Graphics.hpp>

class ProfitableField;

class Field;

class Player {
public:
    Player(
            sf::Sprite sprite,
            std::string name,
            int money,
            int position,
            int amount_of_jail_cards
    );

    ~Player() = default;

    int get_money() const;

    int get_position() const;

    sf::Sprite get_sprite() const;

    std::string get_name() const;

    int get_amount_of_jail_cards() const;

    void set_money(int money);

    void set_position(int position);

    void set_amount_of_jail_cards(int amount_of_jail_cards);

    void add_field(ProfitableField &field);

    void remove_field(ProfitableField &field);

    void increment_position(int number_on_dice);

    Player &operator=(const Player &other);

private:
    sf::Sprite sprite;
    std::string name;

    GameSettings &settings = GameSettings::getInstance();

    int money;
    int position;
    int amount_of_jail_cards;

    std::vector<ProfitableField *> fields;
    // todo: is in jail
};