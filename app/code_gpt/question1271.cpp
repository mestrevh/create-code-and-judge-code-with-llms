/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int N, M;
    std::cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        std::cout << std::setw(3) << i;
        if (i % M == 0) std::cout << std::endl;
    }
    if (N % M != 0) std::cout << std::endl;
    return 0;
}
