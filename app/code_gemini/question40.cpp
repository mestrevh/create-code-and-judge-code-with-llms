/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double gasto;
    std::cin >> gasto;
    double total = gasto * 1.1;
    std::cout << std::fixed << std::setprecision(2) << total << std::endl;
    return 0;
}
