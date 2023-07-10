#pragma once

#include <vector>
#include <string>


class Player {
public:
    Player();

    ~Player();

    void change_money(int delta);

    void change_position(int delta);

    void get_position();

    void change_jail_cards(int delta);

    void change_jail_status(bool status);

private:
    std::string color;
    std::string name;

    int money;
    int position;
    int amount_of_jail_cards;
};