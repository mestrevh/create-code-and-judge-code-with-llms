/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double total_conta;
    std::cin >> total_conta;

    int parte_inteira = static_cast<int>(total_conta / 3.0);

    double parte_carlos = parte_inteira;
    double parte_andre = parte_inteira;
    double parte_felipe = total_conta - (2.0 * parte_inteira);

    std::cout << std::fixed;
    std::cout << std::setprecision(1) << parte_carlos << std::endl;
    std::cout << std::setprecision(1) << parte_andre << std::endl;
    std::cout << std::setprecision(2) << parte_felipe << std::endl;

    return 0;
}
