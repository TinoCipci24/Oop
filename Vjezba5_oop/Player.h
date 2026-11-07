#pragma once

#include <string>

class Player {
    std::string ime;
    int level;
public:
    Player(const std::string& ime, int level);

    void print() const;

    const std::string& name() const;
    int level_number() const;
};