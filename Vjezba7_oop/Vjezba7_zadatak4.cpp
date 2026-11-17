#include <iostream>
#include <string>
#include <vector>
#include <cassert>

class Inventory {
    std::vector<std::string> predmeti;
    int kapacitet;
public:
    Inventory(int kapacitet) : kapacitet(kapacitet) {}

    Inventory& operator+=(const std::string& naziv) {
        if (predmeti.size() < static_cast<std::size_t>(kapacitet)) {
            predmeti.push_back(naziv); 
        }
        return *this;
    }

    std::size_t size() const {
        return predmeti.size();
    }

    explicit operator bool() const {
        return !predmeti.empty();
    }

    std::string& operator[](std::size_t index) {
        return predmeti[index];
    }

    const std::string& operator[](std::size_t index) const {
        return predmeti[index];
    }
};
void show(const Inventory& inv)
{
    if (!inv) {
        std::cout << "prazno\n";
        return;
    }
    for (std::size_t i = 0; i < inv.size(); ++i)
        std::cout << i << ": " << inv[i] << '\n';
}

int main()
{
    Inventory bag(3);
    show(bag);

    bag += "mac";
    bag += "stit";
    bag += "kljuc";
    bag += "baklja";          // ne stane
    show(bag);

    bag[0] = "zlatni mac";
    std::cout << bag[0] << ' ' << bag.size() << '\n';

    if (bag)
        std::cout << "ima predmeta\n";
    return 0;
}

/*
Ocekivani ispis:

    prazno
    0: mac
    1: stit
    2: kljuc
    zlatni mac 3
    ima predmeta
*/
