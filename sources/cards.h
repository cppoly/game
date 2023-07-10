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
            int amount_of_jail_cards,
    );

    ~Card();

    std::string get_name();

    int change_money();

    int change_position_on_delta();

    int change_position_to();

    bool change_jail_status();

private:
    std::string name;

    int money;
    int position;
    int position_to;
    int amount_of_jail_cards;


};


std::vector<Card> get_cards_for_chance();

std::vector<Card> get_cards_for_community_chest();
