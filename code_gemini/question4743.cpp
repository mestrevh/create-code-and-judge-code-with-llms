/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int c;
    std::cin >> c;
    double f = (c * 9.0 / 5.0) + 32.0;
    std::cout << std::fixed << std::setprecision(1) << f << std::endl;
    return 0;
}
