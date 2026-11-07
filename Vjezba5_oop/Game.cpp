#include "Game.h"

#include <iostream>

Game::Game(const std::string& game_title, const std::string& player_name) : title(game_title), player(player_name, 1), level() {}

Game::Game(const std::string& game_title, const Player& player_value,const Level& level_value) : title(game_title), player(player_value), level(level_value) {}

void Game::print() const {
    std::cout << title << std::endl;
    std::cout << "Igrac: " << player.name() << std::endl;
    std::cout << "Level: neprijatelja " << level.enemy_count() << ", oruzja " << level.weapon_count() << std::endl;
}