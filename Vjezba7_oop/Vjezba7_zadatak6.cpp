#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct WordCount {
    std::string word;
    int count;
};

std::string clean(const std::string& word) {
    std::string result;
    for (char c : word) {
        unsigned char uc = static_cast<unsigned char>(c);
        if (std::isalpha(uc)) {
            result += static_cast<char>(std::tolower(uc));
        }
    }
    return result;
}

int main() {
    std::ifstream in("tekst.txt");
    if (!in) {
        std::cout << "Ne mogu otvoriti tekst.txt\n";
        return 1;
    }

    std::map<std::string, int> freq;
    std::string raw;
    while (in >> raw) {
        std::string w = clean(raw);
        if (w.empty()) {
            continue;
        }
        ++freq[w];
    }

    std::cout << "razlicitih rijeci: " << freq.size() << "\n";

    auto it = freq.find("alice");
    int alice = (it != freq.end()) ? it->second : 0;
    std::cout << "alice: " << alice << "\n";

    std::vector<WordCount> v;
    v.reserve(freq.size());
    for (const auto& p : freq) {
        WordCount wc;
        wc.word = p.first;
        wc.count = p.second;
        v.push_back(wc);
    }

    std::sort(v.begin(), v.end(), [](const WordCount& a, const WordCount& b) {
        if (a.count != b.count) return a.count > b.count;
        return a.word < b.word;
        });

    for (std::size_t i = 0; i < v.size() && i < 5; ++i) {
        std::cout << v[i].word << ": " << v[i].count << "\n";
    }

    return 0;
}