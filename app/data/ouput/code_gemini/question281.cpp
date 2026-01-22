/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <utility>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int L;
    while (std::cin >> L) {
        std::vector<int> train(L);
        for (int i = 0; i < L; ++i) {
            std::cin >> train[i];
        }

        int swaps = 0;
        for (int i = 0; i < L - 1; ++i) {
            for (int j = 0; j < L - i - 1; ++j) {
                if (train[j] > train[j + 1]) {
                    std::swap(train[j], train[j + 1]);
                    swaps++;
                }
            }
        }
        std::cout << "A melhor troca leva " << swaps << " passos\n";
    }

    return 0;
}
