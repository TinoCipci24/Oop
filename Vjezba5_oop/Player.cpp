#include "Player.h"

#include <iostream>

Player::Player(const std::string& ime, int level): ime(ime), level(level) {}

void Player::print() const {
    std::cout << "Ime: " << ime << std::endl;
    std::cout << "Level: " << level << std::endl;
}

const std::string& Player::name() const {
    return ime;
}

int Player::level_number() const {
    return level;
}