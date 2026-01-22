/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <numeric>
#include <cmath>

int countDivisors(int n) {
    int count = 1;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int exponent = 0;
            while (n % i == 0) {
                exponent++;
                n /= i;
            }
            count *= (exponent + 1);
        }
    }
    if (n > 1) {
        count *= 2;
    }
    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b;
    std::cin >> a >> b;
    int common = std::gcd(a, b);
    std::cout << countDivisors(common) << std::endl;
    return 0;
}
