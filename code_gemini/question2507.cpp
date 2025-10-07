/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x;
    std::cin >> x;

    std::vector<std::pair<int, std::string>> throwers(x);
    std::vector<std::pair<int, std::string>> receivers(x);

    for (int i = 0; i < x; ++i) {
        std::cin >> throwers[i].second >> throwers[i].first;
    }

    for (int i = 0; i < x; ++i) {
        std::cin >> receivers[i].second >> receivers[i].first;
    }

    std::sort(throwers.begin(), throwers.end());
    
    std::sort(receivers.begin(), receivers.end(), [](const auto& a, const auto& b) {
        return a.first > b.first;
    });

    std::map<std::string, std::string> cycle_map;
    for (int i = 0; i < x; ++i) {
        cycle_map[throwers[i].second] = receivers[i].second;
    }

    std::string current_thrower = throwers.back().second;

    for (int i = 0; i < x; ++i) {
        std::string next_person = cycle_map[current_thrower];
        std::cout << current_thrower << " para " << next_person << '\n';
        current_thrower = next_person;
    }

    std::cout << "I am anything but a dropper" << '\n';

    return 0;
}
