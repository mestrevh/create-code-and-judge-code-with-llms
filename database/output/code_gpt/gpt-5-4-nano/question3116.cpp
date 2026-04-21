/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static long long max2_no_if(long long a, long long b) {
    long long diff = a - b;
    long long ad = diff >= 0 ? diff : -diff;
    return (a + b + ad) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long A, L, P, H;
    if (!(cin >> A)) return 0;
    cin >> L >> P;
    cin >> H;
    long long a = A * H;
    long long l = L * H;
    long long p = P * H;
    long long m1 = max2_no_if(a, l);
    long long m2 = max2_no_if(m1, p);
    cout << m2 << "\n";
    return 0;
}