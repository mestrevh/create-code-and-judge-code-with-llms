/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    while (std::cin >> n) {
        if (n == 0) {
            continue;
        }
        std::vector<int> sequence(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> sequence[i];
        }

        if (n == 1) {
            std::cout << "Jolly\n";
            continue;
        }

        std::vector<bool> diffs(n, false);
        for (int i = 0; i < n - 1; ++i) {
            int diff = std::abs(sequence[i] - sequence[i + 1]);
            if (diff > 0 && diff < n) {
                diffs[diff] = true;
            }
        }

        bool is_jolly = true;
        for (int i = 1; i < n; ++i) {
            if (!diffs[i]) {
                is_jolly = false;
                break;
            }
        }

        if (is_jolly) {
            std::cout << "Jolly\n";
        } else {
            std::cout << "Not jolly\n";
        }
    }
    return 0;
}
