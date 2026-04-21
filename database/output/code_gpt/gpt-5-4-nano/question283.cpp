/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int L, U;
    if (!(cin >> L >> U)) return 0;

    if (U < 2 || U <= L) {
        cout << -1 << "\n";
        return 0;
    }

    int maxN = U;
    vector<bool> isPrime(maxN + 1, true);
    if (maxN >= 0) isPrime[0] = false;
    if (maxN >= 1) isPrime[1] = false;
    for (int i = 2; 1LL * i * i <= maxN; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= maxN; j += i) isPrime[j] = false;
        }
    }

    vector<int> primes;
    for (int x = max(2, L); x <= U; x++) {
        if (isPrime[x]) primes.push_back(x);
    }

    if (primes.size() < 3) {
        cout << -1 << "\n";
        return 0;
    }

    unordered_map<int,int> cnt;
    int bestFreq = 0;
    int bestGap = -1;

    for (size_t i = 1; i < primes.size(); i++) {
        int gap = primes[i] - primes[i - 1];
        int f = ++cnt[gap];
        if (f > bestFreq) {
            bestFreq = f;
            bestGap = gap;
        } else if (f == bestFreq && f > 1 && gap < bestGap) {
            bestGap = gap;
        }
    }

    if (bestFreq <= 1) cout << -1 << "\n";
    else cout << bestGap << "\n";

    return 0;
}