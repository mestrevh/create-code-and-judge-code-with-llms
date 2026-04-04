/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <numeric>

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;
    if (n <= 0) return 0;

    long long result;
    std::cin >> result;

    for (int i = 1; i < n; ++i) {
        long long next_val;
        if (std::cin >> next_val) {
            result = lcm(result, next_val);
        }
    }

    std::cout << result << std::endl;

    return 0;
}