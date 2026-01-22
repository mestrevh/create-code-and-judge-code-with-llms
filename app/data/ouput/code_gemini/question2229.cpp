/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<std::string, int> arrival_pos;
    for (int i = 1; i <= 5; ++i) {
        std::string name;
        std::cin >> name;
        arrival_pos[name] = i;
    }

    std::string table[6];
    table[1] = "Princesa";

    std::vector<std::string> even_arrivals;
    std::vector<std::string> odd_arrivals;
    std::vector<std::string> guests = {"Mario", "Toad", "Luigi", "Yoshi"};

    for (const std::string& guest : guests) {
        if (arrival_pos[guest] % 2 == 0) {
            even_arrivals.push_back(guest);
        } else {
            odd_arrivals.push_back(guest);
        }
    }

    std::map<std::string, int> priority;
    priority["Mario"] = 4;
    priority["Toad"] = 3;
    priority["Luigi"] = 2;
    priority["Yoshi"] = 1;

    auto comparator = [&](const std::string& a, const std::string& b) {
        return priority[a] > priority[b];
    };

    std::sort(even_arrivals.begin(), even_arrivals.end(), comparator);
    std::sort(odd_arrivals.begin(), odd_arrivals.end(), comparator);

    if (!even_arrivals.empty()) {
        table[2] = even_arrivals[0];
    }
    if (even_arrivals.size() > 1) {
        table[4] = even_arrivals[1];
    }

    if (!odd_arrivals.empty()) {
        table[3] = odd_arrivals[0];
    }
    if (odd_arrivals.size() > 1) {
        table[5] = odd_arrivals[1];
    }

    for (int i = 1; i <= 5; ++i) {
        std::cout << table[i] << '\n';
    }

    return 0;
}
