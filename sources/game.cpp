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
    cur_player_id = 0;
    feel_game_fields();
}

void Game::add_player(sf::Sprite sprite, std::string name) {
    Player player(std::move(sprite), std::move(name), settings.get_money_for_game_start(), 0, 0);
    players.push_back(player);
}

const std::vector<Player> Game::get_players() const {
    return players;
}

void Game::feel_game_fields() {
    game_fields.push_back(new Start(settings.get_bonus_for_visit_start()));
    game_fields.push_back(new Street("Buford village", 60, {2, 10, 30, 90, 160, 250}, 50, 50, 30, 1));
    game_fields.push_back(new CommunityChest());
    game_fields.push_back(new Street("Stonington village", 60, {4, 20, 60, 180, 320, 450}, 50, 50, 30, 1));
    game_fields.push_back(new Tax(200));
    game_fields.push_back(new Station("Porshe", 200, {25, 50, 100, 200}, 100, 9));
    game_fields.push_back(new Street("Mont-Saint Michel", 100, {6, 30, 90, 270, 400, 550}, 50, 50, 50, 2));
    game_fields.push_back(new Chance());
    game_fields.push_back(new Street("Chateau d'If", 100, {6, 30, 90, 270, 400, 550}, 50, 50, 50, 2));
    game_fields.push_back(new Street("Hogwarts", 120, {8, 40, 100, 300, 450, 600}, 50, 50, 60, 2));
    game_fields.push_back(new Jail(settings.get_jail_price()));
    game_fields.push_back(new Street("Kawasaki town", 140, {10, 50, 150, 450, 625, 750}, 100, 100, 70, 3));
    game_fields.push_back(new Utility("Ice cream van", 150, {4, 10}, 75, 10));
    game_fields.push_back(new Street("Fukuoka town", 140, {10, 50, 150, 450, 625, 750}, 100, 100, 70, 3));
    game_fields.push_back(new Street("Kioto town", 160, {12, 60, 180, 500, 700, 900}, 100, 100, 80, 3));
    game_fields.push_back(new Station("BMW", 200, {25, 50, 100, 200}, 100, 9));
    game_fields.push_back(new Street("Khibiny", 180, {14, 70, 200, 550, 750, 950}, 100, 100, 90, 4));
    game_fields.push_back(new Chance());
    game_fields.push_back(new Street("Alps", 180, {14, 70, 200, 550, 750, 950}, 100, 100, 90, 4));
    game_fields.push_back(new Street("Patagonia", 200, {16, 80, 220, 600, 800, 1000}, 100, 100, 100, 4));
    game_fields.push_back(new Parking());
    game_fields.push_back(new Street("Fairytale forest", 220, {18, 90, 250, 700, 875, 1050}, 150, 150, 110, 5));
    game_fields.push_back(new Street("Lake Geneva", 220, {18, 90, 250, 700, 875, 1050}, 150, 150, 110, 5));
    game_fields.push_back(new CommunityChest());
    game_fields.push_back(new Street("Meadow", 240, {20, 100, 300, 750, 925, 1100}, 150, 150, 120, 5));
    game_fields.push_back(new Station("Tesla", 200, {25, 50, 100, 200}, 100, 9));
    game_fields.push_back(new Street("Surfer's cove", 260, {22, 110, 330, 800, 975, 1150}, 150, 150, 130, 6));
    game_fields.push_back(new Street("Maldives", 260, {22, 110, 330, 800, 975, 1150}, 150, 150, 130, 6));
    game_fields.push_back(new Utility("Laundromat", 150, {4, 10}, 75, 10));
    game_fields.push_back(new Street("Bali", 280, {24, 120, 360, 850, 1025, 1200}, 150, 150, 140, 6));
    game_fields.push_back(new GoToJail());
    game_fields.push_back(new Street("Aqua park resort", 300, {26, 130, 390, 900, 1100, 1275}, 200, 200, 150, 7));
    game_fields.push_back(new Street("Himeji castle", 300, {26, 130, 390, 900, 1100, 1275}, 200, 200, 150, 7));
    game_fields.push_back(new CommunityChest());
    game_fields.push_back(new Street("Torii", 320, {28, 150, 450, 1000, 1200, 1400}, 200, 200, 160, 7));
    game_fields.push_back(new Station("Audi", 200, {25, 50, 100, 200}, 100, 9));
    game_fields.push_back(new Chance());
    game_fields.push_back(new Street("Fortuna valley", 350, {35, 175, 500, 1100, 1300, 1500}, 200, 200, 175, 8));
    game_fields.push_back(new Tax(100));
    game_fields.push_back(new Street("Paradise island", 400, {50, 200, 600, 1400, 1700, 2000}, 200, 200, 200, 8));
}

