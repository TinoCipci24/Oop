#include "Weapon.h"

Weapon::Weapon(const std::string& ime): ime(ime) {
}

const std::string& Weapon::name() const {
    return ime;
}