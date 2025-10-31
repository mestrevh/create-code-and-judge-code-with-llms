/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;
    double det = a * e - b * d;
    double x = (c * e - b * f) / det;
    double y = (a * f - c * d) / det;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    return 0;
}
