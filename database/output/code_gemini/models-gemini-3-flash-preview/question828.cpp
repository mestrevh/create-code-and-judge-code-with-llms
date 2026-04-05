/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double hourly_rate, hours_worked;
    while (std::cin >> hourly_rate >> hours_worked) {
        std::cout << "Informe quanto ganha por hora:\n"
                  << "Informe a quantidade mensal de trabalho:\n"
                  << "Resultado: " << std::fixed << std::setprecision(1) << (hourly_rate * hours_worked) << "\n";
    }

    return 0;
}