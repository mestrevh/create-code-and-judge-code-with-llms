/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double peso;
    std::cin >> peso;

    if (peso <= 20.0) {
        std::cout << std::fixed << std::setprecision(2) << 0.0 << std::endl;
    } else if (peso <= 25.0) {
        double taxa = (peso - 20.0) * 12.50;
        std::cout << std::fixed << std::setprecision(2) << taxa << std::endl;
    } else if (peso <= 30.0) {
        double taxa = (peso - 20.0) * 32.75;
        std::cout << std::fixed << std::setprecision(2) << taxa << std::endl;
    } else {
        std::cout << "PESO LIMITE EXCEDIDO" << std::endl;
    }

    return 0;
}
