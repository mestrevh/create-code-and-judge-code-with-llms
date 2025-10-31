/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double salario;
    std::cin >> salario;

    if (salario <= 2000.00) {
        std::cout << "Isento" << std::endl;
    } else {
        double imposto = 0.0;
        if (salario <= 3000.00) {
            imposto = (salario - 2000.00) * 0.08;
        } else if (salario <= 4500.00) {
            imposto = (1000.00 * 0.08) + (salario - 3000.00) * 0.18;
        } else {
            imposto = (1000.00 * 0.08) + (1500.00 * 0.18) + (salario - 4500.00) * 0.28;
        }
        std::cout << std::fixed << std::setprecision(2) << "R$ " << imposto << std::endl;
    }

    return 0;
}
