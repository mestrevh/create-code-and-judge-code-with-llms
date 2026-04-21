/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, L, P;
    if (!(cin >> A >> L >> P)) return 0;
    long long H;
    cin >> H;

    long long a = A * H;
    long long b = L * H;
    long long c = P * H;

    auto max2 = [&](long long x, long long y) -> long long {
        long long t = x - y;
        long long absT = llabs(t);
        return (x + y + absT) / 2;
    };

    long long m = max2(a, b);
    m = max2(m, c);

    cout << m << "\n";
    return 0;
}