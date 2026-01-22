/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> locations(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> locations[i];
    }

    std::sort(locations.begin(), locations.end());

    int min_pos = locations.front();
    int max_pos = locations.back();

    int max_covered = -1;
    int best_pos = min_pos;

    for (int current_pos = min_pos; current_pos <= max_pos; ++current_pos) {
        int current_covered = 0;
        for (int loc : locations) {
            if (current_pos - k <= loc && loc <= current_pos + k) {
                current_covered++;
            }
        }

        if (current_covered > max_covered) {
            max_covered = current_covered;
            best_pos = current_pos;
        }
    }
    std::cout << best_pos << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int q;
    std::cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
