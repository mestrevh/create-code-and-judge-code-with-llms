/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;
    double soma = 0.0;

    for (int i = 1; i <= n; ++i) {
        soma += 1.0 / (i * i);
    }

    std::cout << std::fixed << std::setprecision(6) << soma << std::endl;
    return 0;
}
