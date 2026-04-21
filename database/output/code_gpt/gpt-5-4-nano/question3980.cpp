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
    bool first = true;
    while (cin >> n) {
        if (!first) cout << ' ';
        first = false;

        if (n < 0) {
            cout << 0;
            continue;
        }
        unsigned long long fact = 1;
        for (unsigned long long i = 2; i <= (unsigned long long)n; ++i) fact *= i;
        cout << fact;
    }
    return 0;
}