/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int G, P;
    while (std::cin >> G >> P && (G != 0 || P != 0)) {
        std::vector<std::vector<int>> results(G, std::vector<int>(P));
        for (int i = 0; i < G; ++i) {
            for (int j = 0; j < P; ++j) {
                std::cin >> results[i][j];
            }
        }

        int S;
        std::cin >> S;

        for (int s = 0; s < S; ++s) {
            int K;
            std::cin >> K;
            std::vector<int> points(K);
            for (int i = 0; i < K; ++i) {
                std::cin >> points[i];
            }

            std::vector<int> pilot_scores(P, 0);
            for (int g = 0; g < G; ++g) {
                for (int p = 0; p < P; ++p) {
                    int position = results[g][p];
                    if (position <= K) {
                        pilot_scores[p] += points[position - 1];
                    }
                }
            }

            int max_score = 0;
            if (!pilot_scores.empty()) {
                max_score = *std::max_element(pilot_scores.begin(), pilot_scores.end());
            }

            bool first_winner = true;
            for (int p = 0; p < P; ++p) {
                if (pilot_scores[p] == max_score) {
                    if (!first_winner) {
                        std::cout << " ";
                    }
                    std::cout << (p + 1);
                    first_winner = false;
                }
            }
            std::cout << "\n";
        }
    }

    return 0;
}
