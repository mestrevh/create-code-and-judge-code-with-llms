/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> cars;

    for (int i = 1; i <= n; ++i) {
        int total_time = 0;
        for (int j = 0; j < m; ++j) {
            int lap_time;
            std::cin >> lap_time;
            total_time += lap_time;
        }
        cars.push_back({total_time, i});
    }

    std::sort(cars.begin(), cars.end());

    std::cout << cars[0].second << '\n';
    std::cout << cars[1].second << '\n';
    std::cout << cars[2].second << '\n';

    return 0;
}
