/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n1, n2;
    if (!(cin >> n1)) return 0;

    vector<long long> a, b;
    if (n1 < 1) {
        cout << "Erro - A lista deve ter pelo menos 1 elemento.";
        return 0;
    }
    a.resize(n1);
    for (int i = 0; i < n1; i++) cin >> a[i];

    if (!(cin >> n2)) return 0;
    if (n2 < 1) {
        cout << "Erro - A lista deve ter pelo menos 1 elemento.";
        return 0;
    }
    b.resize(n2);
    for (int i = 0; i < n2; i++) cin >> b[i];

    bool first = true;
    for (int i = 0; i < n1; i++) {
        if (!first) cout << ' ';
        cout << a[i];
        first = false;
    }
    for (int i = 0; i < n2; i++) {
        if (!first) cout << ' ';
        cout << b[i];
        first = false;
    }
    return 0;
}