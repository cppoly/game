#include "field.h"


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


void Street::buy(Player &player) {
    player.set_money(player.get_money() - price);
    player.add_street(&*this);
}

void Street::sell(Player &player) {
    player.set_money(player.get_money() + mortgage_price);
    player.remove_street(&*this);
}

void Street::build_house(Player &player) {
    player.set_money(player.get_money() - house_price);
}

void Street::build_hotel(Player &player) {
    player.set_money(player.get_money() - hotel_price);
}

