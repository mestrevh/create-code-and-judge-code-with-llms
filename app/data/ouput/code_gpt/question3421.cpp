/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double x;
    int n;
    std::cin >> x >> n;

    double result = 0.0;
    for (int i = 0; i < n; ++i) {
        result += pow(x, i) / tgamma(i + 1);
    }

    std::cout << std::fixed << std::setprecision(5) << result << std::endl;
    return 0;
}
