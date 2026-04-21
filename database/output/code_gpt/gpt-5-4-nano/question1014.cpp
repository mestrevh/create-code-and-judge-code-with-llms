/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static inline bool isPrime(int n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    for (int p = 3; (long long)p * p <= n; p += 2)
        if (n % p == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        cin >> N;

        if (isPrime(N)) {
            cout << "Primo\n";
            continue;
        }
        if (N < 4) {
            cout << "Nem primo nem quase primo\n";
            continue;
        }

        int n = N;
        int first = -1, second = -1;
        for (int p = 2; (long long)p * p <= n; ++p) {
            if (n % p == 0) {
                int cnt = 0;
                while (n % p == 0) {
                    n /= p;
                    cnt++;
                }
                if (cnt != 1) {
                    first = -2;
                    break;
                }
                if (first == -1) first = p;
                else if (second == -1) second = p;
                else {
                    first = -2;
                    break;
                }
            }
        }
        if (first == -2) {
            cout << "Nem primo nem quase primo\n";
            continue;
        }

        if (n > 1) {
            if (second == -1) {
                if (first == -1) {
                    first = n;
                } else {
                    second = n;
                }
            } else {
                first = -2;
            }
        }

        if (first >= 2 && second >= 2 && first != second && isPrime(first) && isPrime(second)) {
            cout << "Quase primo\n";
        } else {
            cout << "Nem primo nem quase primo\n";
        }
    }
    return 0;
}