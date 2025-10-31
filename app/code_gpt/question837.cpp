/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main() {
    std::vector<int> speeds(5);
    for (int i = 0; i < 5; ++i) {
        std::cin >> speeds[i];
    }

    std::vector<std::pair<int, int>> indexed_speeds(5);
    for (int i = 0; i < 5; ++i) {
        indexed_speeds[i] = {speeds[i], i + 1};
    }

    std::sort(indexed_speeds.rbegin(), indexed_speeds.rend());

    for (int i = 0; i < 5; ++i) {
        std::cout << i + 1 << " - " << indexed_speeds[i].first << " km/h" << std::endl;
    }

    return 0;
}
