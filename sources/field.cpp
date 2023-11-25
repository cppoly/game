#include "field.h"


Field::Field(FieldTypes type) : field_type(type) {}

ProfitableField::ProfitableField(
        std::string name,
        int price,
        std::vector<int> rent,
        int mortgage_price,
        int type,
        FieldTypes field_type
) :
        Field(field_type),
        name(std::move(name)),
        price(price),
        rent(std::move(rent)),
        mortgage_price(mortgage_price),
        type(type) {}

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
    player.add_field(*this);
    owner = &player;
}


void ProfitableField::mortgage() {
    if (owner == nullptr) {
        return;
    }
    if (is_mortgaged) {
        return;
    }
    is_mortgaged = true;
}

void ProfitableField::unmortgage() {
    if (owner == nullptr) {
        return;
    }
    if (!is_mortgaged) {
        return;
    }
    is_mortgaged = false;
}

Player *ProfitableField::get_owner() const {
    return owner;
}

bool ProfitableField::get_is_mortgaged() const {
    return is_mortgaged;
}

int ProfitableField::get_rent() const {
    return rent[0];
}

Start::Start(int money_for_visit_start) : Field(FieldTypes::START), money_for_visit_start(money_for_visit_start) {}

Street::Street(std::string name, int price, std::vector<int> rent, int house_price, int hotel_price, int mortgage_price,
               int type)
        :
        ProfitableField(name, price, rent, mortgage_price, type, FieldTypes::STREET), name(std::move(name)),
        price(price),
        rent(std::move(rent)), house_price(house_price), hotel_price(hotel_price), mortgage_price(mortgage_price),
        type(type) {}


int Street::get_rent() const {
    // todo
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
    // todo
    return rent[amount_of_stations];
}

int Utility::get_rent(int amount_of_utilities) const {
    // todo
    return rent[amount_of_utilities];
}

Station::Station(std::string name, int price, std::vector<int> rent, int mortgage_price, int type) :
        ProfitableField(name, price, rent, mortgage_price, type, FieldTypes::STATION), name(std::move(name)),
        price(price),
        rent(std::move(rent)), mortgage_price(mortgage_price), type(type) {}

Utility::Utility(std::string name, int price, std::vector<int> rent, int mortgage_price, int type) :
        ProfitableField(name, price, rent, mortgage_price, type, FieldTypes::UTILITY), name(std::move(name)),
        price(price),
        rent(std::move(rent)), mortgage_price(mortgage_price), type(type) {}

Tax::Tax(int tax) : Field(FieldTypes::TAX), price(tax) {}

int Tax::get_price() const {
    return price;
}

Jail::Jail(int price) : Field(FieldTypes::JAIL), price(price) {}

int Jail::get_price() const {
    return price;
}

FieldTypes Start::get_type() const {
    return FieldTypes::START;
}

FieldTypes Street::get_type() const {
    return FieldTypes::STREET;
}

FieldTypes Station::get_type() const {
    return FieldTypes::STATION;
}

FieldTypes Utility::get_type() const {
    return FieldTypes::UTILITY;
}

FieldTypes Tax::get_type() const {
    return FieldTypes::TAX;
}

FieldTypes Jail::get_type() const {
    return FieldTypes::JAIL;
}

FieldTypes CommunityChest::get_type() const {
    return FieldTypes::COMMUNITY_CHEST;
}

FieldTypes Chance::get_type() const {
    return FieldTypes::CHANCE;
}

FieldTypes Parking::get_type() const {
    return FieldTypes::PARKING;
}

FieldTypes GoToJail::get_type() const {
    return FieldTypes::GO_TO_JAIL;
}

FieldTypes Field::get_type() const {
    return field_type;
}

// todo: do it
CommunityChest::CommunityChest() : Field(FieldTypes::COMMUNITY_CHEST) {}

Chance::Chance() : Field(FieldTypes::CHANCE) {}

Parking::Parking() : Field(FieldTypes::PARKING) {}

GoToJail::GoToJail() : Field(FieldTypes::GO_TO_JAIL) {}