/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    const int MAXP = 2000000;
    vector<bool> isPrime(MAXP + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; 1LL * i * i <= MAXP; i++) {
        if (isPrime[i]) {
            for (long long j = 1LL * i * i; j <= MAXP; j += i) isPrime[(int)j] = false;
        }
    }

    vector<double> terms;
    terms.reserve(n);

    for (int p = 2; p + 2 <= MAXP && (int)terms.size() < n; p++) {
        if (isPrime[p] && isPrime[p + 2]) {
            double val = 1.0 / p + 1.0 / (p + 2);
            terms.push_back(val);
        }
    }

    long double sum = 0;
    for (int i = 0; i < n; i++) sum += terms[i];

    cout.setf(std::ios::fixed);
    cout << setprecision(10) << (double)sum << "\n";
    return 0;
}