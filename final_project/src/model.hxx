#pragma once

#include <ge211.hxx>
#include "game_config.hxx"
#include "player.hxx"
#include "platform.hxx"
#include <vector>

class Model
{

public:
    /// Constructor
    explicit Model(Game_config const& config = Game_config());

    /// Member Functions
    void on_frame(double dt);

    void set_game_over();

    void start_new_game();

    void clear_platforms() {
        platforms_.clear();
    }

    /// Get Functions
    Player& get_player() {
        return player_;
    }

    std::vector<Platform>
    get_platforms() {
        return platforms_;
    }

    Platform get_starting_platform() {
        return starting_platform_;
    }

    bool is_game_over() const {
        return game_over_;
    }

    bool is_hit() {
        return hit_;
    }

    bool is_new_game() {
        return new_game_;
    }

    /// Testing Functions
    void test_move_normal_platform(int x, int y);

    void test_move_broken_platform(int x, int y);

    void guarantee_broken_platform();

private:
    /// Member Variables
    Game_config config_;

    ge211::Random_source<int> random_position_;

    Player player_;

    Platform platform_;

    Platform starting_platform_;

    std::vector<Platform> platforms_;

    bool hit_;

    bool game_over_;

    bool new_game_;

    ge211::Random_source<int> breakable_num;

    ge211::Random_source<int> x_values;
};
