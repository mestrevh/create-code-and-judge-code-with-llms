/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double x;
    std::cin >> x;

    std::cout << "sinal(" << std::scientific << std::setprecision(4) << x << ") = ";

    if (x > 0) {
        std::cout << "+1\n";
    } else if (x < 0) {
        std::cout << "-1\n";
    } else {
        std::cout << "0\n";
    }

    return 0;
}
