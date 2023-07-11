#include "field.h"


ProfitableField::ProfitableField(
        std::string name,
        int price,
        std::vector<int> rent,
        int mortgage_price
) :
        name(std::move(name)),
        price(price),
        rent(std::move(rent)),
        mortgage_price(mortgage_price) {}

std::string ProfitableField::get_name() const {
    return name;
}

int ProfitableField::get_price() const {
    return price;
}

int ProfitableField::get_mortgage_price() const {
    return mortgage_price;
}

int ProfitableField::get_redemption_price() const {
    return mortgage_price * (100 + mortgage_percent) / 100;
}

std::vector<int> ProfitableField::get_rent_vector() const {
    return rent;
}

void ProfitableField::buy(Player &player) {
    if (is_mortgaged) {
        if (player.get_money() < get_redemption_price()) {
            return;
        }
        player.set_money(player.get_money() - get_redemption_price());
    } else {
        if (player.get_money() < price) {
            return;
        }
        player.set_money(player.get_money() - price);
        player.add_field(&*this);
    }
}


void ProfitableField::mortgage(Player &player) {
    if (is_mortgaged) {
        return;
    }
    player.set_money(player.get_money() + mortgage_price);
    is_mortgaged = true;
}


Start::Start(int money_for_visit_start) : money_for_visit_start(money_for_visit_start) {}

Street::Street(
        std::string name,
        int price,
        std::vector<int> rent,
        int house_price,
        int hotel_price,
        int mortgage_price
) :
        name(std::move(name)),
        price(price),
        rent(std::move(rent)),
        house_price(house_price),
        hotel_price(hotel_price),
        mortgage_price(mortgage_price) {}


int Street::get_rent() const {
    return rent[amount_of_houses];
}

int Street::get_house_price() const {
    return house_price;
}

int Street::get_hotel_price() const {
    return hotel_price;
}

int Street::get_amount_of_houses() const {
    return amount_of_houses;
}

void Street::build(Player &player) {
    if (amount_of_houses < 4) {
        amount_of_houses++;
        build_house(player);
    } else if (this->amount_of_houses == 4) {
        amount_of_houses++;
        build_hotel(player);
    } else {
        return;
    }
}

void Street::sell_house(Player &player) {
    if (amount_of_houses == 0) {
        return;
    }
    amount_of_houses--;
    player.set_money(player.get_money() + house_price / 2);
}

void Street::build_house(Player &player) const {
    if (player.get_money() < house_price) {
        return;
    }
    player.set_money(player.get_money() - house_price);
}

void Street::build_hotel(Player &player) const {
    if (player.get_money() < hotel_price) {
        return;
    }
    player.set_money(player.get_money() - hotel_price);
}

int Station::get_rent(int amount_of_stations) const {
    return rent[amount_of_stations];
}

int Utility::get_rent(int amount_of_utilities) const {
    return rent[amount_of_utilities];
}
