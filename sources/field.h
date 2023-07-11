#pragma once

#include <vector>
#include <string>
#include "cards.h"
#include "player.h"

class Field {
public:
    virtual ~Field() = 0;
};


class Start : public Field {
public:
    Start(int money_for_visit_start);

    ~Start() override = default;

private:
    std::string name = "Старт";
    int money_for_visit_start;
};


class Street : public Field {
public:
    Street(
            std::string name,
            int price,
            std::vector<int> rent,
            int house_price,
            int hotel_price,
            int mortgage_price
    );

    ~Street() override = default;

    int get_price() const;

    int get_rent() const;

    void buy(Player &player);

    void sell(Player &player);

    void build_house(Player &player);

    void build_hotel(Player &player);

private:
    std::string name;
    int price;
    std::vector<int> rent;
    int house_price;
    int hotel_price;
    int mortgage_price;

    int amount_of_houses = 0;
};


class Station : public Field {
public:
    Station(
            std::string name,
            int price,
            std::vector<int> rent,
            int mortgage_price
    );

    ~Station() override = default;

    void buy(Player &player);

    void sell(Player &player);

private:
    std::string name;
    int price;
    std::vector<int> rent;
    int mortgage_price;
};


class Utility : public Field {
public:
    Utility(
            std::string name,
            int price,
            std::vector<int> rent,
            int mortgage_price
    );

    ~Utility() override = default;

    void buy(Player &player);

    void sell(Player &player);

private:
    std::string name;
    int price;
    std::vector<int> rent;
    int mortgage_price;
};

class Jail : public Field {
public:
    Jail(int price);

    ~Jail() override = default;

private:
    std::string name = "Тюрьма";
    int price;
};


class Parking : public Field {
public:
    Parking();

    ~Parking() override = default;

private:
    std::string name = "Бесплатная парковка";
    int bonus = 0;
};


class GoToJail : public Field {
public:
    GoToJail();

    ~GoToJail() override = default;

private:
    std::string name = "Иди в тюрьму";
};


class Chance : public Field {
public:
    Chance();

    ~Chance() override = default;

    std::string draw_card(Player &player);

private:
    std::string name = "Шанс";
    std::vector<Card> cards;
};


class CommunityChest : public Field {
public:
    CommunityChest();

    ~CommunityChest() override = default;

    std::string draw_card(Player &player);

private:
    std::string name = "Общественная казна";
    std::vector<Card> cards;
};


class Tax : public Field {
public:
    Tax(int price);

    ~Tax() override = default;

private:
    std::string name = "Налог";
    int price;
};


