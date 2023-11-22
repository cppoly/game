#pragma once


class GameSettings {
public:
    static GameSettings &getInstance();

    void set_parameters(
            int moneyForGameStart,
            int moneyForWin,
            int moneyPerLoop,
            int bonusForVisitStart,
            bool isFreeParking,
            int jailPrice,
            int secondsPerTurn
    );

    int get_money_for_game_start() const;

    int get_money_for_win() const;

    int get_money_per_loop() const;

    int get_bonus_for_visit_start() const;

    bool get_is_free_parking() const;

    int get_jail_price() const;

    int get_seconds_per_turn() const;


private:
    GameSettings();

    int money_for_game_start{};
    int money_for_win{};
    int money_per_loop{};

    int bonus_for_visit_start{};

    bool is_free_parking{};
    int jail_price{};

    int seconds_per_turn{};
};
