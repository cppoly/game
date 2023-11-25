#include "field.h"


Field::Field(FieldTypes type, std::string name) : field_type(type), name(std::move(name)){}

ProfitableField::ProfitableField(
        std::string name,
        int price,
        std::vector<int> rent,
        int mortgage_price,
        int type,
        FieldTypes field_type
) :
        Field(field_type, name),
        price(price),
        rent(std::move(rent)),
        mortgage_price(mortgage_price),
        type(type) {}

Station::Station(std::string name, int price, std::vector<int> rent, int mortgage_price, int type) :
        ProfitableField(name, price, rent, mortgage_price, type, FieldTypes::STATION) {}

Utility::Utility(std::string name, int price, std::vector<int> rent, int mortgage_price, int type) :
        ProfitableField(name, price, rent, mortgage_price, type, FieldTypes::UTILITY) {}

Tax::Tax(int tax) : Field(FieldTypes::TAX, "Tax"), price(tax) {}

Jail::Jail(int price) : Field(FieldTypes::JAIL, "Jail"), price(price) {}

Start::Start(int money_for_visit_start) : Field(FieldTypes::START, "Start"), money_for_visit_start(money_for_visit_start) {}

Street::Street(std::string name, int price, std::vector<int> rent, int house_price, int hotel_price, int mortgage_price,
               int type)
        :
        ProfitableField(name, price, rent, mortgage_price, type, FieldTypes::STREET),
        house_price(house_price), hotel_price(hotel_price) {}

// todo: do it
CommunityChest::CommunityChest() : Field(FieldTypes::COMMUNITY_CHEST, "Community_chest") {}

Chance::Chance() : Field(FieldTypes::CHANCE, "Chance") {}

Parking::Parking() : Field(FieldTypes::PARKING, "Parking") {}

GoToJail::GoToJail() : Field(FieldTypes::GO_TO_JAIL, "Jail") {}


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

int ProfitableField::get_collection_type() const {
    return type;
}

int Street::get_rent() const {
    // todo
    return get_rent_vector()[amount_of_houses];
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
    return get_rent_vector()[amount_of_stations];
}

int Utility::get_rent(int amount_of_utilities) const {
    // todo
    return get_rent_vector()[amount_of_utilities];
}

int Tax::get_price() const {
    return price;
}

int Jail::get_price() const {
    return price;
}

FieldTypes Field::get_type() const {
    return field_type;
}

std::string Field::get_name() const {
    return name;
}
