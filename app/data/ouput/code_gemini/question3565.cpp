/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, x;

    while (std::cin >> n && n != -1) {
        std::cin >> x;

        std::vector<int> original_vec(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> original_vec[i];
        }

        std::vector<int> sorted_vec = original_vec;
        std::sort(sorted_vec.begin(), sorted_vec.end());

        std::vector<std::tuple<int, int, int>> matches;

        for (int i = 0; i < n; ++i) {
            if (std::abs(original_vec[i] - sorted_vec[i]) == x) {
                matches.emplace_back(original_vec[i], sorted_vec[i], i + 1);
            }
        }

        std::cout << matches.size() << "\n";
        for (const auto& match : matches) {
            std::cout << std::get<0>(match) << " " << std::get<1>(match) << " " << std::get<2>(match) << "\n";
        }
    }

    return 0;
}
