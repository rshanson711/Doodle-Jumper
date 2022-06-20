#pragma once

#include "game_config.hxx"
#include <ge211.hxx>

class Platform : public ge211::Rect<int> {

public:
    /// Constructor
    Platform(Game_config const&);

    /// Member Functions
    Platform next(double dt, float vel, int x_value) const;

    void set_pos(int x, int y);

    void set_breakable(int i);

    void hit_platform();

    void break_platform();

    void set_hit(bool val);

    /// Get Functions
    ge211::Posn<int> get_pos() const;

    ge211::Dims<int> get_dims() const;

    bool is_hit() const;

    bool is_breakable() const;

    bool get_broken();

private:
    /// Member Variables
    Game_config config_;
    ge211::Dims<int> dims;
    bool hit;
    bool breakable;
    bool broken;
};