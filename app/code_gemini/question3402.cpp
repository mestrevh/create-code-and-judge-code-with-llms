/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double a, b, c, d;
    std::cin >> a >> b;
    std::cin >> c >> d;

    double x = (d - b) / (a - c);
    double y = a * x + b;

    std::cout << std::fixed << std::setprecision(2) << x << " " << y << std::endl;

    return 0;
}
