#include <iostream>

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

    void set(int i,int j,char ch) {
        if (i > 0 && i < x - 1 &&j > 0 && j < y - 1) {
            data[i * y + j] = ch;
        }
    }
    
    char get(int i,int j) {
        if (i >= 0 && i < x && j >= 0 && j < y) {
            return data[i * y + j];
        }
        else {
            return NULL;
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

int main()
{
    Board b(4, 8, '#');
    b.set(1, 2, '@');
    Board copy = b;         
    copy.set(2, 5, '*');
    copy.set(0, 0, '!');    
    b.print();
    copy.print();
    std::cout << copy.rows() << ' ' << copy.cols() << ' '
        << copy.get(2, 5) << '\n';
    return 0;
}