void Game::start_game() {
    is_game_started = true;

    srand(time(nullptr));
    auto rd = std::random_device{};
    auto rng = std::default_random_engine{rd()};
    std::shuffle(std::begin(players), std::end(players), rng);
    cur_player_id = 0;
}

GameMove Game::player_move() {
    if (!is_game_started) {
        throw std::runtime_error("Game is not started");
    }
    if (is_player_roll_dice) {
        throw std::runtime_error("Player already roll dice");
    }

    int dice1 = number_on_dice();
    int dice2 = number_on_dice();

    if (dice1 != dice2) {
        is_player_roll_dice = true;
    }

    GameMove return_obj;
    auto player = players[cur_player_id];
    return_obj.player_id = cur_player_id;
    return_obj.old_position = player.get_position();
    return_obj.number_on_dice1 = dice1;
    return_obj.number_on_dice2 = dice2;
    player.increment_position(dice1 + dice2);
    return_obj.new_position = player.get_position();
    players[cur_player_id] = player;

    auto field = game_fields[player.get_position()];
    auto field_type = field->get_type();
    if (field_type == FieldTypes::START or field_type == FieldTypes::PARKING or field_type == FieldTypes::JAIL) {
        return_obj.funcs = GameFieldTypes::DO_NOTHING;
        if (is_player_roll_dice) {
            is_player_do_move = true;
        }
    } else if (field_type == FieldTypes::TAX) {
        return_obj.funcs = GameFieldTypes::PAY_BANK;
        return_obj.amount_to_pay = ((Tax &) field).get_price();
    } else if (field_type == FieldTypes::CHANCE or field_type == FieldTypes::COMMUNITY_CHEST) {
        return_obj.funcs = GameFieldTypes::DRAW_CARD;
    } else if (field_type == FieldTypes::GO_TO_JAIL) {
        return_obj.funcs = GameFieldTypes::GO_TO_JAIL;
    } else {
        auto profitable_field = dynamic_cast<ProfitableField *>(game_fields[player.get_position()]);
        if (profitable_field->get_owner() == nullptr) {
            return_obj.funcs = GameFieldTypes::YOU_CAN_BUY;
            return_obj.field_to_buy = profitable_field;
        } else if (profitable_field->get_owner()->get_name() == players[cur_player_id].get_name()) {
            return_obj.funcs = GameFieldTypes::DO_NOTHING;
            if (is_player_do_move) {
                is_player_do_move = true;
            }
        } else {
            int user_id = -1;
            for (int i = 0; i < (int) players.size(); ++i) {
                if (players[i].get_name() == profitable_field->get_owner()->get_name()) {
                    user_id = i;
                    break;
                }
            }
            if (user_id == -1) {
                throw std::runtime_error("Invalid user id");
            }

            return_obj.funcs = GameFieldTypes::PAY_PLAYER;
            return_obj.player_to_pay = user_id;
            return_obj.amount_to_pay = profitable_field->get_rent();
        }
    }

    return return_obj;
}

bool Game::get_is_player_do_move() const {
    return is_player_do_move;
}

bool Game::get_is_player_roll_dice() const {
    return is_player_roll_dice;
}

std::vector<Field*> Game::get_fields() const {
    return game_fields;
}

int Game::number_on_dice() {
    return rand() % 6 + 1;
}

int Game::next_turn() {
    if (!is_game_started) {
        throw std::runtime_error("Game is not started");
    }

    if (is_player_do_move) {
        cur_player_id++;
        cur_player_id %= (int) players.size();
        is_player_do_move = false;
        is_player_roll_dice = false;
    }
    return cur_player_id;
}

Game &Game::operator=(const Game &other) {
    if (this == &other) {
        return *this;
    }
    cur_player_id = other.cur_player_id;
    game_fields = other.game_fields;
    players = other.players;
    settings = GameSettings::getInstance();
    is_game_started = other.is_game_started;
    is_player_do_move = other.is_player_do_move;

    return *this;
}

int Game::get_cur_player_id() const {
    return cur_player_id;
}

void Game::give_up() {
    if (!is_game_started) {
        throw std::runtime_error("Game is not started");
    }
    players.erase(players.begin() + cur_player_id);
    cur_player_id %= (int) players.size();
}


bool Game::pay_player(int player_id, int amount) {
    if (!is_game_started) {
        throw std::runtime_error("Game is not started");
    }
    if (player_id < 0 || player_id >= (int) players.size()) {
        throw std::runtime_error("Invalid player id");
    }
    if (amount < 0) {
        throw std::runtime_error("Invalid amount");
    }
    if (players[cur_player_id].get_money() < amount) {
        return false;
    }

    players[cur_player_id].set_money(players[cur_player_id].get_money() - amount);
    players[player_id].set_money(players[player_id].get_money() + amount);
    if (is_player_roll_dice) {
        is_player_do_move = true;
    }

    return true;
}

