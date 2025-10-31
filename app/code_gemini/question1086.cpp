/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int dias;
    int km;
    std::cin >> dias >> km;
    double custo_dias = dias * 30.00;
    double custo_km = km * 0.01;
    double total = (custo_dias + custo_km) * 0.90;
    std::cout << std::fixed << std::setprecision(2) << total << std::endl;
    return 0;
}
