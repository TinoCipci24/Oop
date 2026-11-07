#include "Enemy.h"

Enemy::Enemy(const std::string& ime, int snaga)
    : ime(ime), snaga(snaga) {
}

const std::string& Enemy::name() const {
    return ime;
}

int Enemy::strength() const {
    return snaga;
}