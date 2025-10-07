/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>

int main() {
    int dias, km_rodados;
    std::cin >> dias >> km_rodados;

    double custo_diarias = dias * 90.0;
    double custo_km_extra = 0.0;

    int km_incluidos = dias * 100;
    
    if (km_rodados > km_incluidos) {
        int km_excedentes = km_rodados - km_incluidos;
        custo_km_extra = km_excedentes * 12.0;
    }

    double custo_total = custo_diarias + custo_km_extra;

    std::cout << std::fixed << std::setprecision(2) << custo_total << std::endl;

    return 0;
}
