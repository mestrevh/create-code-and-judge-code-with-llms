/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a(10), b(10), c(10);
    for (int i = 0; i < 10; i++) {
        if (!(cin >> a[i])) return 0;
    }
    for (int i = 0; i < 10; i++) {
        if (!(cin >> b[i])) return 0;
    }
    for (int i = 0; i < 10; i++) c[i] = a[i] + b[i];

    for (int i = 0; i < 10; i++) {
        if (i) cout << ' ';
        cout << c[i];
    }
    return 0;
}