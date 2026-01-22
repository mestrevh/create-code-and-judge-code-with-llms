/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <utility>
#include <numeric>

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    if (a == 1) {
        return b;
    }
    if (b == 1) {
        return a;
    }
    return (a / gcd(a, b)) * b;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << 1 << std::endl;
        return 0;
    }

    long long result;
    std::cin >> result;

    for (int i = 1; i < n; ++i) {
        long long next_num;
        std::cin >> next_num;
        result = lcm(result, next_num);
    }

    std::cout << result << std::endl;

    return 0;
}
