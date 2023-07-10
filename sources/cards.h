#pragma once

#include <string>
#include <vector>

class Card {
public:
    Card(
            std::string name,
            int money,
            int position_delta,
            int position_to,
            int amount_of_jail_cards
    );

    ~Card() = default;

    std::string get_name() const;

    int change_money() const;

    int change_position_on_delta() const;

    int change_position_to() const;

    bool change_jail_status() const;

private:
    std::string name;

    int money;
    int position_delta;
    int position_to;
    int amount_of_jail_cards;


};


std::vector<Card> get_cards_for_chance();

std::vector<Card> get_cards_for_community_chest();
