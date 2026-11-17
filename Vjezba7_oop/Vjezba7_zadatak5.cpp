#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Vec2 {
    int x;
    int y;

    Vec2& operator+=(const Vec2& other) {
        x = x + other.x;
        y = y + other.y;
        return *this;
    }

    Vec2& operator-=(const Vec2& other) {
        x = x - other.x;
        y = y - other.y;
        return *this;
    }
};

Vec2 operator+(Vec2 a, const Vec2& b) {
    a += b;
    return a;
}

Vec2 operator-(Vec2 a, const Vec2& b) {
    a -= b;
    return a;
}

Vec2 operator*(const Vec2& v, int broj) {
    Vec2 rezultat = { v.x * broj, v.y * broj };
    return rezultat;
}

Vec2 operator*(int broj, const Vec2& v) {
    return v * broj;
}

bool operator==(const Vec2& a, const Vec2& b) {
    return a.x == b.x && a.y == b.y;
}

bool operator!=(const Vec2& a, const Vec2& b) {
    return !(a == b);
}

std::ostream& operator<<(std::ostream& os, const Vec2& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

struct Enemy {
    std::string ime;
    Vec2 polozaj;
};

class InRange {
    Vec2 srediste;
    int domet;
public:
    InRange(Vec2 srediste, int domet) : srediste(srediste), domet(domet) {}

    bool operator()(const Enemy& e) const {
        int dx = e.polozaj.x - srediste.x;
        int dy = e.polozaj.y - srediste.y;
        return (dx * dx + dy * dy) <= (domet * domet);
    }
};

int main()
{
    std::vector<Enemy> enemies = {
        {"Goblin", {2, 2}}, {"Troll", {6, 1}}, {"Bat", {3, 5}},
        {"Ghost", {0, 0}}, {"Slime", {7, 7}}
    };
    Vec2 player{ 3, 3 };

    InRange near(player, 2);                                           
    std::cout << near(enemies[0]) << ' ' << near(enemies[1]) << '\n';   

    int brojac = std::count_if(enemies.begin(), enemies.end(), near);
    std::cout << brojac << '\n';

    int range = 2;
    brojac = std::count_if(enemies.begin(), enemies.end(), [player, range](const Enemy& e) {
        int dx = e.polozaj.x - player.x;
        int dy = e.polozaj.y - player.y;
        return (dx * dx + dy * dy) <= range * range;
    });
    std::cout << brojac << '\n';

    return 0;
}

/*
Ocekivani ispis:

    1 0
    2
    2
*/
