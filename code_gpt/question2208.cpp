/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

double euler_series(int n) {
    double sum = 0.0;
    double factorial = 1.0;

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            factorial *= i; 
        }
        sum += 1.0 / factorial;
    }

    return sum;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << std::fixed << std::setprecision(15) << euler_series(n) << std::endl;
    return 0;
}
