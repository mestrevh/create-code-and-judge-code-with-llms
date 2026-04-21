/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, C;
    if (!(cin >> A >> C)) return 0;

    for (long long i = 0; i < C; ++i) {
        if (30 % (A + 1) == 0) {
            cout << "Curvou";
        } else {
            cout << "Pedro se cagou todo e foi pego.";
            return 0;
        }
        cout << "\n";
        A += 1;
    }

    return 0;
}