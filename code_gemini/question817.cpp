/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

int main() {
    setup_io();

    int n;
    std::cin >> n;

    std::vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> h[i];
    }

    if (n <= 2) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<int> max_l(n);
    max_l[0] = h[0];
    for (int i = 1; i < n; ++i) {
        max_l[i] = std::max(max_l[i - 1], h[i]);
    }

    std::vector<int> max_r(n);
    max_r[n - 1] = h[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        max_r[i] = std::max(max_r[i + 1], h[i]);
    }

    int covered_sections = 0;
    for (int i = 0; i < n; ++i) {
        int water_level = std::min(max_l[i], max_r[i]);
        if (water_level > h[i]) {
            covered_sections++;
        }
    }

    std::cout << covered_sections << std::endl;

    return 0;
}
