/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::unordered_map<int, int> house_positions;
    for (int i = 0; i < n; ++i) {
        int house_num;
        std::cin >> house_num;
        house_positions[house_num] = i;
    }

    long long total_time = 0;
    int current_pos = 0;

    for (int i = 0; i < m; ++i) {
        int delivery_house_num;
        std::cin >> delivery_house_num;

        int target_pos = house_positions[delivery_house_num];
        total_time += std::abs(target_pos - current_pos);
        current_pos = target_pos;
    }

    std::cout << total_time << std::endl;

    return 0;
}
