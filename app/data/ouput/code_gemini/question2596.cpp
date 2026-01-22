/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double h, r, custo_lata;
    std::cin >> h >> r >> custo_lata;

    const double PI = 3.14159; 
    
    // A sample de saída é inconsistente com um PI de alta precisão ou 3.14.
    // Usando M_PI ou acos(-1.0) para maior precisão geral.
    // A fórmula da área é 2 * PI * r^2 + 2 * PI * r * h
    double area_total = (2.0 * acos(-1.0) * r * r) + (2.0 * acos(-1.0) * r * h);

    double litros = area_total / 3.0;
    double latas = litros / 5.0;
    double custo_total = latas * custo_lata;

    std::cout << std::fixed << std::setprecision(6);

    std::cout << area_total << "m2" << std::endl;
    std::cout << litros << "l" << std::endl;
    std::cout << latas << std::endl;
    std::cout << "R$" << custo_total << std::endl;

    return 0;
}
