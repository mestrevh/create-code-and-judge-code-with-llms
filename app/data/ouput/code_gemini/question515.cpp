/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

const int M = 30011;

struct Entry {
    std::string key;
    std::vector<int> lines;
    bool occupied = false;
};

Entry hash_table[M];

unsigned int calculate_hash(const std::string& word) {
    unsigned long long hash_val = 0;
    for (char c : word) {
        hash_val = (hash_val * 26 + (c - 'a')) % M;
    }
    return static_cast<unsigned int>(hash_val);
}

void insert(const std::string& word, int line_num) {
    unsigned int index = calculate_hash(word);
    int i = 0;
    while (true) {
        int probe_index = (index + i) % M;

        if (!hash_table[probe_index].occupied) {
            hash_table[probe_index].key = word;
            hash_table[probe_index].lines.push_back(line_num);
            hash_table[probe_index].occupied = true;
            return;
        }

        if (hash_table[probe_index].key == word) {
            if (hash_table[probe_index].lines.empty() || hash_table[probe_index].lines.back() != line_num) {
                hash_table[probe_index].lines.push_back(line_num);
            }
            return;
        }

        i++;
    }
}

const std::vector<int>* find(const std::string& word) {
    unsigned int index = calculate_hash(word);
    int i = 0;
    while (i < M) {
        int probe_index = (index + i) % M;

        if (!hash_table[probe_index].occupied) {
            return nullptr;
        }

        if (hash_table[probe_index].key == word) {
            return &hash_table[probe_index].lines;
        }

        i++;
    }
    return nullptr;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;

    while (std::getline(std::cin, line) && line != "$TEXTO") {
    }

    int line_counter = 0;
    while (std::getline(std::cin, line) && line != "$CONSULTAS") {
        line_counter++;
        std::stringstream ss(line);
        std::string word;
        while (ss >> word) {
            insert(word, line_counter);
        }
    }

    std::string query_word;
    while (std::cin >> query_word) {
        std::cout << query_word << ":";
        const std::vector<int>* occurrences = find(query_word);
        if (occurrences != nullptr) {
            for (int line_num : *occurrences) {
                std::cout << " " << line_num;
            }
        }
        std::cout << "\n";
    }

    return 0;
}
