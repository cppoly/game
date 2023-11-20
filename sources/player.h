#pragma once

#include <vector>
#include <string>
#include "field.h"

class ProfitableField;
class Field;

class Player {
public:
    Player(
            std::string color,
            std::string name,
            int money,
            int position,
            int amount_of_jail_cards
    );

    ~Player() = default;

    int get_money() const;

    int get_position() const;

    int get_amount_of_jail_cards() const;

    void set_money(int money);

    void set_position(int position);

    void set_amount_of_jail_cards(int amount_of_jail_cards);

    void add_field(ProfitableField &field);

    void remove_street(Field &field);

    void mortgage_street(Field &field);

    void increment_position(int number_on_dice);

private:
    std::string color;
    std::string name;
    int money;
    int position;
    int amount_of_jail_cards;

    std::vector<Field *> fields;
};