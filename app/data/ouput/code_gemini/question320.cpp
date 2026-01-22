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

    int n, g;
    std::cin >> n >> g;

    int total_points = 0;
    std::vector<int> diffs;

    for (int i = 0; i < n; ++i) {
        int s, r;
        std::cin >> s >> r;
        if (s > r) {
            total_points += 3;
        } else {
            if (s == r) {
                total_points += 1;
            }
            diffs.push_back(r - s);
        }
    }

    std::sort(diffs.begin(), diffs.end());

    for (int diff : diffs) {
        if (g <= 0) {
            break;
        }

        int cost_to_win = diff + 1;
        
        if (g >= cost_to_win) {
            g -= cost_to_win;
            if (diff == 0) {
                total_points += 2;
            } else {
                total_points += 3;
            }
        } else {
            if (diff > 0) {
                int cost_to_draw = diff;
                if (g >= cost_to_draw) {
                    g -= cost_to_draw;
                    total_points += 1;
                }
            }
            break;
        }
    }

    std::cout << total_points << '\n';

    return 0;
}
