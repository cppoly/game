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
    game_fields.push_back(Start(settings.get_bonus_for_visit_start()));
    game_fields.push_back(Street("Buford village", 60, {2, 10, 30, 90, 160, 250}, 50, 50, 30));
    game_fields.push_back(CommunityChest());
    game_fields.push_back(Street("Buford village", 60, {4, 20, 60, 180, 320, 450}, 50, 50, 30));
    game_fields.push_back(Tax(200));
    game_fields.push_back(Station("Porshe", 200, {25, 50, 100, 200}, 100));
    game_fields.push_back(Street("Buford village", 100, {6, 30, 90, 270, 400, 550}, 50, 50, 50));
    game_fields.push_back(Chance());
    game_fields.push_back(Street("Buford village", 100, {6, 30, 90, 270, 400, 550}, 50, 50, 50));
    game_fields.push_back(Street("Buford village", 120, {8, 40, 100, 300, 450, 600}, 50, 50, 60));
    game_fields.push_back(Jail(settings.get_jail_price()));
    game_fields.push_back(Street("Buford village", 140, {10, 50, 150, 450, 625, 750}, 100, 100, 70));
    game_fields.push_back(Utility("Electricity", 150, {4, 10}, 75));
    game_fields.push_back(Street("Buford village", 140, {10, 50, 150, 450, 625, 750}, 100, 100, 70));
    game_fields.push_back(Street("Buford village", 160, {12, 60, 180, 500, 700, 900}, 100, 100, 80));
    game_fields.push_back(Station("Ferrari", 200, {25, 50, 100, 200}, 100));
    game_fields.push_back(Street("Buford village", 180, {14, 70, 200, 550, 750, 950}, 100, 100, 90));
    game_fields.push_back(Chance());
    game_fields.push_back(Street("Buford village", 180, {14, 70, 200, 550, 750, 950}, 100, 100, 90));
    game_fields.push_back(Street("Buford village", 200, {16, 80, 220, 600, 800, 1000}, 100, 100, 100));
    game_fields.push_back(Parking());
    game_fields.push_back(Street("Buford village", 220, {18, 90, 250, 700, 875, 1050}, 150, 150, 110));
    game_fields.push_back(Street("Buford village", 220, {18, 90, 250, 700, 875, 1050}, 150, 150, 110));
    game_fields.push_back(CommunityChest());
    game_fields.push_back(Street("Buford village", 240, {20, 100, 300, 750, 925, 1100}, 150, 150, 120));
    game_fields.push_back(Station("Lamborghini", 200, {25, 50, 100, 200}, 100));
    game_fields.push_back(Street("Buford village", 260, {22, 110, 330, 800, 975, 1150}, 150, 150, 130));
    game_fields.push_back(Street("Buford village", 260, {22, 110, 330, 800, 975, 1150}, 150, 150, 130));
    game_fields.push_back(Utility("Water", 150, {4, 10}, 75));
    game_fields.push_back(Street("Buford village", 280, {24, 120, 360, 850, 1025, 1200}, 150, 150, 140));
    game_fields.push_back(GoToJail());
    game_fields.push_back(Street("Buford village", 300, {26, 130, 390, 900, 1100, 1275}, 200, 200, 150));
    game_fields.push_back(Street("Buford village", 300, {26, 130, 390, 900, 1100, 1275}, 200, 200, 150));
    game_fields.push_back(CommunityChest());
    game_fields.push_back(Street("Buford village", 320, {28, 150, 450, 1000, 1200, 1400}, 200, 200, 160));
    game_fields.push_back(Station("Bugatti", 200, {25, 50, 100, 200}, 100));
    game_fields.push_back(Chance());
    game_fields.push_back(Street("Buford village", 350, {35, 175, 500, 1100, 1300, 1500}, 200, 200, 175));
    game_fields.push_back(Tax(100));
    game_fields.push_back(Street("Buford village", 400, {50, 200, 600, 1400, 1700, 2000}, 200, 200, 200));
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