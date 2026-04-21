/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static long long gcdll(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    long long lcm = 1;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        long long g = gcdll(lcm, x);
        __int128 tmp = (__int128)(lcm / g) * x;
        if (tmp > LLONG_MAX) {
            lcm = (long long)tmp;
        } else if (tmp < LLONG_MIN) {
            lcm = (long long)tmp;
        } else {
            lcm = (long long)tmp;
        }
    }

    if (lcm < 0) lcm = -lcm;
    cout << lcm;
    return 0;
}