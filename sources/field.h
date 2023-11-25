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
    virtual ~Field() = default;

    virtual FieldTypes get_type() const;
};


const int mortgage_percent = 10;

const int sell_percent = 50;

class Start : public Field {
public:
    Start(int money_for_visit_start);

    ~Start() override = default;

    FieldTypes get_type() const override;

private:
    std::string name = "Старт";
    int money_for_visit_start;

};

class ProfitableField : public Field {
public:
    ProfitableField() = default;

    ProfitableField(
            std::string name,
            int price,
            std::vector<int> rent,
            int mortgage_price,
            int type
    );

    ~ProfitableField() override = default;

    std::string get_name() const;

    int get_price() const;

    int get_mortgage_price() const;

    int get_redemption_price() const;

    std::vector<int> get_rent_vector() const;

    bool get_is_mortgaged() const;

    int get_rent() const;

    Player *get_owner() const;

    void buy(Player &player);

    void mortgage();

    void unmortgage();

private:
    std::string name;
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

    FieldTypes get_type() const override;

    void build(Player &player);

    void sell_house(Player &player);

private:
    void build_house(Player &player) const;

    void build_hotel(Player &player) const;

    std::string name;
    int price;
    std::vector<int> rent;

    int house_price;
    int hotel_price;
    int amount_of_houses = 0;

    int mortgage_price;
    bool is_mortgaged = false;
    int type;
};


class Station : public ProfitableField {
public:
    Station(std::string name, int price, std::vector<int> rent, int mortgage_price, int type);

    int get_rent(int amount_of_stations) const;

    FieldTypes get_type() const override;

private:
    std::string name;
    int price;
    std::vector<int> rent;

    int mortgage_price;
    bool is_mortgaged = false;
    int type;
};


class Utility : public ProfitableField {
public:
    Utility(std::string name, int price, std::vector<int> rent, int mortgage_price, int type);

    int get_rent(int amount_of_utilities) const;

    FieldTypes get_type() const override;

private:
    std::string name;
    int price;
    std::vector<int> rent;

    int mortgage_price;
    bool is_mortgaged = false;
    int type;
};

class Jail : public Field {
public:
    Jail(int price);

    ~Jail() override = default;

    int get_price() const;

    FieldTypes get_type() const override;

private:
    std::string name = "Тюрьма";
    int price;
};


class Parking : public Field {
public:
    Parking();

    ~Parking() override = default;

    FieldTypes get_type() const override;

private:
    std::string name = "Бесплатная парковка";
    int bonus = 0;
};


class GoToJail : public Field {
public:
    GoToJail();

    ~GoToJail() override = default;

    FieldTypes get_type() const override;

private:
    std::string name = "Иди в тюрьму";
};


class Chance : public Field {
public:
    Chance();

    ~Chance() override = default;

    FieldTypes get_type() const override;

    std::string draw_card(Player &player);

private:
    std::string name = "Шанс";
    std::vector<Card> cards;
};


class CommunityChest : public Field {
public:
    CommunityChest();

    ~CommunityChest() override = default;

    FieldTypes get_type() const override;

    std::string draw_card(Player &player);

private:
    std::string name = "Общественная казна";
    std::vector<Card> cards;
};


class Tax : public Field {
public:
    Tax(int price);

    ~Tax() override = default;

    int get_price() const;

    FieldTypes get_type() const override;

private:
    std::string name = "Налог";
    int price;
};


