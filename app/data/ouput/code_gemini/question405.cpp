/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int ContaDigitosPares(int n) {
    n = std::abs(n);

    if (n < 10) {
        return (n % 2 == 0) ? 1 : 0;
    }

    if ((n % 10) % 2 == 0) {
        return 1 + ContaDigitosPares(n / 10);
    } else {
        return ContaDigitosPares(n / 10);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int numero;
    std::cin >> numero;

    std::cout << ContaDigitosPares(numero) << std::endl;

    return 0;
}
