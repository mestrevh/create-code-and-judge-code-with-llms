/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    if (!(cin >> n)) return 0;

    bool first = true;
    for (long long i = 1; i <= n; i++) {
        bool isPrime = true;
        if (i < 2) isPrime = false;
        else {
            for (long long d = 2; d * d <= i; d++) {
                if (i % d == 0) {
                    isPrime = false;
                    break;
                }
            }
        }

        if (!isPrime) {
            if (!first) cout << ' ';
            cout << i;
            first = false;
        }
    }
    return 0;
}