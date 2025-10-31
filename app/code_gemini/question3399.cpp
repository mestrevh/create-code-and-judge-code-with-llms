/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double A, B;
    std::cin >> A >> B;
    double x = -B / A;
    std::cout << std::fixed << std::setprecision(2) << x << std::endl;
    return 0;
}
