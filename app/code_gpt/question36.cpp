/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    int M, N;
    std::cin >> M >> N;

    int maiorMultiplo = (N / M) * M;

    if (maiorMultiplo > 0) {
        std::cout << maiorMultiplo << std::endl;
    } else {
        std::cout << "sem multiplos menores que " << N << std::endl;
    }

    return 0;
}
