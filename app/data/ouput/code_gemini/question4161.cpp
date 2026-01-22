/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double a, b, n;
    std::cin >> a >> b >> n;

    double c;
    std::cin >> c;

    double base = (b - a) / n;
    double total_area = 0.0;

    for (int i = 1; i <= n; ++i) {
        double x = a + i * base;
        total_area += base * (x * x);
    }

    if (total_area > c) {
        std::cout << "Maior\n";
    } else if (total_area < c) {
        std::cout << "Menor\n";
    } else {
        std::cout << "Igual\n";
    }

    return 0;
}
