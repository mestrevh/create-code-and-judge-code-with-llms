/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int P, N, C;
    while (std::cin >> P >> N >> C && (P != 0 || N != 0 || C != 0)) {
        std::vector<int> current_streaks(P, 0);
        int total_palitos = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < P; ++j) {
                int bit;
                std::cin >> bit;
                if (bit == 1) {
                    current_streaks[j]++;
                } else {
                    if (current_streaks[j] >= C) {
                        total_palitos++;
                    }
                    current_streaks[j] = 0;
                }
            }
        }

        for (int j = 0; j < P; ++j) {
            if (current_streaks[j] >= C) {
                total_palitos++;
            }
        }

        std::cout << total_palitos << "\n";
    }

    return 0;
}
