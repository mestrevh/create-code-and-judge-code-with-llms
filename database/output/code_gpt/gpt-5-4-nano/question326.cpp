/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X, Y;
    if (!(cin >> X >> Y)) return 0;

    for (long long i = 1; i <= Y; i++) {
        if (i > 1) {
            if ((i - 1) % X == 0) cout << '\n';
            else cout << ' ';
        }
        cout << i;
    }
    return 0;
}