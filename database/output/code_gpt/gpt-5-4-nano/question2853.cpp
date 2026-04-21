/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, c;
    cout << "Digite as dimensoes da matriz:\n";
    if (!(cin >> l >> c)) return 0;

    vector<vector<long long>> a(l, vector<long long>(c));
    cout << "Digite os elementos da matriz:\n";
    for (int i = 0; i < l; ++i)
        for (int j = 0; j < c; ++j)
            cin >> a[i][j];

    cout << "Matriz transposta:\n";
    for (int j = 0; j < c; ++j) {
        for (int i = 0; i < l; ++i) {
            cout << left << setw(6) << a[i][j];
        }
        cout << "\n";
    }

    return 0;
}