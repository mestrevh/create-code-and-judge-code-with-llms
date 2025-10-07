/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double a, b, c, d, e;
    std::cin >> a >> b >> c >> d >> e;
    double result = (a + b + c) / (d + e);
    std::cout << std::fixed << std::setprecision(2) << result << std::endl;
    return 0;
}
