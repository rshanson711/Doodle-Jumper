#pragma once


#include "game_config.hxx"
#include "platform.hxx"
#include <ge211.hxx>


class Player
{
public:
    /// CONSTRUCTOR
    Player(Game_config const&);

    using Position = ge211::Posn<float>;

    using Velocity = ge211::Dims<float>;

    /// PUBLIC METHODS
    /// Get Functions
    ge211::Posn<int> get_pos() const;

    Velocity get_vel() const;

    int get_score() const;

    ge211::Dims<int> get_dims() const;

    bool is_alive() const;

    /// Member Functions
    void set_alive();

    void set_dead();

    void set_pos(float x, float y);

    void increment_score();

    Player next(double dt) const;

    void bounce();

    void set_velocity(Velocity);

    void change_velocity(Velocity);

    Velocity const_velocity_grab();

    bool hits_scroll_height();

    bool hits_platform(Platform const&) const;

    bool hits_any_platform(std::vector<Platform>&);

    bool check_left_side(int plat_x, int plat_width) const;

    bool check_right_side(int plat_x, int plat_width) const;

private:
    /// Member Variables
    Game_config config_;
    ge211::Dims<int> dims;
    Position pos;
    Velocity velocity;
    Velocity bounce_velocity;
    Position center;
    Velocity const_velocity;
    int score;
    bool live;
    bool at_height_limit;
};