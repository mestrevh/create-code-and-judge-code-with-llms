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

    long double prod = 1.0L;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            long double x;
            cin >> x;
            if (i == j) prod *= x;
        }
    }

    cout << fixed << setprecision(10) << (double)prod;
    return 0;
}