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
    fields = std::vector<Field *>();
}

int Player::get_money() const {
    return money;
}

int Player::get_position() const {
    return position;
}

int Player::get_amount_of_jail_cards() const {
    return amount_of_jail_cards;
}

void Player::set_money(int money) {
    Player::money = money;
}

void Player::set_position(int position) {
    Player::position = position;
}

void Player::set_amount_of_jail_cards(int amount_of_jail_cards) {
    Player::amount_of_jail_cards = amount_of_jail_cards;
}

void Player::add_field(ProfitableField &field) {
    fields.push_back(&field);
}

void Player::remove_street(Field &field) {
    for (auto it = fields.begin(); it != fields.end(); ++it) {
        if (*it == &field) {
            fields.erase(it);
            // TODO: add money
            // TODO: check houses
            // TODO: check hotels
            break;
        }
    }
}

void Player::mortgage_street(Field &field) {
    for (auto it = fields.begin(); it != fields.end(); ++it) {
        if (*it == &field) {
            fields.erase(it);
            // TODO: add money
            // TODO: do not remove field
            break;
        }
    }
}

void Player::increment_position(int number_on_dice) {
    position += number_on_dice;
    if (position >= 40) {
        position -= 40;
        money += 200;
    }
}
