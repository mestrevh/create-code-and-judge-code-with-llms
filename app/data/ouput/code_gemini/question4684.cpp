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

    int N, M, X;
    std::cin >> N >> M;
    std::cin >> X;

    std::vector<int> counts(M, 0);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int value;
            std::cin >> value;
            if (value == X) {
                counts[j]++;
            }
        }
    }

    for (int j = 0; j < M; ++j) {
        std::cout << counts[j] << " ";
    }
    std::cout << "\n\n";

    int max_height = 0;
    if (!counts.empty()) {
        max_height = *std::max_element(counts.begin(), counts.end());
    }

    for (int i = 0; i < max_height; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i < counts[j]) {
                std::cout << "1 ";
            } else {
                std::cout << "0 ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}
