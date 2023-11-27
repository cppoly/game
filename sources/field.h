#pragma once

#include <vector>
#include <string>
#include "cards.h"
#include "player.h"

enum FieldTypes {
    START,
    STREET,
    STATION,
    UTILITY,
    JAIL,
    PARKING,
    GO_TO_JAIL,
    CHANCE,
    COMMUNITY_CHEST,
    TAX
};

class Player;

class Field {
public:
    Field(FieldTypes, std::string name = "");

    virtual ~Field() = default;

    virtual FieldTypes get_type() const;

    std::string get_name() const;

private:

    FieldTypes field_type;

    std::string name;
};


const int mortgage_percent = 10;

const int sell_percent = 50;

class Start : public Field {
public:
    Start(int money_for_visit_start);

    ~Start() override = default;

private:
    int money_for_visit_start;

    FieldTypes field_type = FieldTypes::START;
};

class ProfitableField : public Field {
public:
    ProfitableField(
            std::string name,
            int price,
            std::vector<int> rent,
            int mortgage_price,
            int type,
            FieldTypes field_type
    );

    ~ProfitableField() override = default;

    int get_price() const;

    int get_mortgage_price() const;

    int get_redemption_price() const;

    std::vector<int> get_rent_vector() const;

    bool get_is_mortgaged() const;

    int get_rent() const;

    int get_collection_type() const;

    Player *get_owner() const;

    void buy(Player *player);

    void mortgage();

    void unmortgage();

private:
    int price;
    std::vector<int> rent;

    int mortgage_price;
    bool is_mortgaged = false;
    int type;

    Player *owner = nullptr;
};

class Street : public ProfitableField {
public:
    Street(std::string name, int price, std::vector<int> rent, int house_price, int hotel_price, int mortgage_price,
           int type);

    ~Street() override = default;

    int get_rent() const;

    int get_house_price() const;

    int get_hotel_price() const;

    int get_amount_of_houses() const;

    void build(Player &player);

    void sell_house(Player &player);

private:
    void build_house(Player &player) const;

    void build_hotel(Player &player) const;

    int house_price;
    int hotel_price;
    int amount_of_houses = 0;

    FieldTypes field_type = FieldTypes::STREET;
};


class Station : public ProfitableField {
public:
    Station(std::string name, int price, std::vector<int> rent, int mortgage_price, int type);

    int get_rent(int amount_of_stations) const;

private:
    FieldTypes field_type = FieldTypes::STATION;
};


class Utility : public ProfitableField {
public:
    Utility(std::string name, int price, std::vector<int> rent, int mortgage_price, int type);

    int get_rent(int amount_of_utilities) const;

private:
    FieldTypes field_type = FieldTypes::UTILITY;
};

class Jail : public Field {
public:
    Jail(int price);

    ~Jail() override = default;

    int get_price() const;

private:
    int price;

    FieldTypes field_type = FieldTypes::JAIL;
};


class Parking : public Field {
public:
    Parking();

    ~Parking() override = default;

private:
    int bonus = 0;

    FieldTypes field_type = FieldTypes::PARKING;
};


class GoToJail : public Field {
public:
    GoToJail();

    ~GoToJail() override = default;

private:
    FieldTypes field_type = FieldTypes::GO_TO_JAIL;
};


class Chance : public Field {
public:
    Chance();

    ~Chance() override = default;

    std::string draw_card(Player &player);

private:
    std::vector<Card> cards;

    FieldTypes field_type = FieldTypes::CHANCE;
};


class CommunityChest : public Field {
public:
    CommunityChest();

    ~CommunityChest() override = default;

    std::string draw_card(Player &player);

private:
    std::vector<Card> cards;

    FieldTypes field_type = FieldTypes::COMMUNITY_CHEST;
};


class Tax : public Field {
public:
    Tax(int price);

    ~Tax() override = default;

    int get_price() const;

private:
    int price;

    FieldTypes field_type = FieldTypes::TAX;
};


