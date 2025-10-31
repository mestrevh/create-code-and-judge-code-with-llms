/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double f;
    std::cin >> f;
    double c = (f - 32.0) * 5.0 / 9.0;
    std::cout << std::fixed << std::setprecision(10) << c << std::endl;
    return 0;
}
