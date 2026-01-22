/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    double raio, altura;
    std::cin >> raio >> altura;
    double volume = M_PI * pow(raio, 2) * altura;
    std::cout << volume << std::endl;
    return 0;
}
