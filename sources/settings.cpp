#include "settings.h"

GameSettings &GameSettings::getInstance() {
    static GameSettings instance;
    return instance;
}

GameSettings::GameSettings() = default;

void GameSettings::set_parameters(
        int moneyForGameStart,
        int moneyForWin,
        int moneyPerLoop,
        int bonusForVisitStart,
        bool isFreeParking,
        int jailPrice,
        int secondsPerTurn
) {
    this->money_for_game_start = moneyForGameStart;
    this->money_for_win = moneyForWin;
    this->money_per_loop = moneyPerLoop;
    this->bonus_for_visit_start = bonusForVisitStart;
    this->is_free_parking = isFreeParking;
    this->jail_price = jailPrice;
    this->seconds_per_turn = secondsPerTurn;
}

int GameSettings::get_money_for_game_start() const {
    return money_for_game_start;
}

int GameSettings::get_money_for_win() const {
    return money_for_win;
}

int GameSettings::get_money_per_loop() const {
    return money_per_loop;
}

int GameSettings::get_bonus_for_visit_start() const {
    return bonus_for_visit_start;
}

bool GameSettings::get_is_free_parking() const {
    return is_free_parking;
}

int GameSettings::get_jail_price() const {
    return jail_price;
}

int GameSettings::get_seconds_per_turn() const {
    return seconds_per_turn;
}