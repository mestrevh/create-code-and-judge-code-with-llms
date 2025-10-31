/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    double sum = 0.0;
    int terms_found = 0;

    for (int p = 3; terms_found < n; p += 2) {
        if (isPrime(p) && isPrime(p + 2)) {
            sum += (1.0 / p) + (1.0 / (p + 2));
            terms_found++;
        }
    }

    std::cout << std::fixed << std::setprecision(10) << sum << std::endl;

    return 0;
}
