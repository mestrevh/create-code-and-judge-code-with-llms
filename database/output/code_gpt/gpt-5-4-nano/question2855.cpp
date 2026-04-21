/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<vector<long long>> a(N, vector<long long>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> a[i][j];
    }

    long long target = 0;
    for (int j = 0; j < N; j++) target += a[0][j];

    bool ok = true;

    for (int i = 1; i < N && ok; i++) {
        long long s = 0;
        for (int j = 0; j < N; j++) s += a[i][j];
        if (s != target) ok = false;
    }

    for (int j = 0; j < N && ok; j++) {
        long long s = 0;
        for (int i = 0; i < N; i++) s += a[i][j];
        if (s != target) ok = false;
    }

    long long d1 = 0, d2 = 0;
    for (int i = 0; i < N; i++) {
        d1 += a[i][i];
        d2 += a[i][N - 1 - i];
    }
    if (d1 != target || d2 != target) ok = false;

    cout << "Digite a dimensao da matriz quadrada N x N:\n";
    cout << "Digite os elementos da matriz:\n";
    if (ok) cout << "Os elementos FORMAM um quadrado magico.\n";
    else cout << "Os elementos NAO FORMAM um quadrado magico.\n";
    cout << "A soma do quadrado magico e " << target << ".\n";

    return 0;
}