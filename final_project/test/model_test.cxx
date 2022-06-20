#include "model.hxx"
#include <catch.hxx>
#include <iostream>

// Game config initializer
Game_config const config;

TEST_CASE("Starting Game Initiation Test")
{
    // Initialize model
    Model m(config);

    // One frame per second
    double const dt = 1;
    // Clear platforms
    m.clear_platforms();

    // Get positions of starting platform and player
    ge211::Posn<int> posn = m.get_player().get_pos();
    ge211::Posn<int> p_posn = m.get_starting_platform().get_pos();
    // Checks if starting positions are correct
    CHECK(posn.x == config.spawn_pos.x);
    CHECK(posn.y == config.spawn_pos.y);
    CHECK(p_posn.x == config.starting_platform_pos.x);
    CHECK(p_posn.y == config.starting_platform_pos.y);
    // Checks other relevant starting information
    CHECK(!m.get_player().is_alive());
    CHECK(!m.is_hit());
    CHECK(!m.is_game_over());
    CHECK(!m.is_new_game());
    CHECK(m.get_player().get_score() == 0);
    // Replicates pressing space bar to start game
    m.get_player().set_alive();
    CHECK(m.get_player().is_alive());
    // Checks if starting game initialization occurred but no time as passed
    CHECK(!m.is_hit());
    CHECK(!m.is_game_over());
    // Moves the game 1 frame
    m.on_frame(dt);
    // Check if velocity constant is applied
    CHECK(m.get_player().get_vel().height == 10);
    CHECK(m.get_player().get_pos().y == 850);
    // Move another frame
    m.on_frame(dt);
    // Checks if player correctly bounced off of starter platform
    // and if bounce() function worked correctly to apply correct velocity
    // after 1 second.
    CHECK(m.is_hit());
    CHECK(m.get_player().get_vel().height == -540);
    // Moves 54 frames to check if velocity of player is 0
    for (int i = 0; i < 54; i++) {
        m.on_frame(dt);
    }
    CHECK(m.get_player().get_vel().height == 0);
    CHECK(m.get_player().get_pos().x == 250);



}

TEST_CASE("Platform Collision Tests")
{
    Model m(config);
    double const dt = 1;
    int count = 0;

    m.get_player().set_alive();
    m.on_frame(dt);
    m.on_frame(dt);

    //BRING NORMAL PLAT
    m.test_move_normal_platform(100, 800);

    m.get_player().set_pos(110, 730);
    m.get_player().set_velocity({0, 20});
    m.on_frame(dt);
    m.on_frame(dt);
    CHECK(m.get_player().get_score() == 100);
    for (Platform plat : m.get_platforms()) {
        if (plat.is_hit()) {
            count++;
        }
    }
    CHECK(count == 1);

    //SEND NORMAL AWAY, BRING BROKEN
    m.test_move_normal_platform(100, 300);
    m.guarantee_broken_platform();
    m.test_move_broken_platform(100, 800);

    m.get_player().set_pos(110, 750);
    m.get_player().set_velocity({0, 50});
    m.on_frame(dt);
    m.on_frame(dt);
    CHECK(m.get_player().get_score() == 100);

    ge211::Dims<float> expected_vel = {0, 70};
    CHECK(m.get_player().get_vel() == expected_vel);

    for (Platform plat : m.get_platforms()) {
        if (plat.get_broken()) {
            count++;
        }
    }
    CHECK(count == 2);
}

TEST_CASE("Scroll Testing")
{
    Model m(config);

    double const dt = 1;

    // Sets player at scroll limit height and applies an upward velocity
    m.get_player().set_alive();
    m.get_player().set_pos(250, 500);
    m.get_player().set_velocity({0, -100});

    // Creates an array of y values of platforms
    float platform_pos[9] = { };
    for (Platform platform : m.get_platforms()) {
        int i = 0;
        platform_pos[i] = platform.get_pos().y;
        i++;
    }
    // Moves game by one frame
    m.on_frame(dt);

    // Checks if positions of platforms moved accordingly
    int count = 0;
    for (Platform platform : m.get_platforms()) {
        for (float i : platform_pos) {
            if ((platform.get_pos().y - i) == 100) {
                count += 1;
            }
        }
    }
    CHECK(count == 9);
}

TEST_CASE("Repositioning Platform Test")
{
    Model m(config);
    double const dt = 1;

    m.get_player().set_alive();
    // Sets player at scroll limit height and applies an upward velocity
    m.get_player().set_pos(250, 500);
    m.get_player().set_velocity({0, -60});

    // Copies y/x position of first platform
    int y = m.get_platforms().at(0).get_pos().y;
    int x = m.get_platforms().at(0).get_pos().x;
    // Moves game by frames
    for (int i=0; i < 3; i ++) {
        m.on_frame(dt);
    }
    m.on_frame(dt);
    m.on_frame(dt);
    m.on_frame(dt);
    // Copies y/x position after repositioning of platform
    int y2 = m.get_platforms().at(0).get_pos().y;
    int x2 = m.get_platforms().at(0).get_pos().x;
    // Checks if previous position after reaching bottom limit
    // is different from original position and if the block got set
    // to the top of the screen.
    CHECK(y != y2);
    CHECK(y2 == 10);
    // Checks if x value changed to random value
    CHECK(x != x2);

}

TEST_CASE("Death Sequence Test")
{
    Model m(config);
    double const dt = 1;

    // CLEARS PLATFORMS
    m.clear_platforms();

    //SET PLAYER ALIVE AND GIVE 100 POINTS
    m.get_player().set_alive();
    m.get_player().increment_score();

    //BOUNCE PLAYER OFF STARTING PLATFORM
    m.on_frame(dt);
    m.on_frame(dt);
    CHECK(m.is_hit());

    //SEND PLAYER DOWN FOR DEATH AT BOTTOM OF SCREEN
    m.get_player().set_velocity({0, 100});
    m.get_player().set_pos(100, 900);
    m.on_frame(dt);
    m.on_frame(dt);

    //CHECK FOR DEATH
    //CHECK(!m.get_player().is_alive());
    CHECK(m.get_player().get_score() == 100);
    CHECK(m.is_game_over());

    //CHECK NEW GAME INITIALIZATION
    m.start_new_game();
    m.on_frame(dt);
    m.on_frame(dt);
    CHECK(!m.get_player().is_alive());
    CHECK(m.get_player().get_score() == 0);
    CHECK(!m.is_game_over());
    CHECK(m.get_player().get_pos() == config.spawn_pos);
    CHECK(!m.is_hit());
    CHECK(m.get_starting_platform().get_pos() == config.starting_platform_pos);
}