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

    const int MAX = 2000;
    vector<long long> primes;
    vector<bool> isPrime(MAX + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * 1LL * i <= MAX; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX; j += i) isPrime[j] = false;
        }
    }
    for (int i = 2; i <= MAX; i++) if (isPrime[i]) primes.push_back(i);

    vector<long long> zeca(MAX + 1, 0);
    for (size_t i = 1; i + 1 < primes.size(); i++) {
        long long p = (primes[i - 1] + primes[i + 1]) / 2;
        if (p >= 2 && p <= MAX) zeca[p] = 1;
    }

    int cnt = 0;
    for (int x = (int)max<long long>(2, a); x <= b; x++) {
        if (zeca[x]) cnt++;
    }
    cout << cnt << "\n";
    return 0;
}