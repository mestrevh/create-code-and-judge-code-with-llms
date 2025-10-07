/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int dias;
    std::cin >> dias;
    double custo = dias * 20 * 3.20;
    std::cout << std::fixed << std::setprecision(2) << custo << std::endl;
    return 0;
}
