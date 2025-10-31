/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

void maior_numero(double a, double b) {
    if (a == b) {
        std::cout << "São iguais" << std::endl;
    } else {
        double maior = (a > b) ? a : b;
        if (maior == floor(maior)) {
            std::cout << static_cast<long long>(maior) << std::endl;
        } else {
            std::cout << maior << std::endl;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double n1, n2;
    std::cin >> n1 >> n2;
    maior_numero(n1, n2);
    return 0;
}
