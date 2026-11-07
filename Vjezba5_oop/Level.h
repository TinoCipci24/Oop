#pragma once

#include <vector>

#include "Enemy.h"
#include "Weapon.h"

class Level {
    std::vector<Enemy> enemies;
    std::vector<Weapon> weapons;

public:
    Level();
    Level(const std::vector<Enemy>& enemies,const std::vector<Weapon>& weapons);

    int enemy_count() const;
    int weapon_count() const;

    void add_enemy(const Enemy& enemy);
    void add_weapon(const Weapon& weapon);
};