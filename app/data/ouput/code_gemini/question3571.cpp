/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double altura, raio;
    std::cin >> altura >> raio;

    const double CUSTO_LATA = 20.00;
    const double LITROS_POR_LATA = 5.0;
    const double COBERTURA_POR_LITRO = 3.0;

    double area_base = M_PI * raio * raio;
    double area_lateral = 2 * M_PI * raio * altura;
    double area_total = 2 * area_base + area_lateral;

    double litros_necessarios = area_total / COBERTURA_POR_LITRO;

    int latas_necessarias = ceil(litros_necessarios / LITROS_POR_LATA);

    double custo_total = latas_necessarias * CUSTO_LATA;

    std::cout << "custo = R$ " << std::fixed << std::setprecision(2) << custo_total << std::endl;
    std::cout << "quantidade de latas = " << latas_necessarias << std::endl;

    return 0;
}
