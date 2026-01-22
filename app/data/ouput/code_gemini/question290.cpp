/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int codigo1, numero1, codigo2, numero2;
    double valor1, valor2, total;

    std::cin >> codigo1 >> numero1 >> valor1;
    std::cin >> codigo2 >> numero2 >> valor2;

    total = (numero1 * valor1) + (numero2 * valor2);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "VALOR A PAGAR: R$ " << total << std::endl;

    return 0;
}
