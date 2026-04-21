/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0) return false;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

static long long sumDivisorsExcludingSelf(long long n) {
    if (n <= 1) return 0;
    long long sum = 1;
    long long temp = n;
    for (long long p = 2; p * p <= temp; ++p) {
        if (temp % p == 0) {
            long long pow = 1;
            long long term = 1;
            while (temp % p == 0) {
                temp /= p;
                pow *= p;
                term += pow;
            }
            sum += term;
        }
    }
    if (temp > 1) {
        sum += 1 + temp;
    }
    return sum - n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    bool hasPrime = false;
    long long maxPrime = LLONG_MIN;

    bool hasNonPrime = false;
    long long minNonPrimeSum = LLONG_MAX;

    while (cin >> x) {
        if (x <= 0) break;
        if (isPrime(x)) {
            hasPrime = true;
            maxPrime = max(maxPrime, x);
        } else {
            hasNonPrime = true;
            long long s = sumDivisorsExcludingSelf(x);
            minNonPrimeSum = min(minNonPrimeSum, s);
        }
    }

    if (hasPrime) {
        cout << "Maior numero primo: " << maxPrime << "\n";
    } else {
        cout << "Nenhum numero primo foi digitado\n";
    }

    if (hasNonPrime) {
        cout << "A Menor soma dos divisores: " << minNonPrimeSum << "\n";
    } else {
        cout << "Nenhum numero nao primo foi digitado\n";
    }

    if (hasPrime && hasNonPrime) {
        if (maxPrime > 3LL * minNonPrimeSum) {
            cout << "Deu a logica, Computos campeao!" << "\n";
        } else {
            cout << "eh mafiaaaaa!" << "\n";
        }
    } else {
        cout << "eh mafiaaaaa!" << "\n";
    }

    return 0;
}