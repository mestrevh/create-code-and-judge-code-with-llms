/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long n;
    std::cin >> n;
    bool found = false;
    for (long long i = 1; ; ++i) {
        long long product = i * (i + 1) * (i + 2);
        if (product == n) {
            std::cout << i << " * " << (i + 1) << " * " << (i + 2) << " = " << n << "\n";
            std::cout << "Verdadeiro\n";
            found = true;
            break;
        }
        if (product > n || product <= 0) {
            break;
        }
    }
    if (!found) {
        std::cout << "Falso\n";
    }
    return 0;
}
