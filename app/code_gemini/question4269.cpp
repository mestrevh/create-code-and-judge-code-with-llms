/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double d1, d2, d3;
    const double rate = 5.08;

    std::cin >> d1 >> d2 >> d3;

    std::cout << d1 * rate << std::endl;
    std::cout << d2 * rate << std::endl;
    std::cout << d3 * rate << std::endl;

    return 0;
}