bool Game::pay_bank(int amount) {
    if (!is_game_started) {
        throw std::runtime_error("Game is not started");
    }
    if (amount < 0) {
        throw std::runtime_error("Invalid amount");
    }
    if (players[cur_player_id].get_money() < amount) {
        return false;
    }
    players[cur_player_id].set_money(players[cur_player_id].get_money() - amount);

    if (is_player_roll_dice) {
        is_player_do_move = true;
    }

    return true;
}

bool Game::go_to_jail() {
    if (!is_game_started) {
        throw std::runtime_error("Game is not started");
    }
    players[cur_player_id].set_position(10);

    if (is_player_roll_dice) {
        is_player_do_move = true;
    }
    return true;
}

bool Game::buy_field() {
    if (!is_game_started) {
        throw std::runtime_error("Game is not started");
    }
    if (is_player_do_move) {
        throw std::runtime_error("Player already do move");
    }

    auto player = players[cur_player_id];
    auto field = game_fields[player.get_position()];

    if (field->get_type() != FieldTypes::STREET and field->get_type() != FieldTypes::STATION and
        field->get_type() != FieldTypes::UTILITY) {
        throw std::runtime_error("Field is not profitable");
    }
    auto profitable_field = dynamic_cast<ProfitableField *> (field);

    if (profitable_field->get_owner() != nullptr) {
        throw std::runtime_error("Field already has owner");
    }

    if (player.get_money() < profitable_field->get_price()) {
        return false;
    }
    profitable_field->buy(player);
    player.add_field(*profitable_field);
    player.set_money(player.get_money() - profitable_field->get_price());
    players[cur_player_id] = player;
    game_fields[player.get_position()] = profitable_field;

    if (is_player_roll_dice) {
        is_player_do_move = true;
    }

    return true;
}

bool Game::set_field_on_auction() {
    // todo: do
    if (!is_game_started) {
        throw std::runtime_error("Game is not started");
    }
    if (is_player_do_move) {
        throw std::runtime_error("Player already do move");
    }

    if (is_player_roll_dice) {
        is_player_do_move = true;
    }
    return true;
}

bool Game::mortgage_field(int field_id) {
    // todo: проверка, что на других домах нет зданий
    if (!is_game_started) {
        return false;
    }

    auto player = players[cur_player_id];
    auto field = game_fields[field_id];
    if (field->get_type() != FieldTypes::STREET or field->get_type() != FieldTypes::STATION or
        field->get_type() != FieldTypes::UTILITY) {
        return false;
    }
    auto profitable_field = dynamic_cast<ProfitableField *>(field);

    if (profitable_field->get_owner()->get_name() != player.get_name()) {
        return false;
    }
    if (profitable_field->get_is_mortgaged()) {
        return false;
    }

    profitable_field->mortgage();
    player.set_money(player.get_money() + profitable_field->get_mortgage_price());
    players[cur_player_id] = player;
    game_fields[field_id] = profitable_field;
    return true;
}

bool Game::build_house(int field_id) {
    // todo: do
    if (!is_game_started) {
        throw std::runtime_error("Game is not started");
    }

    auto player = players[cur_player_id];
    auto field = game_fields[field_id];
    if (field->get_type() != FieldTypes::STREET) {
        throw std::runtime_error("Field is not street");
    }
    auto profitable_field = dynamic_cast<Street *>(field);

    if (profitable_field->get_owner()->get_name() != player.get_name()) {
        throw std::runtime_error("Player is not owner of this field");
    }
    return true;
}

bool Game::sell_house(int field_id) {
    // todo: do
    if (!is_game_started) {
        throw std::runtime_error("Game is not started");
    }

    auto player = players[cur_player_id];
    auto field = game_fields[field_id];

    if (field->get_type() != FieldTypes::STREET) {
        throw std::runtime_error("Field is not street");
    }

    auto profitable_field = dynamic_cast<Street *>(field);

    if (profitable_field->get_owner()->get_name() != player.get_name()) {
        throw std::runtime_error("Player is not owner of this field");
    }
    if (profitable_field->get_amount_of_houses() == 0) {
        throw std::runtime_error("Field has no houses");
    }
    return true;
}

Card Game::draw_card() {
    // todo: do
    if (!is_game_started) {
        throw std::runtime_error("Game is not started");
    }
    if (is_player_do_move) {
        throw std::runtime_error("Player already do move");
    }

    if (is_player_roll_dice) {
        is_player_do_move = true;
    }
    return {"Ага", 0, 0, 0, 0};
}