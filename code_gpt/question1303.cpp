/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

struct Scavenger {
    int index;
    int level;
    int relics[10];

    Scavenger(int idx, int lvl, const std::vector<int>& rel) : index(idx), level(lvl) {
        for (int i = 0; i < 10; ++i) {
            relics[i] = rel[i];
        }
    }

    bool operator<(const Scavenger& other) const {
        for (int i = 9; i >= 0; --i) {
            if (relics[i] != other.relics[i]) {
                return relics[i] > other.relics[i];
            }
        }
        return index < other.index;
    }
};

int main() {
    int N;
    std::cin >> N;
    std::vector<Scavenger> scavengers;

    for (int i = 0; i < N; ++i) {
        int level;
        std::cin >> level;
        std::vector<int> relics(10);
        for (int j = 0; j < 10; ++j) {
            std::cin >> relics[j];
        }
        scavengers.emplace_back(i + 1, level, relics);
    }

    std::sort(scavengers.begin(), scavengers.end());

    for (const auto& scav : scavengers) {
        std::cout << scav.index << std::endl;
    }

    return 0;
}
