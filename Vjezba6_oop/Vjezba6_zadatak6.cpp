#include <cassert>
#include <iostream>
#include <string>

class RecentlyPlayed {
    std::string* songs;
    int kapacitet;
    int broj_spremljenih_naslova;
    int sljedeci;
public:
    bool provjera() {
        return kapacitet > 0;
    }

    RecentlyPlayed(int kapacitet) : songs(nullptr), kapacitet(kapacitet), broj_spremljenih_naslova(0), sljedeci(0) {
        assert(provjera());
        songs = new std::string[kapacitet];
    }

    RecentlyPlayed(const RecentlyPlayed& other) :  kapacitet(other.kapacitet), broj_spremljenih_naslova(other.broj_spremljenih_naslova), sljedeci(other.sljedeci){
        songs = new std::string[kapacitet];
        for (int i = 0; i < kapacitet; i++) {
            songs[i] = other.songs[i];
        }
    }

    ~RecentlyPlayed() {
        delete[] songs;
    }

    void play(std::string title) {
        songs[sljedeci] = title;

        if (broj_spremljenih_naslova < kapacitet) {
            broj_spremljenih_naslova++;
        }
        
        sljedeci = (sljedeci + 1) % kapacitet;
    }

    int size() {
        return broj_spremljenih_naslova;
    }

    int capacity() {
        return kapacitet;
    }

    std::string get(int i){
        assert(i >= 0 && i < broj_spremljenih_naslova);
        return songs[(sljedeci - 1 - i + kapacitet) % kapacitet];
    }

    void print() {
        for (int i = 0; i < broj_spremljenih_naslova; i++) {
            if (i > 0) {
                std::cout << ", ";
            }

            std::cout << get(i);
        }

        std::cout << '\n';
    }

};

int main()
{
    RecentlyPlayed recent(3);
    recent.play("Heroes");
    recent.play("Literary Mind");
    std::cout << recent.size() << ' ' << recent.capacity() << '\n';
    recent.play("Sports");
    recent.print();
    recent.play("Henry Don't Got Love");    
    recent.print();

    RecentlyPlayed copy = recent;        
    recent.play("Guided by Angels");
    recent.print();
    copy.print();
    std::cout << copy.get(0) << '\n';
    return 0;
}

/*
Ocekivani ispis:

    2 3
    Sports, Literary Mind, Heroes
    Henry Don't Got Love, Sports, Literary Mind
    Guided by Angels, Henry Don't Got Love, Sports
    Henry Don't Got Love, Sports, Literary Mind
    Henry Don't Got Love
*/
