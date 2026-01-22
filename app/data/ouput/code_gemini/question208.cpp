/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long n;
    std::cin >> n;
    if (n <= 3) {
        std::cout << 'N' << '\n';
        return 0;
    }
    if (n % 2 == 0) {
        std::cout << 'S' << '\n';
        return 0;
    }
    long long limit = sqrt(n);
    for (long long i = 3; i <= limit; i += 2) {
        if (n % i == 0) {
            std::cout << 'S' << '\n';
            return 0;
        }
    }
    std::cout << 'N' << '\n';
    return 0;
}
