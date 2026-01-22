/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double altura;
    std::cout << "Informe sua altura:" << std::endl;
    std::cin >> altura;
    double peso_ideal = (72.7 * altura) - 58;
    std::cout << "Peso ideal: " << std::fixed << std::setprecision(14) << peso_ideal << std::endl;
    return 0;
}
