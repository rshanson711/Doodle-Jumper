#include "model.hxx"

Model::Model(Game_config const& config)
        : config_(),
          random_position_(0, (config.scene_dims.width - 75)),
          player_(config),
          platform_(config),
          starting_platform_(config),
          hit_(false),
          game_over_(false),
          new_game_(false),
          breakable_num(0, 10),
          x_values(0, (config.scene_dims.width - platform_.get_dims().width))
{
    int x;
    int y = config.platform_y;

    for (int i=0; i < 10; i++) {
        x = random_position_.next();
        Platform platform(config);
        platform.set_breakable(breakable_num.next());
        platform.set_pos(x, y);
        platforms_.push_back(platform);

        y -= config.platform_spacing;
    }

}

void Model::set_game_over() {
    player_.set_dead();
    game_over_ = true;
}

void
Model::start_new_game() {
    for (Platform& platform : platforms_) {
        platform.set_hit(false);
    }

    game_over_ = false;
    new_game_ = true;
}

void Model::test_move_normal_platform(int x, int y) {
    bool run = true;
    for (Platform& plat : platforms_) {
        if (!plat.is_breakable() && run) {
            plat.set_pos(x, y);
            run = false;
        }
    }
}

void Model::test_move_broken_platform(int x, int y) {
    bool run = true;
    for (Platform& plat : platforms_) {
        if (plat.is_breakable() && run) {
            plat.set_pos(x, y);
            run = false;
        }
    }
}

void Model::guarantee_broken_platform() {
    platforms_.at(8).set_breakable(10);
}

void
Model::on_frame(double dt)
{
    if (new_game_) {
        Player newplayer(config_);
        player_ = newplayer;
        hit_ = false;
        new_game_ = false;
        return;
    }

    if (player_.is_alive()) {
        Player nextplayer = player_.next(dt);

        // Starting platform check
        if (nextplayer.hits_platform(starting_platform_) && !hit_) {
            player_.bounce();
            hit_ = true;
        }

        // Continue scrolling if needed
        if (nextplayer.hits_scroll_height() &&
                nextplayer.get_vel().height < 0) {
            float playervel = nextplayer.get_vel().height;

            for (Platform& platform : platforms_) {
                platform = platform.next(dt, playervel, x_values.next());
            }
        }

        // Collision check
        if (player_.hits_any_platform(platforms_)) {
            player_.bounce();
        }

        // Constantly changes velocity to implement gravity
        player_.change_velocity(nextplayer.const_velocity_grab());

        if (nextplayer.get_pos().y > config_.scene_dims.height) {
            set_game_over();
            return;
        }

        player_ = player_.next(dt);
    }
}
