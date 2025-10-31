/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double distancia, litros;
    std::cin >> distancia >> litros;
    double consumo = distancia / litros;
    std::cout << std::fixed << std::setprecision(1) << consumo << std::endl;
    return 0;
}
