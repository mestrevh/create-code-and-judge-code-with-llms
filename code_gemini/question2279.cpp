/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int verifica(unsigned int n, int x) {
    int ultimo_digito = n % 10;

    if (ultimo_digito == x - 1 || ultimo_digito == x + 1) {
        return 1;
    }

    if (n / 10 == 0) {
        return 0;
    }

    return verifica(n / 10, x);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    unsigned int n;
    int x;

    std::cin >> n >> x;

    if (verifica(n, x)) {
        std::cout << "sim\n";
    } else {
        std::cout << "nao\n";
    }

    return 0;
}
