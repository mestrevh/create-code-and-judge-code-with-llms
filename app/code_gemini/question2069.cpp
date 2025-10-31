/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long a, g, p;
    std::cin >> a >> g >> p;
    long long posicao = 0;
    long long velocidade = 0;
    while (g > 0) {
        velocidade += a;
        posicao += velocidade;
        g -= velocidade;
    }
    std::cout << posicao << std::endl;
    if (posicao >= p) {
        std::cout << "S" << std::endl;
    } else {
        std::cout << "N" << std::endl;
    }
    return 0;
}
