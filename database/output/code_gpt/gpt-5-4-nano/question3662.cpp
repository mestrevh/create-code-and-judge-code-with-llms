/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int I, J;
    if (!(cin >> I >> J)) return 0;

    vector<vector<long long>> a(I, vector<long long>(J));
    vector<long long> sumRow(I, 0), sumCol(J, 0);
    long long diag = 0;

    for (int i = 0; i < I; i++) {
        for (int j = 0; j < J; j++) {
            long long x;
            cin >> x;
            a[i][j] = x;
            sumRow[i] += x;
            sumCol[j] += x;
        }
    }

    if (I == J) {
        for (int i = 0; i < I; i++) diag += a[i][i];
    }

    for (int i = 0; i < I; i++) {
        cout << "Linha " << i << ": " << sumRow[i] << "\n";
    }
    for (int j = 0; j < J; j++) {
        cout << "Coluna " << j << ": " << sumCol[j] << "\n";
    }
    if (I == J) {
        cout << "Diagonal principal: " << diag << "\n";
    }

    return 0;
}