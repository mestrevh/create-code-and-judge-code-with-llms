/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string word;
    if (!getline(cin, word)) return 0;

    long long sumWord = 0;
    for (unsigned char c : word) sumWord += (long long)c;

    auto factorDistinct = [&](long long n) {
        vector<long long> primes;
        for (long long p = 2; p * p <= n; ++p) {
            if (n % p == 0) {
                primes.push_back(p);
                while (n % p == 0) n /= p;
            }
        }
        if (n > 1) primes.push_back(n);
        return primes;
    };

    if (sumWord % 17 == 0) {
        cout << "Agora estou Putin, Bonxai!\n";
        return 0;
    }

    vector<long long> primes = factorDistinct(sumWord);
    if (sumWord % 3 == 0) {
        bool ok = false;
        int cnt = 0;
        for (long long p : primes) {
            if (p == 2) continue;
            if (p != 2) cnt++;
        }
        int distinctPrimeCount = (int)primes.size();
        if (distinctPrimeCount >= 3) {
            long long t = sumWord;
            for (long long p : primes) {
                if (t % p == 0) {
                    cnt++;
                }
            }
        }
        if (distinctPrimeCount >= 3) ok = true;
        else ok = false;
        if (ok) sumWord *= 3;
    }

    int attempts = 0;
    long long guessSum = 0;

    while (attempts < 6) {
        long long g;
        if (!(cin >> g)) break;
        guessSum += g;
        attempts++;
        if (guessSum > sumWord) {
            cout << "Agora voce passou dos limites!\n";
            return 0;
        }
        if (guessSum == sumWord) break;
    }

    if (guessSum == sumWord) {
        cout << "Parabueins! Voce ajudou Bonxai a escapar.\n";
        return 0;
    }

    cout << "Bonxai foi de base.\n";
    return 0;
}