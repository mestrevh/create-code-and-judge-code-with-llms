/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n, m;
    while (std::cin >> n >> m && (n != 0 || m != 0)) {
        if (n == 0 || m == 0) {
            std::cout << std::fixed << std::setprecision(2) << 0.00 << std::endl;
            continue;
        }

        __int128_t N_128 = (__int128_t)n * m;
        
        __int128_t t = N_128 * (N_128 + 1) / 2;

        __int128_t c = (__int128_t)m * (m + 1) / 2;
        
        __int128_t first_term_d = (__int128_t)(n - 1) * m + 1;
        __int128_t d = (__int128_t)m * (first_term_d + N_128) / 2;

        __int128_t a = (__int128_t)m * n * (n - 1) / 2 + n;

        __int128_t b = (__int128_t)m * n * (n + 1) / 2;

        long long k = std::min(n, m);

        __int128_t x = (__int128_t)(m + 1) * k * (k - 1) / 2 + k;

        __int128_t y = (__int128_t)(m - 1) * k * (k - 1) / 2 + (__int128_t)k * m;

        __int128_t numerator = t - (x + y) + (a * b) - (c * d);
        
        long double result = (long double)numerator / (long double)N_128;

        std::cout << std::fixed << std::setprecision(2) << result << std::endl;
    }

    return 0;
}
