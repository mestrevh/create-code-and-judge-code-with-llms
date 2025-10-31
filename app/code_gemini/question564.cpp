/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double velocidade_maxima, velocidade_veiculo;
    std::cin >> velocidade_maxima >> velocidade_veiculo;

    std::cout << std::fixed << std::setprecision(2);

    if (velocidade_veiculo <= velocidade_maxima) {
        std::cout << 0.00 << std::endl;
        std::cout << 0 << std::endl;
    } else if (velocidade_veiculo <= velocidade_maxima * 1.20) {
        std::cout << 85.13 << std::endl;
        std::cout << 4 << std::endl;
    } else if (velocidade_veiculo <= velocidade_maxima * 1.50) {
        std::cout << 127.69 << std::endl;
        std::cout << 5 << std::endl;
    } else {
        std::cout << 574.62 << std::endl;
        std::cout << 7 << std::endl;
    }

    return 0;
}
