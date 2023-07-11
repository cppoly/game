#include "player.h"

Player::Player(
        std::string color,
        std::string name,
        int money,
        int position,
        int amount_of_jail_cards
) :
        color(std::move(color)),
        name(std::move(name)),
        money(money),
        position(position),
        amount_of_jail_cards(amount_of_jail_cards) {
    streets.reserve(28);
}
