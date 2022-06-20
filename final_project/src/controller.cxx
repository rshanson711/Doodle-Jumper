#include "controller.hxx"
#include "game_config.hxx"

Controller::Controller()
        : config_(Game_config()),
        view_(model_, config_)
{ }

void Controller::on_key(ge211::Key key) {
    if (key == ge211::Key::code(' ')) {
        model_.get_player().set_alive();
    }

    if (model_.get_player().is_alive()) {
        if (key.type() == ge211::Key::Type::left) {
            model_.get_player().change_velocity({-10, 0});
        }

        if (key.type() == ge211::Key::Type::right) {
            model_.get_player().change_velocity({10, 0});
        }
    }

    if (model_.is_game_over()) {
        if (key == ge211::Key::code('r')) {
            model_.start_new_game();
        }
    }
}

void Controller::on_frame(double dt) {
    model_.on_frame(dt);
}

View::Dimensions
Controller::initial_window_dimensions() const {
    return view_.initial_window_dimensions();
}

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}
