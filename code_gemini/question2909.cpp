/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    int start_pos = -1;
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
        if (p[i] == 1) {
            start_pos = i;
        }
    }

    bool is_clockwise = true;
    for (int i = 0; i < n; ++i) {
        if (p[(start_pos + i) % n] != i + 1) {
            is_clockwise = false;
            break;
        }
    }

    if (is_clockwise) {
        std::cout << "SIM, HORARIO\n";
        return;
    }

    bool is_anti_clockwise = true;
    for (int i = 1; i < n; ++i) {
        int current_idx = (start_pos + i) % n;
        int expected_val = n - i + 1;
        if (p[current_idx] != expected_val) {
            is_anti_clockwise = false;
            break;
        }
    }

    if (is_anti_clockwise) {
        std::cout << "SIM, ANTI-HORARIO\n";
        return;
    }

    std::cout << "NAO\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int Q;
    std::cin >> Q;
    while (Q--) {
        solve();
    }
    return 0;
}
