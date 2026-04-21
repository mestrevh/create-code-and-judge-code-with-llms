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
    if (!(cin >> N)) return 0;
    cin >> A >> B;

    long long lcm = A / std::gcd(A, B) * B;
    auto sum1toN = N * (N + 1) / 2;
    long long cntA = N / A;
    long long cntB = N / B;
    long long cntL = N / lcm;

    auto sumMultiples = [&](long long d, long long cnt) -> long long {
        return d * cnt * (cnt + 1) / 2;
    };

    long long sub = sumMultiples(A, cntA) + sumMultiples(B, cntB) - sumMultiples(lcm, cntL);
    long long ans = sum1toN - sub;

    if (ans % 2 == 0) {
        cout << "Lá ele!!!";
    } else {
        cout << "Opa xupenio AULAS...";
    }

    return 0;
}