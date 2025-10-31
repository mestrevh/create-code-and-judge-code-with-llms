/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>

const int M = 10007;

class HashTable {
    std::vector<std::pair<std::string, std::vector<int>>> table;

    int code(const std::string &word) {
        long long value = 0;
        for (char c : word) {
            value = value * 26 + (c - 'a');
        }
        return value % M;
    }

public:
    HashTable() : table(M) {}

    void insert(const std::string &word, int line) {
        int idx = code(word);
        while (table[idx].first != "" && table[idx].first != word) {
            idx = (idx + 1) % M;
        }
        table[idx].first = word;
        table[idx].second.push_back(line);
    }

    const std::vector<int>& find(const std::string &word) {
        int idx = code(word);
        while (table[idx].first != "") {
            if (table[idx].first == word) {
                return table[idx].second;
            }
            idx = (idx + 1) % M;
        }
        return std::vector<int>(); 
    }
};

int main() {
    std::string input;

    std::getline(std::cin, input);
    HashTable dictionary;
    int line_count = 1;

    while (std::getline(std::cin, input) && input != "$CONSULTAS") {
        std::istringstream ss(input);
        std::string word;
        while (ss >> word) {
            dictionary.insert(word, line_count);
        }
        line_count++;
    }

    while (std::getline(std::cin, input)) {
        auto occurrences = dictionary.find(input);
        std::cout << input << ":";
        if (!occurrences.empty()) {
            for (int line : occurrences) {
                std::cout << " " << line;
            }
        }
        std::cout << "\n";
    }
    return 0;
}
