/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int mediaLista(const vector<int>& L) {
    long long soma = 0;
    for (int x : L) soma += x;
    return (int)floor((double)soma / (double)L.size());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> L(n);
    for (int i = 0; i < n; i++) cin >> L[i];

    int m = mediaLista(L);
    double media = 0.0;
    long long soma = 0;
    for (int x : L) soma += x;
    media = (double)soma / (double)n;

    cout << fixed << setprecision(2) << media;
    return 0;
}