/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

void reduce(double* x, double* y) {
    *x -= *y;
}

int main() {
    double x, y;
    std::cin >> x >> y;
    std::cout << std::fixed << std::setprecision(2) << x << " " << y << std::endl;
    reduce(&x, &y);
    std::cout << std::fixed << std::setprecision(2) << x << " " << y << std::endl;
    return 0;
}
