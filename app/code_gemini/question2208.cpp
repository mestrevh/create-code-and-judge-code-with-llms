/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    long double sum = 0.0;
    long double factorial = 1.0;
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            factorial *= i;
        }
        sum += 1.0 / factorial;
    }
    std::cout << std::fixed << std::setprecision(15) << sum << std::endl;
    return 0;
}
