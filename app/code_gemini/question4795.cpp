/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double a, b;
    std::cin >> a >> b;
    double m1 = (a + b) / 2.0;
    double m2 = (m1 + a) / 2.0;
    double result = (m2 + a) / 2.0;
    std::cout << std::fixed << std::setprecision(2) << result << std::endl;
    return 0;
}
