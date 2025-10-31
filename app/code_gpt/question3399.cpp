/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double A, B;
    std::cin >> A >> B;
    double root = -B / A;
    std::cout << std::fixed << std::setprecision(2) << root << std::endl;
    return 0;
}
