#include "cards.h"

#include <utility>


Card::Card(std::string name, int money, int position_delta, int position_to, int amount_of_jail_cards) {
    this->name = std::move(name);
    this->money = money;
    this->position_delta = position_delta;
    this->position_to = position_to;
    this->amount_of_jail_cards = amount_of_jail_cards;
}


std::string Card::get_name() const {
    return name;
}

int Card::change_money() const {
    return money;
}

int Card::change_position_on_delta() const {
    return position_delta;
}

int Card::change_position_to() const {
    return position_to;
}

bool Card::change_jail_status() const {
    return amount_of_jail_cards;
}


std::vector<Card> get_cards_for_chance() {
    std::vector<Card> cards;

    cards.emplace_back("Идите на 2 клетки вперед", 0, 2, 0, 0);

    return cards;
}

std::vector<Card> get_cards_for_community_chest() {
    std::vector<Card> cards;

    cards.emplace_back("Collect 200$", 200, 0, 0, 0);

    return cards;
}