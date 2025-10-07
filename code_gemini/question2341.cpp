/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int decrementa(int n, int valor_inicial = -1) {
    if (valor_inicial == -1) {
        valor_inicial = n;
    }

    if (n < 10) {
        if (n % 2 != 0) {
            return valor_inicial - 3;
        } else {
            return valor_inicial - 4;
        }
    }

    return decrementa(n / 10, valor_inicial);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::cout << decrementa(n) << '\n';
    return 0;
}
