#include <iostream>
#include <string>
#include <vector>

class Song {
public:
    std::string title;
    std::string artist;
    int seconds;

    Song(std::string t, std::string a, int s)
        : title(t), artist(a), seconds(s) {}
};

class Album {
    std::string title;
    int year;
    std::vector<Song> songs;

public:
    Album(std::string t, int y, Song first) : title(t), year(y) {
        songs.push_back(first);
    }

    bool add(Song s) {
        for (auto pjesma : songs) {
            if (pjesma.title == s.title) {
                return false;
            }
        }
        songs.push_back(s);
        return true;
    }

    int duration() const {
        int total = 0;
        for (auto pjesma : songs) {
            total += pjesma.seconds;
        }
        return total;
    }

    void print() const {
        int broj_pjesama = songs.size();
        int ukp = duration();
        int minute = ukp / 60;
        int sekunde = ukp % 60;

        std::cout << title << " (" << year << "), " << broj_pjesama << " pjesme, " << minute << ":" << sekunde << std::endl;
        for (size_t i = 0;i < broj_pjesama;i++) {
            std::cout << "  " << i + 1 << ". " << songs[i].title << std::endl;
        }
    }

};


int main()
{
    Album a("Sol Invictus", 2015, { "Sol Invictus", "Faith No More", 156 });
    a.add({ "Superhero", "Faith No More", 315 });
    a.add({ "Matador", "Faith No More", 368 });
    std::cout << a.add({ "Superhero", "Faith No More", 315 }) << '\n'; 
    a.print();
    return 0;
}

/*
Ocekivani ispis:

    0
    Sol Invictus (2015), 3 pjesme, 13:59
      1. Sol Invictus
      2. Superhero
      3. Matador
*/
