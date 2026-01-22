/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double raio;
    double angulo_graus;
    const double pi = 3.14;

    std::cin >> raio;
    std::cin >> angulo_graus;

    double comprimento_arco = (angulo_graus / 360.0) * 2.0 * pi * raio;
    double area_setor = (angulo_graus / 360.0) * pi * raio * raio;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << comprimento_arco << std::endl;
    std::cout << area_setor << std::endl;

    return 0;
}
