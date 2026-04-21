/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long minHoursRec(long long E, long long X, long long N, long long h) {
    if (h == 0) return 0;
    __int128 total = (__int128)N * h * (2 * X + 100 * (h - 1)) / 200;
    if (total >= E) return h;
    return minHoursRec(E, X, N, h - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long E, X, N;
    if (!(cin >> E >> X >> N)) return 0;

    long long lo = 0, hi = 1;
    while (true) {
        __int128 total = (__int128)N * hi * (2 * X + 100 * (hi - 1)) / 200;
        if (total >= E) break;
        hi *= 2;
    }

    while (lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        __int128 total = (__int128)N * mid * (2 * X + 100 * (mid - 1)) / 200;
        if (total >= E) hi = mid;
        else lo = mid;
    }

    long long H = hi;
    if (H > 0) {
        long long possibleLower = minHoursRec(E, X, N, H - 1);
        if (possibleLower == H - 1) H = possibleLower + 1;
    }

    cout << "Precisamos de " << H << " horas para conseguirmos imprimir " << E << " euros.";
    return 0;
}