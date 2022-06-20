#pragma once

#include <ge211.hxx>

struct Game_config
{
    Game_config();

    using Position = ge211::Posn<int>;

    using Velocity = ge211::Dims<float>;

    using Dimension = ge211::Dims<int>;

    Velocity bounce_velocity;

    Dimension platform_dims;

    Dimension scene_dims;

    Dimension game_over_rect_w1_dims;

    Dimension game_over_rect_b2_dims;

    Position starting_platform_pos;

    Dimension player_dims;

    Position spawn_pos;

    int platform_y;

    int scroll_height;

    int score_increment;

    int platform_spacing;

};