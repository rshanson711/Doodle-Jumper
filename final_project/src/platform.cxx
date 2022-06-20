#include "platform.hxx"

Platform::Platform(Game_config const& config)
        : config_(config),
        dims(config.platform_dims),
        hit(false),
        breakable(false),
        broken(false)
{
    this->x = config.starting_platform_pos.x;
    this->y = config.starting_platform_pos.y;
}

void Platform::set_pos(int x, int y) {
    this->x = x;
    this->y = y;
}

void Platform::set_breakable(int i) {
    breakable = (i > 8);
}

ge211::Posn<int> Platform::get_pos() const {
    return {this->x, this->y};
}

ge211::Dims<int> Platform::get_dims() const {
    return dims;
}

bool Platform::is_hit() const {
    return hit;
}

bool Platform::is_breakable() const {
    return breakable;
}

void Platform::set_hit(bool val) {
    hit = val;
}


Platform Platform::next(double dt, float vel, int x_value) const {

    Platform result(*this);
    result.y -= (vel * dt);


    // IF BELOW BOTTOM OF WINDOW, MOVE TO TOP OFFSCREEN (OR ONSCREEN? TEST)
    if (result.y > config_.scene_dims.height) {
        result.y -= config_.scene_dims.height;
        result.x = x_value;
        result.hit = false;
        result.broken = false;
    }

    return result;
}

void Platform::hit_platform() {
    hit = true;
}

void Platform::break_platform() {
    broken = true;
}

bool Platform::get_broken() {
    return broken;
}