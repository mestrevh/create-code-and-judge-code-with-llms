/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int V, N;
    std::cin >> V >> N;

    std::vector<int> debts(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> debts[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            for (int k = j + 1; k < N; ++k) {
                if (debts[i] + debts[j] + debts[k] == V) {
                    std::cout << "Zeca nao vai ter que trabalhar!";
                    return 0;
                }
            }
        }
    }

    std::cout << "Zeca vai ter que trabalhar.";

    return 0;
}
