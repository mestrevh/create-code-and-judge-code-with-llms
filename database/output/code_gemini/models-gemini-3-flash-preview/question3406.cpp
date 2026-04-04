/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    if (!(std::cin >> n)) return 0;

    if (n < 1) return 0;

    std::vector<long long> divisors;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }

    std::sort(divisors.begin(), divisors.end());

    for (size_t i = 0; i < divisors.size(); ++i) {
        std::cout << divisors[i] << "\n";
    }

    return 0;
}