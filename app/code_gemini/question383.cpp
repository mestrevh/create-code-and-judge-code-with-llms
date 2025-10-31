/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b, c;
    std::cin >> a >> b >> c;
    double media = (static_cast<double>(a) + b + c) / 3.0;
    std::cout << std::scientific << std::setprecision(2) << media << std::endl;
    return 0;
}
