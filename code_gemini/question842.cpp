/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long m, n;
    std::cin >> m >> n;
    long long lcm = (m / gcd(m, n)) * n;
    std::cout << lcm << std::endl;
    return 0;
}
