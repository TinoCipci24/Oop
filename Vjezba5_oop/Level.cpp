#include "Level.h"

Level::Level()
    : enemies{ Enemy("Neprijatelj", 1) } {
}

Level::Level(
    const std::vector<Enemy>& enemies,
    const std::vector<Weapon>& weapons): enemies(enemies), weapons(weapons) 
    {
        if (this->enemies.empty()) {
            this->enemies.push_back(Enemy("Neprijatelj", 1));
    }
}

int Level::enemy_count() const {
    return static_cast<int>(enemies.size());
}

int Level::weapon_count() const {
    return static_cast<int>(weapons.size());
}

void Level::add_enemy(const Enemy& enemy) {
    enemies.push_back(enemy);
}

void Level::add_weapon(const Weapon& weapon) {
    weapons.push_back(weapon);
}