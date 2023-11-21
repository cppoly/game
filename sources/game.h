#pragma once

#include <vector>
#include "player.h"
#include "field.h"
#include "settings.h"

struct GameMove {
    int player_id;
    int number_on_dice1;
    int number_on_dice2;
    int cur_position;
};

class Game {
public:
    Game(
        int money_for_game_start,
        int money_for_win,
        int money_per_loop,
        int bonus_for_visit_start,

        bool is_free_parking,
        int jail_price,
        int seconds_per_turn,
        std::vector<Player> players
    );

    ~Game() = default;

    void run();

    GameMove player_move();

    int next_turn();

private:
    void feel_game_fields();
    static int number_on_dice();

    GameSettings &settings = GameSettings::getInstance();

    int money_for_game_start;
    int money_for_win;
    int money_per_loop;

    int bonus_for_visit_start;

    bool is_free_parking;
    int jail_price;

    int seconds_per_turn;

    int cur_position;


    std::vector<Field> game_fields;

    std::vector<Player> players;
};