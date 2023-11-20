#include "game.h"
#include <cstdlib>
#include <ctime>


Game::Game(int money_for_game_start, int money_for_win, int money_per_loop, int bonus_for_visit_start,
           bool is_free_parking, int jail_price, int seconds_per_turn, std::vector<Player> players)
        : money_for_game_start(money_for_game_start),
          money_for_win(money_for_win),
          money_per_loop(money_per_loop),
          bonus_for_visit_start(bonus_for_visit_start),
          is_free_parking(is_free_parking),
          jail_price(jail_price),
          seconds_per_turn(seconds_per_turn),
          players(std::move(players)) {
    feel_game_fields();
}

void Game::feel_game_fields() {

}

GameMove Game::player_move() {
    Player cur_player = players[cur_position];
    int dice1 = number_on_dice();
    int dice2 = number_on_dice();
    cur_player.increment_position(dice1 + dice2);
    GameMove return_obj{cur_position, dice1, dice2, cur_player.get_position()};
    return return_obj;
}

int Game::number_on_dice() {
    srand(time(nullptr));
    return rand() % 6 + 1;
}

int Game::next_turn() {
    // TODO: make it
    cur_position++;
    cur_position %= (int) players.size();
    return cur_position;
}