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

    long long x;
    if (!(std::cin >> x)) return 0;

    std::vector<long long> divisors;
    for (long long i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            divisors.push_back(i);
            if (i * i != x) {
                divisors.push_back(x / i);
            }
        }
    }

    std::sort(divisors.begin(), divisors.end(), std::greater<long long>());

    for (const auto& d : divisors) {
        std::cout << d << "\n";
    }

    return 0;
}