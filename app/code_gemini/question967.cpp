/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    while (std::cin >> N) {
        for (int k = 1; k <= N; k += 2) {
            int padding = (N - k) / 2;
            for (int i = 0; i < padding; ++i) {
                std::cout << "-";
            }
            for (int i = 0; i < k; ++i) {
                std::cout << "*";
            }
            for (int i = 0; i < padding; ++i) {
                std::cout << "-";
            }
            std::cout << "\n";
        }
        int leaf_height = (N + 1) / 2;
        int num_trunk_lines = leaf_height / 2;
        for (int i = 0; i < num_trunk_lines; ++i) {
            int k = 1 + 2 * i;
            int padding = (N - k) / 2;
            for (int j = 0; j < padding; ++j) {
                std::cout << "-";
            }
            for (int j = 0; j < k; ++j) {
                std::cout << "*";
            }
            for (int j = 0; j < padding; ++j) {
                std::cout << "-";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    return 0;
}
