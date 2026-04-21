/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;
int cntPrimes[MAXN];
bool isPrime[MAXN];

void sieve() {
    for (int i = 2; i < MAXN; ++i) isPrime[i] = true;
    for (int p = 2; p * p < MAXN; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i < MAXN; i += p)
                isPrime[i] = false;
        }
    }
    cntPrimes[0] = 0;
    for (int i = 1; i < MAXN; i++) {
        cntPrimes[i] = cntPrimes[i - 1] + (isPrime[i] ? 1 : 0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        long long A, B;
        if (!(cin >> A >> B)) break;

        long long L = (long long)sqrt(A);
        if (L < 0) L = 0;
        while (L * L < A) L++;
        while (L > 0 && (L - 1) * (L - 1) >= A) L--;

        long long R = (long long)sqrt(B);
        while ((R + 1) * (R + 1) <= B) R++;
        while (R * R > B) R--;

        if (L > R || R < 2) {
            cout << 0 << "\n";
        } else {
            // L and R can be at most 10^6.
            // Clamp L to at least 0 for safety in array indexing
            if (L < 1) L = 1;
            if (R >= MAXN) R = MAXN - 1;
            
            cout << cntPrimes[R] - cntPrimes[L - 1] << "\n";
        }
    }

    return 0;
}

