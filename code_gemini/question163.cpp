/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int p, n;
    std::cin >> p >> n;

    std::vector<int> counts(p + 1, 0);
    for (int i = 0; i < n; ++i) {
        int folder_pos;
        std::cin >> folder_pos;
        counts[folder_pos]++;
    }

    bool is_perfect = true;

    for (int i = 1; i < p; ++i) {
        if (counts[i] < counts[i + 1]) {
            is_perfect = false;
            break;
        }
    }

    if (is_perfect) {
        if (counts[1] > counts[p] + 1) {
            is_perfect = false;
        }
    }

    if (is_perfect) {
        std::cout << "S\n";
    } else {
        std::cout << "N\n";
    }

    return 0;
}
