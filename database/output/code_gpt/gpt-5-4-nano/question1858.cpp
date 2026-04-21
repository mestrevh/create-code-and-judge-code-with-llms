/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int menorElemento(const int* a) {
    int mn = a[0];
    for (int i = 1; i < 6; i++) mn = min(mn, a[i]);
    return mn;
}

int maiorElemento(const int* a) {
    int mx = a[0];
    for (int i = 1; i < 6; i++) mx = max(mx, a[i]);
    return mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[6];
    for (int i = 0; i < 6; i++) cin >> a[i];

    cout << menorElemento(a) << "\n" << maiorElemento(a) << "\n";
    return 0;
}