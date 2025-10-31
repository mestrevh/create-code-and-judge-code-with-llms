/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long x;
    while (std::cin >> x && x != 0) {
        long long n = (x + 1) / 2;
        long long a = n * n;
        long long b = (n - 1) * (n - 1);
        std::cout << a << " - " << b << "\n";
    }
    return 0;
}
