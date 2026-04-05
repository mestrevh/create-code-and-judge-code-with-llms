/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isPrimeInRange(int n, int l, int r) {
    for (int p = max(2, l); p <= r; p++) {
        bool prime = true;
        if (p < 2) continue;
        for (int d = 2; (long long)d * d <= p; d++) {
            if (p % d == 0) { prime = false; break; }
        }
        if (prime && n == p) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> id(5), w(5);
    for (int i = 0; i < 5; i++) {
        if (!(cin >> id[i] >> w[i])) return 0;
    }
    long long total;
    cin >> total;

    bool prime3to10[11] = {};
    for (int p = 3; p <= 10; p++) {
        bool prime = true;
        if (p < 2) prime = false;
        for (int d = 2; d * d <= p && prime; d++) {
            if (p % d == 0) prime = false;
        }
        if (prime) prime3to10[p] = true;
    }

    bool prime11to20[21] = {};
    for (int p = 11; p <= 20; p++) {
        bool prime = true;
        if (p < 2) prime = false;
        for (int d = 2; d * d <= p && prime; d++) {
            if (p % d == 0) prime = false;
        }
        if (prime) prime11to20[p] = true;
    }

    long long expected = 0;
    for (int i = 0; i < 5; i++) {
        long long ID = id[i];
        long long peso = w[i];

        long long pontos = peso * ID;

        if (ID % 2 == 0) {
            bool mult = false;
            for (int p = 3; p <= 10; p++) {
                if (prime3to10[p] && ID % p == 0) { mult = true; break; }
            }
            if (mult) pontos = pontos * 2;
        }

        if (pontos % 2 == 1) {
            bool mult = false;
            for (int p = 11; p <= 20; p++) {
                if (prime11to20[p] && (pontos % p == 0)) { mult = true; break; }
            }
            if (mult) pontos /= 2;
        }

        if (ID % 17 == 0 && ID % 2 == 0) pontos = 0;

        expected += pontos;
    }

    if (total > expected) cout << "UEPAAA TEMOS UM RATINHO";
    else cout << "barra limpa, khan";

    return 0;
}