/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double n1, n2;
    std::cin >> n1 >> n2;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << n1 << " + " << n2 << " = " << n1 + n2 << std::endl;
    std::cout << n1 << " - " << n2 << " = " << n1 - n2 << std::endl;
    std::cout << n1 << " * " << n2 << " = " << n1 * n2 << std::endl;
    std::cout << n1 << " / " << n2 << " = " << n1 / n2 << std::endl;

    return 0;
}
