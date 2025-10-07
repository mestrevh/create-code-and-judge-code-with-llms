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
    int count = 0;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i % 3 == 0) {
                count++;
            }
            if (i * i != n) {
                if ((n / i) % 3 == 0) {
                    count++;
                }
            }
        }
    }
    if (count > 0) {
        std::cout << count << "\n";
    } else {
        std::cout << "O numero nao possui divisores multiplos de 3!\n";
    }
    return 0;
}
