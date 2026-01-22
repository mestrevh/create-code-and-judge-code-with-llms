/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

struct Excavator {
    int id;
    int whistle_level;
    std::vector<int> relics_collected;
};

bool compareExcavators(const Excavator& a, const Excavator& b) {
    for (int i = 9; i >= 0; --i) {
        if (a.relics_collected[i] != b.relics_collected[i]) {
            return a.relics_collected[i] > b.relics_collected[i];
        }
    }
    return a.id < b.id;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Excavator> excavators(n);

    for (int i = 0; i < n; ++i) {
        excavators[i].id = i + 1;
        std::cin >> excavators[i].whistle_level;
        
        excavators[i].relics_collected.resize(10);
        int map_relics;
        for (int j = 0; j < 10; ++j) {
            std::cin >> map_relics;
            if ((j + 1) <= excavators[i].whistle_level) {
                excavators[i].relics_collected[j] = map_relics;
            } else {
                excavators[i].relics_collected[j] = 0;
            }
        }
    }

    std::sort(excavators.begin(), excavators.end(), compareExcavators);

    for (int i = 0; i < n; ++i) {
        std::cout << excavators[i].id << '\n';
    }

    return 0;
}
