/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int N;
    std::cin >> N;

    if (N < 0) {
        std::cout << "O valor informado para N foi negativo" << std::endl;
        return 0;
    }
    if (N == 0) {
        std::cout << "Lista vazia - O valor de S eh zero" << std::endl;
        return 0;
    }

    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    int S = 0;
    for (int i = 0; i < N / 2; ++i) {
        S += pow(A[i] - A[N - 1 - i], 2);
    }

    std::cout << "S = " << S << std::endl;
    return 0;
}
