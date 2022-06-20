#include "view.hxx"

/// Constants
static ge211::Color const player_color {255, 0, 0};
static ge211::Color const platform_color {0, 255, 0};
static ge211::Color const breakable_platform_color {255, 0, 0};
static ge211::Color const white_color {255, 255, 255};
static ge211::Color const black_color {0, 0, 0};
/// Constructor
View::View(Model& model, Game_config config)
        : model_(model),
          sans30("sans.ttf", 30),
          player_sprite({model_.get_player().get_dims().width,
                         model_.get_player().get_dims().height}, player_color),
          platform_sprite(config.platform_dims, platform_color),
          breakable_platform_sprite(config.platform_dims,
                                     breakable_platform_color),
          game_over_rect_w1(config.game_over_rect_w1_dims, white_color),
          game_over_rect_b2(config.game_over_rect_b2_dims, black_color)

{ }

void
View::draw(ge211::Sprite_set& set)
{
    set.add_sprite(player_sprite, model_.get_player().get_pos());
    if (!model_.is_hit()) {
        set.add_sprite(platform_sprite,
                       {model_.get_starting_platform().x, model_
                       .get_starting_platform().y});
    }
    for (Platform platform: model_.get_platforms()) {
        if (platform.is_breakable() && !platform.get_broken()) {
            set.add_sprite(breakable_platform_sprite, platform.get_pos());
        } else if (!platform.is_breakable()) {
            set.add_sprite(platform_sprite, platform.get_pos());
        }
    }

    set_score_indicator();

    if (!model_.is_game_over()) {
        set.add_sprite(score_sprite, {0, 900}, 1);
    } else if (model_.is_game_over()) {
        set.add_sprite(game_over_rect_w1, {100, 250}, 1);
        set.add_sprite(game_over_rect_b2, {110, 260}, 2);
        set.add_sprite(score_sprite, {125, 400}, 3);

        set_restart_text();
        set.add_sprite(restart_sprite, {125, 500}, 3);
    }
}

View::Dimensions
View::initial_window_dimensions() const
{
    return Dimensions{500, 1000};
}

void View::set_score_indicator() {
    ge211::Text_sprite::Builder builder(sans30);
    builder.color(white_color);

    builder << "Score: " << model_.get_player().get_score();
    score_sprite = builder.build();
}

void View::set_restart_text() {
    ge211::Text_sprite::Builder builder(sans30);
    builder.color(white_color);

    builder << "Press 'r' to restart";
    restart_sprite = builder.build();
}