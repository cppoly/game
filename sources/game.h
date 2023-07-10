#pragma once

#include <vector>
#include "player.h"

class Game {
public:
    Game();

    ~Game();

    void run();

private:
    int money_for_game_start:;
    int money_for_win;
    int money_per_loop;

    int bonus_for_visit_start;

    bool is_free_parking;
    int jail_price;

    int seconds_per_turn;

    std::vector<Player> players;
};