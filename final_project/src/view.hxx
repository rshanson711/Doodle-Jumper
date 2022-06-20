#pragma once

#include "model.hxx"

class View
{
public:
    using Dimensions = ge211::Dims<int>;

    explicit View(Model& model, Game_config config);

    void draw(ge211::Sprite_set& set);

    Dimensions initial_window_dimensions() const;

    void set_score_indicator();

    void set_restart_text();

private:
    Model& model_;

    ge211::Font const sans30;

    ge211::Rectangle_sprite const player_sprite;

    ge211::Rectangle_sprite const platform_sprite;

    ge211::Rectangle_sprite const breakable_platform_sprite;

    ge211::Rectangle_sprite const game_over_rect_w1;

    ge211::Rectangle_sprite const game_over_rect_b2;

    ge211::Text_sprite score_sprite;

    ge211::Text_sprite restart_sprite;
};
