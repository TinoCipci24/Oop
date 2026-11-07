#pragma once

#include <string>

class Enemy {
    std::string ime;
    int snaga;

public:
    Enemy(const std::string& ime, int snaga);

    const std::string& name() const;
    int strength() const;
};