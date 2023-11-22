#pragma once

#include <vector>
#include <random>
#include <algorithm>
#include "player.h"
#include "field.h"
#include "settings.h"
#include <SFML/Graphics.hpp>

enum class GameFieldTypes {
    DO_NOTHING,
    PAY_PLAYER,
    PAY_BANK,
    GO_TO_JAIL,
    DRAW_CARD,
    YOU_CAN_BUY,
};

struct GameMove {
    int player_id;
    int number_on_dice1;
    int number_on_dice2;
    int old_position;
    int new_position;
    GameFieldTypes funcs;

    int player_to_pay;
    int amount_to_pay;
    ProfitableField field_to_buy;
};

class Game {
public:
    Game() = default;

    Game(
            int money_for_game_start,
            int money_for_win,
            int money_per_loop,
            int bonus_for_visit_start,

            bool is_free_parking,
            int jail_price,
            int seconds_per_turn
    );

    ~Game() = default;

    void add_player(sf::Sprite sprite, std::string name);

    std::vector<Player> get_players() const;

    void start_game();

    GameMove player_move();

    int next_turn();

    Game &operator=(const Game &other);


private:
    void feel_game_fields();

    static int number_on_dice();

    GameSettings &settings = GameSettings::getInstance();

    int cur_player_id;

    std::vector<Field> game_fields;
    std::vector<Player> players;

    bool is_game_started = false;
    bool is_player_do_move = false;
};