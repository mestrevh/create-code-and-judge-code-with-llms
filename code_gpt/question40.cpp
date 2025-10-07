/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double gasto;
    std::cin >> gasto;
    double total = gasto * 1.10;
    std::cout << std::fixed << std::setprecision(2) << total << std::endl;
    return 0;
}
