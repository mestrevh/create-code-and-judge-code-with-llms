/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

bool check(long long t, long long k, long long n) {
    long long reachable_levels = 0;
    long long term = 1;
    for (long long i = 1; i <= k && i <= t; ++i) {
        long long next_term_numerator;
        if (__builtin_mul_overflow(term, t - i + 1, &next_term_numerator)) {
            reachable_levels = n;
            break;
        }
        term = next_term_numerator / i;
        reachable_levels += term;
        if (reachable_levels >= n) {
            break;
        }
    }
    return reachable_levels >= n;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long N, K;
    std::cin >> N >> K;

    long long low = 1, high = N, ans = N;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, K, N)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
