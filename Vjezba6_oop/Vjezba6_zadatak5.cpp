#include <iostream>
#include <string>
#include <vector>

class Board {
    char* data;
    int x;
    int y;
    char znak;
public:
    Board(int x, int y, char znak) : x(x), y(y), znak(znak) {
        data = new char[x * y];

        for (int i = 0;i < x;i++) {
            for (int j = 0;j < y;j++) {
                if (i == 0 || i == x - 1 || j == y - 1 || j == 0) {
                    data[i * y + j] = znak;
                }
                else {
                    data[i * y + j] = ' ';
                }
            }
        }
    };

    Board(const Board& other) : x(other.x), y(other.y), znak(other.znak) {
        data = new char[x * y];

        for (int i = 0;i < x * y;i++) {
            data[i] = other.data[i];
        }
    }

    ~Board() {
        delete[] data;
    }

    void set(int i, int j, char ch) {
        if (i > 0 && i < x - 1 && j > 0 && j < y - 1) {
            data[i * y + j] = ch;
        }
    }

    char get(int i, int j) const{
        if (i >= 0 && i < x && j >= 0 && j < y) {
            return data[i * y + j];
        }
        else {
            return '\0';
        }
    }

    int rows() {
        return x;
    }

    int cols() {
        return y;
    }

    void print() {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                std::cout << data[i * y + j];
            }
            std::cout << '\n';
        }
    }

};

class Enemy {
    std::string name;
    int x;
    int y;
    int health = 100;
public:
    Enemy(std::string n, int x, int y) : name(std::move(n)), x(x), y(y) {};
    
    std::string get_name() const {
        return name;
    }
    
    int get_x() const {
        return x;
    }
        
    int get_y() const {
        return y;
    }
        
    int get_health() const {
        return health;
    }
    
    bool is_alive() const {
        return health > 0;
    }
    
    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }
     
    void take_damage(int d) {
        if (d > 0 && is_alive()) {
            health = health - d;
        }
        if (health < 0) {
            health = 0;
        }
    }

};
    
class Level {
    int rows;
    int cols;
    std::vector<Enemy> enemies;
public:
    Level(int r,int c) : rows(r), cols(c){}
    
    bool add(Enemy e) {
        if (e.get_x() >= 0 && e.get_x() < cols && e.get_y() >= 0 && e.get_y() < rows) {
            enemies.push_back(e);
            return true;
        }
        else {
            return false;
        }
    }
    
    void step(int dx,int dy){
        for (Enemy& e : enemies) {
            int next_x = e.get_x() + dx;
            int next_y = e.get_y() + dy;
            if (next_x >= 0 && next_x< cols && next_y >= 0 && next_y < rows) {
                e.move(dx, dy);
            }
        }
    }
    
    void print() const{
        for (const Enemy& e : enemies) {
            std::cout << e.get_name() << " (" << e.get_x() << ", " << e.get_y() << ") " << e.get_health() << '\n';
        }
    }

    void draw() const {
        Board b(rows + 2, cols + 2, '#');
        for (const Enemy& e : enemies) {
            b.set(e.get_y() + 1, e.get_x() + 1, e.get_name()[0]);
        }
        b.print();
    }

};

int main()
{
    Level cave(5, 10);
    cave.add(Enemy("Gnome", 1, 1));
    std::cout << cave.add(Enemy("Troll", 8, 3))
        << cave.add(Enemy("Bat", 12, 2)) << '\n';
    cave.step(1, 1);
    cave.print();
    cave.draw();
    cave.step(1, 1);
    cave.print();
    return 0;
}

/*
Ocekivani ispis:

    10
    Gnome (2, 2) 100
    Troll (9, 4) 100
    Gnome (3, 3) 100
    Troll (9, 4) 100
*/
