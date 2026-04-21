/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

/**
 * Problem: Least Common Multiple (LCM)
 * Complexity: O(log(min(m, n))) using Euclidean Algorithm for GCD.
 * Persona: Competitive Programming Grandmaster
 */

long long get_gcd(long long a, long long b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main() {
    // Standard Competitive Programming I/O Optimization
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long m, n;
    // Reading input values m and n
    if (!(std::cin >> m >> n)) {
        return 0;
    }

    // LCM(m, n) = (m * n) / GCD(m, n)
    // To prevent overflow, we divide before multiplying: (m / GCD) * n
    if (m == 0 || n == 0) {
        std::cout << 0 << "\n";
    } else {
        long long common_divisor = get_gcd(m, n);
        long long lcm = (m / common_divisor) * n;
        std::cout << lcm << "\n";
    }

    return 0;
}

生活