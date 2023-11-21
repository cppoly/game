#include "game.h"
#include <cstdlib>
#include <ctime>


Game::Game(int money_for_game_start, int money_for_win, int money_per_loop, int bonus_for_visit_start,
           bool is_free_parking, int jail_price, int seconds_per_turn) {
    settings.set_parameters(
            money_for_game_start,
            money_for_win,
            money_per_loop,
            bonus_for_visit_start,
            is_free_parking,
            jail_price,
            seconds_per_turn
    );
    feel_game_fields();
}

void Game::add_player(sf::Sprite sprite, std::string name) {
    Player player(sprite, name, settings.get_money_for_game_start(), 0, 0);
    players.push_back(player);
}

std::vector<Player> Game::get_players() const {
    return players;
}

void Game::feel_game_fields() {

}

void Game::start_game() {
    srand(time(nullptr));
    cur_player_id = 0;
}

GameMove Game::player_move() {
    Player cur_player = players[cur_player_id];
    int dice1 = number_on_dice();
    int dice2 = number_on_dice();
    cur_player.increment_position(dice1 + dice2);
    GameMove return_obj{cur_player_id, dice1, dice2, cur_player.get_position()};
    return return_obj;
}

int Game::number_on_dice() {
    return rand() % 6 + 1;
}

int Game::next_turn() {
    // TODO: make it
    cur_player_id++;
    cur_player_id %= (int) players.size();
    return cur_player_id;
}