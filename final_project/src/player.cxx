#include "player.hxx"

static ge211::Posn<float> get_center(ge211::Posn<float> pos, ge211::Dims<int>
        dims) {
    float x = pos.x + (dims.width / 2);
    float y = pos.y + (dims.height / 2);
    return {x, y};
}

/// CONSTRUCTOR
Player::Player(Game_config const& config)
        : config_(config),
          dims(config.player_dims),
          pos(config.spawn_pos),
          velocity({0, 0}),
          bounce_velocity(config.bounce_velocity),
          center(get_center(pos, dims)),
          const_velocity({0,10}),
          score(0),
          live(false),
          at_height_limit(false)
{ }

ge211::Posn<int> Player::get_pos() const {
    int x = center.x - (dims.width / 2);
    int y = center.y - (dims.height / 2);
    return {x, y};
}

ge211::Dims<float> Player::get_vel() const {
    return velocity;
}

int Player::get_score() const {
    return score;
}

ge211::Dims<int> Player::get_dims() const {
    return dims;
}

bool Player::is_alive() const {
    return live;
}

void Player::set_alive() {
    live = true;
}

void Player::set_dead() {
    live = false;
}

void Player::set_pos(float x, float y) {
    pos = {x, y};
    center = {pos.x + (dims.width / 2), pos.y + (dims.height / 2)};
}

void Player::increment_score() {
    score += config_.score_increment;
}

Player Player::next(double dt) const {
    Player result(*this);
    result.center.x += (result.velocity.width * dt);
    result.pos.x = result.center.x - (result.dims.width / 2);

    if (!at_height_limit) {
        result.center.y += (result.velocity.height * dt);
        result.pos.y = result.center.y - (result.dims.height / 2);
    }

    return result;
}

void Player::bounce() {
    velocity = {velocity.width, bounce_velocity.height};
}

void Player::set_velocity(Velocity vel) {
    velocity = vel;
}

void Player::change_velocity(Velocity vel) {
    velocity += vel;
}

ge211::Dims<float>
Player::const_velocity_grab() {
    return const_velocity;
}

bool Player::hits_scroll_height() {
    bool result = ((pos.y == config_.scroll_height) ||
            (pos.y < config_.scroll_height));

    if (result) {
        at_height_limit = true;
    }
    return result;
}


bool
Player::hits_platform(Platform const& platform) const {
    if (velocity.height >= 0) {
        // Checks left side in between
        if (check_left_side(platform.get_pos().x, platform.get_dims().width) ||
            // Checks right side in between
            check_right_side(platform.get_pos().x, platform.get_dims().width)) {
            // Checks if bottom is below platform
            if ((pos.y + dims.height) >= platform.get_pos().y) {
                // Checks if bottom is above bottom of platform
                if ((pos.y + dims.height) < (platform.get_pos().y + platform.
                get_dims().height)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool
Player::hits_any_platform(std::vector<Platform>& platforms)
{
    for (Platform& platform : platforms){
        if (hits_platform(platform)) {
            // CHECK IF BREAKABLE PLATFORM
            if (platform.is_breakable()) {
                platform.break_platform();
                platform.hit_platform();
                return false;
            } else if (!platform.is_hit()) { //HANDLE SCORING
                increment_score();
            }

            platform.hit_platform();
            return true;
        }
    }
    return false;
}

bool Player::check_left_side(int plat_x, int plat_width) const {
    return ((plat_x <= pos.x) &&
           (pos.x <= (plat_x + plat_width)));
}

bool Player::check_right_side(int plat_x, int plat_width) const {
    return ((plat_x <= (pos.x + dims.width)) &&
            ((pos.x + dims.width) <= (plat_x + plat_width)));
}