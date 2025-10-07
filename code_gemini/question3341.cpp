/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

long long sum_digits(long long n) {
    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void solve() {
    long long n, s;
    std::cin >> n >> s;

    if (sum_digits(n) <= s) {
        std::cout << 0 << "\n";
        return;
    }

    long long power = 1;
    for (int p = 0; p < 18; ++p) {
        power *= 10;
        long long m = (n / power + 1) * power;
        if (sum_digits(m) <= s) {
            std::cout << m - n << "\n";
            return;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
