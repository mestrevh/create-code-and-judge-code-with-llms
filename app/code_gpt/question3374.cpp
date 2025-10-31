/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double a, b, c;
    std::cin >> a >> b >> c;
    double media = (a + b + c) / 3;
    std::cout << std::fixed << std::setprecision(6) << media << std::endl;
    return 0;
}
