/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    if (!(cin >> a >> b)) return 0;

    if (b == 0) return 0;

    long long sign = 1;
    if ((a < 0) ^ (b < 0)) sign = -1;

    unsigned long long ua = a < 0 ? (unsigned long long)(-a) : (unsigned long long)a;
    unsigned long long ub = b < 0 ? (unsigned long long)(-b) : (unsigned long long)b;

    unsigned long long q = 0;
    unsigned long long rem = ua;

    while (rem >= ub) {
        unsigned long long temp = ub;
        unsigned long long mult = 1;
        while ((temp << 1) > temp && (temp << 1) <= rem) {
            temp <<= 1;
            mult <<= 1;
        }
        rem -= temp;
        q += mult;
    }

    long long res;
    if (q > (unsigned long long)LLONG_MAX) res = sign < 0 ? LLONG_MIN : LLONG_MAX;
    else res = sign < 0 ? -(long long)q : (long long)q;

    cout << res << "\n";
    return 0;
}