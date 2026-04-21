/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X;
    if (!(cin >> X)) return 0;

    long long letters = 0;
    long long digits = 0;
    for (long long i = 0; i < X; i++) {
        string s;
        cin >> s;
        char c = s.empty() ? 0 : s[0];
        if (c >= 'a' && c <= 'z') letters++;
        else if (c >= '1' && c <= '9') digits++;
    }

    long long K;
    cin >> K;

    vector<bool> isPrime(K + 1, true);
    if (K >= 0) isPrime[0] = false;
    if (K >= 1) isPrime[1] = false;
    for (long long i = 2; i * i <= K; i++) {
        if (!isPrime[i]) continue;
        for (long long j = i * i; j <= K; j += i) isPrime[j] = false;
    }

    auto powll = [&](long long base, long long exp) -> long long {
        __int128 res = 1;
        __int128 b = base;
        while (exp > 0) {
            if (exp & 1) res *= b;
            exp >>= 1;
            if (exp) b *= b;
        }
        long long ans = (long long)res;
        return ans;
    };

    for (long long n = 1; n <= K; n++) {
        long long seq = 0, num = 0;
        if (!isPrime[n]) seq = powll(letters, n);
        if (isPrime[n]) num = powll(digits, n);

        cout << "Tamanho " << n << ":\n";
        cout << "Sequencias: " << seq << ", Numeros: " << num << "\n";
    }

    return 0;
}