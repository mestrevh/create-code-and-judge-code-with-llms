/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double n1, n2;
    std::cin >> n1 >> n2;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << n1 << " + " << n2 << " = " << n1 + n2 << std::endl;
    std::cout << n1 << " - " << n2 << " = " << n1 - n2 << std::endl;
    std::cout << n1 << " * " << n2 << " = " << n1 * n2 << std::endl;
    std::cout << n1 << " / " << n2 << " = " << n1 / n2 << std::endl;

    return 0;
}
