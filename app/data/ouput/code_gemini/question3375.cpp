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

    double altura, raio, custo_lata, conteudo_lata, rendimento_litro;

    std::cin >> altura;
    std::cin >> raio;
    std::cin >> custo_lata;
    std::cin >> conteudo_lata;
    std::cin >> rendimento_litro;

    const double PI = acos(-1.0);

    double area_base = PI * raio * raio;
    double area_lateral = 2.0 * PI * raio * altura;
    double area_total = 2.0 * area_base + area_lateral;

    double litros_necessarios = area_total / rendimento_litro;
    double quantidade_latas = ceil(litros_necessarios / conteudo_lata);
    double custo_total = quantidade_latas * custo_lata;

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Quantidade de latas: " << quantidade_latas << std::endl;
    std::cout << "Custo: R$" << custo_total << std::endl;

    return 0;
}
