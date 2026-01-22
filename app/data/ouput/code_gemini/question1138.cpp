/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long a, b, c, d;
    std::cin >> a >> b >> c >> d;
    if (c % a != 0) {
        std::cout << -1 << std::endl;
        return 0;
    }
    long long g = c / a;
    std::vector<long long> divisors_k;
    for (long long i = 1; i * i <= g; ++i) {
        if (g % i == 0) {
            divisors_k.push_back(i);
            if (i * i != g) {
                divisors_k.push_back(g / i);
            }
        }
    }
    std::sort(divisors_k.begin(), divisors_k.end());
    for (long long k : divisors_k) {
        long long n = a * k;
        if (n % b != 0 && d % n != 0) {
            std::cout << n << std::endl;
            return 0;
        }
    }
    std::cout << -1 << std::endl;
    return 0;
}
