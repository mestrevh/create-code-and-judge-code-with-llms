/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double distancia, litros;
    std::cin >> distancia >> litros;
    double km_por_litro = distancia / litros;
    std::cout << std::fixed << std::setprecision(1) << km_por_litro << std::endl;
    return 0;
}
