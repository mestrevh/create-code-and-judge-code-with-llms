/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <numeric>

typedef long long ll;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll M, N;
    if (!(std::cin >> M >> N)) return 0;

    ll common = gcd(M, N);
    ll m_reduced = M / common;
    ll n_reduced = N / common;

    if (m_reduced % 2 != 0 && n_reduced % 2 != 0) {
        std::cout << common << "\n";
    } else {
        std::cout << 0 << "\n";
    }

    return 0;
}

_
