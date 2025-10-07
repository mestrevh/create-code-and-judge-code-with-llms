/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int n;
    std::cout << "Digite um numero positivo:" << std::endl;
    std::cin >> n;

    if (n > 0) {
        double sum = static_cast<double>(n) * (static_cast<double>(n) + 1.0) / 2.0;
        double media = sum / static_cast<double>(n);
        
        std::cout << "Media de 1 ate " << n << ": " << media << std::endl;
    } else {
        std::cout << "Apenas valores positivos" << std::endl;
    }

    return 0;
}
