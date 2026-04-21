/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    if (!(cin >> A >> B)) return 0;

    int maxN = B + 6;
    vector<bool> isPrime(maxN + 1, true);
    if (maxN >= 0) isPrime[0] = false;
    if (maxN >= 1) isPrime[1] = false;

    for (int i = 2; 1LL * i * i <= maxN; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= maxN; j += i) isPrime[j] = false;
        }
    }

    int best = 0;
    int cur = 0;
    int start = A - (A % 2);

    for (int p = 2; p <= maxN; p += 2) {
        if (p < A) continue;
        if (p >= B) break;
        if (p + 6 <= maxN && isPrime[p] && isPrime[p + 6]) {
            cur++;
            best = max(best, cur);
        } else {
            cur = 0;
        }
    }

    cur = 0;
    best = 0;
    for (int x = A; x <= B - 1; x++) {
        if (x % 2 == 1) continue;
        if (x + 6 <= maxN && isPrime[x] && isPrime[x + 6]) {
            cur++;
            best = max(best, cur);
        } else {
            cur = 0;
        }
    }

    cout << best << "\n";
    return 0;
}