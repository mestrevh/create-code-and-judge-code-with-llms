/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> ships_info(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> ships_info[i].first >> ships_info[i].second;
    }

    int people;
    std::cin >> people;

    std::vector<std::vector<int>> allocation(n);
    for (int i = 0; i < n; ++i) {
        allocation[i].resize(ships_info[i].first, 0);
    }

    int remaining_people = people;

    for (int i = 0; i < n; ++i) {
        int sectors = ships_info[i].first;
        int capacity_per_sector = ships_info[i].second;

        for (int j = 0; j < sectors; ++j) {
            if (remaining_people == 0) {
                break;
            }
            int to_allocate = std::min(remaining_people, capacity_per_sector);
            allocation[i][j] = to_allocate;
            remaining_people -= to_allocate;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (size_t j = 0; j < allocation[i].size(); ++j) {
            std::cout << "Nave " << i + 1 << " - Setor " << j + 1 << ": " << allocation[i][j] << " pessoa(s)\n";
        }
    }

    std::cout << "Pessoas nao evacuadas: " << remaining_people << " pessoa(s)\n";

    return 0;
}
