/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int calcularCusto(int quantidade, int preco) {
    if (quantidade <= 0) {
        return 0;
    }
    return preco + calcularCusto(quantidade - 1, preco);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int c, m, p;
    while (std::cin >> c >> m >> p) {
        if (m >= calcularCusto(c, p)) {
            std::cout << "Sim\n";
        } else {
            std::cout << "Nao\n";
        }
    }
    return 0;
}
