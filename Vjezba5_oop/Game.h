#pragma once

#include <string>

#include "Level.h"
#include "Player.h"

class Game {
    std::string title;
    Player player;
    Level level;
public:
    Game(const std::string& game_title, const std::string& player_name);
    Game(const std::string& game_title,const Player& player_value,const Level& level_value);

    void print() const;
};