#pragma once

#include <string>

class Weapon {
    std::string ime;

public:
    Weapon(const std::string& ime);

    const std::string& name() const;
};