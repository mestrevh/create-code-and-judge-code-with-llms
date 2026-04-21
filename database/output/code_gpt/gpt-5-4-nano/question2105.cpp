/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> vals;
    int x;
    while (cin >> x) vals.push_back(x);

    int total = (int)vals.size();
    if (total % 9 != 0) return 0;

    int n = total / 9;
    for (int k = 0; k < n; k++) {
        int a[3][3];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                a[i][j] = vals[k * 9 + i * 3 + j];

        bool upper = true;    // triangular superior: abaixo da diagonal sólida
        bool lower = true;    // triangular inferior: acima da diagonal sólida
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i > j && a[i][j] == 0) upper = false;
                if (i < j && a[i][j] == 0) lower = false;
            }
        }

        if (upper) {
            cout << "Por baixo";
        } else if (lower) {
            cout << "Por cima";
        } else {
            cout << "Nao pode atravessar";
        }
        if (k + 1 < n) cout << "\n";
    }

    return 0;
}