#define _CRT_SECURE_NO_WARNINGS  
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

class LogFile {
    std::FILE* f;
public:

    LogFile(const std::string& name) {
        f = std::fopen(name.c_str(), "a");
    }

    ~LogFile() {
        std::fclose(f);
    }

    LogFile(const LogFile&) = delete;

    void write(const std::string& line) {
        std::fputs(line.c_str(),f);
        std::fputs("\n",f);
    }
};

int log_songs(const std::vector<std::string>& titles) {
    LogFile file("played.log");
    int brojac = 0;
    for (const auto& pjesma : titles) {
        if (pjesma == "STOP") {
            break;
        }
        file.write(pjesma);
        brojac++;
    }
    return brojac;
}

int main()
{
    std::remove("played.log");
    int n = log_songs({ "Superhero", "Sports", "STOP", "Matador" });
    std::cout << n << '\n';
    std::cout << log_songs({ "One Rizla" }) << '\n';
    std::FILE* f = std::fopen("played.log", "r");
    char line[100];
    while (std::fgets(line, sizeof line, f))
        std::cout << line;
    std::fclose(f);
    return 0;
}

/*
Ocekivani ispis:

    2
    1
    Superhero
    Sports
    One Rizla
*/

