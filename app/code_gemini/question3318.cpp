/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double n;
    std::cin >> n;
    double result = sqrt(sqrt(n));
    std::cout << std::fixed << std::setprecision(1) << result << std::endl;
    return 0;
}
