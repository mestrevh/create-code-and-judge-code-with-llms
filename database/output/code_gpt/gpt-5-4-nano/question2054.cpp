/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, A, B;
    if (!(cin >> N >> A >> B)) return 0;

    auto sum1to = [](long long x) -> long long {
        return x * (x + 1) / 2;
    };

    long long l = A / std::gcd(A, B) * B;
    long long cntA = N / A;
    long long cntB = N / B;
    long long cntL = N / l;

    long long total = sum1to(N);
    long long bad = A * sum1to(cntA) / 1 + B * sum1to(cntB) / 1 - l * sum1to(cntL) / 1;
    long long good = total - bad;

    cout << good << "\n";
    return 0;
}