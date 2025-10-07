/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int dias;
    std::cin >> dias;
    double custo_reais = dias * 20.0 * 3.20;
    std::cout << std::fixed << std::setprecision(2) << custo_reais << std::endl;
    return 0;
}
