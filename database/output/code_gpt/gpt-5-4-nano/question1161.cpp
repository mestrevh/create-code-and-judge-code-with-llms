/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, L, P;
    if (!(cin >> A >> L >> P)) return 0;
    long long H;
    cin >> H;

    long long a = A * H;
    long long b = L * H;
    long long c = P * H;

    auto max2 = [](long long x, long long y) -> long long {
        long long diff = llabs(x - y);
        return (x + y + diff) / 2;
    };

    long long m = max2(max2(a, b), c);
    cout << m;
    return 0;
}