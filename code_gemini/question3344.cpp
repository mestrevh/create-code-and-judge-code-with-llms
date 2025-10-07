/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n <= 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<int> original_v(n);
    std::vector<int> sorted_v(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> original_v[i];
    }

    sorted_v = original_v;
    std::sort(sorted_v.begin(), sorted_v.end());

    std::vector<std::pair<int, int>> result;
    for (int i = 0; i < n; ++i) {
        if (original_v[i] == sorted_v[i]) {
            result.push_back({original_v[i], i + 1});
        }
    }

    std::cout << result.size() << std::endl;
    for (const auto& p : result) {
        std::cout << p.first << " " << p.second << std::endl;
    }

    return 0;
}
