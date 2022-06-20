#include "game_config.hxx"

Game_config::Game_config()
        : bounce_velocity {0, -550},
          platform_dims {75, 20},
          scene_dims {500, 1000},
          game_over_rect_w1_dims {300, 500},
          game_over_rect_b2_dims {280, 480},
          starting_platform_pos {225, 900},
          player_dims {20, 50},
          spawn_pos {250, 840},
          platform_y {800},
          scroll_height(500),
          score_increment(100),
          platform_spacing(100)

{ }
