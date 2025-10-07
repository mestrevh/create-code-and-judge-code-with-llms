/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

void reduz(double *x, double *y) {
    *x = *x - *y;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double x, y;

    std::cin >> x >> y;

    reduz(&x, &y);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << x << " " << y << std::endl;

    return 0;
}
