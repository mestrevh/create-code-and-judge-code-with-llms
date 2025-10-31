/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

long long somatorio_fatores_primos(int x) {
    long long soma = 0;
    for (int i = 2; i <= sqrt(x); ++i) {
        int exp = 0;
        while (x % i == 0) {
            x /= i;
            exp++;
        }
        if (exp > 0) {
            soma += exp * i;
        }
    }
    if (x > 1) {
        soma += 1 * x; // x é primo
    }
    return soma;
}

int main() {
    int x;
    while (std::cin >> x, x != 0) {
        std::cout << somatorio_fatores_primos(x) << std::endl;
    }
    return 0;
}
