/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N)) return 0;
    long long P, Q, R, S, X, Y;
    cin >> P >> Q >> R >> S >> X >> Y;
    long long I, J;
    cin >> I >> J;

    long long i = I, j = J;

    auto A = [&](long long m, long long n) -> long long {
        return P * m + Q * n + (m % X) + (n % X);
    };
    auto B = [&](long long m, long long n) -> long long {
        return R * m + S * n + (m % Y) + (n % Y);
    };

    long long ans = 0;
    for (long long k = 1; k <= N; k++) {
        ans += A(i, k) * B(k, j);
    }

    cout << ans << "\n";
    return 0;
}