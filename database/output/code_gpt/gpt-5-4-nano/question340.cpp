/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, K;
    if (!(cin >> N >> K)) return 0;

    if (N <= 1) {
        cout << 0 << "\n";
        return 0;
    }

    long long totalNeeded = N - 1;
    long long t = 0;
    while (true) {
        __int128 capacity = (__int128)K * (__int128)t + (__int128)(t * (t - 1) / 2);
        if (capacity >= totalNeeded) break;
        t++;
    }

    cout << t << "\n";
    return 0;
}