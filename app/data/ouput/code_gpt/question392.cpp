/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int minutos = 0, totalMinutos = 0, totalChamadas = 0;
    double total = 10.00;

    while (true) {
        std::cin >> minutos;
        if (minutos == 0) break;
        totalMinutos += minutos;
        totalChamadas++;
    }

    if (totalMinutos > 40 || totalChamadas > 10) {
        int minutosExcedentes = totalMinutos - 40;
        if (minutosExcedentes < 0) minutosExcedentes = 0;
        total += minutosExcedentes * 0.20;
    }

    std::cout << std::fixed << std::setprecision(2) << total << std::endl;
    return 0;
}
