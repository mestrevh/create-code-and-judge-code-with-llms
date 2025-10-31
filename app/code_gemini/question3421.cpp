/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double x;
    int n;
    std::cin >> x >> n;
    double sum = 0.0;
    double term = 1.0;
    for (int i = 0; i < n; ++i) {
        sum += term;
        term = term * x / (i + 1);
    }
    std::cout << std::fixed << std::setprecision(5) << sum << std::endl;
    return 0;
}
