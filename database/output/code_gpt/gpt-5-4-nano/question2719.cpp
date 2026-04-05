/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int prod[20][12];
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 12; j++) {
            if (!(cin >> prod[i][j])) return 0;
        }
    }

    int m1, y1, m2, y2;
    cin >> m1 >> y1;
    cin >> m2 >> y2;

    int startYear = 2000;
    auto idx = [&](int y) { return y - startYear; };

    long long total = 0;

    if (y1 == y2) {
        for (int m = m1; m <= m2; m++) total += prod[idx(y1)][m-1];
    } else {
        for (int m = m1; m <= 12; m++) total += prod[idx(y1)][m-1];
        for (int y = y1 + 1; y <= y2 - 1; y++) {
            for (int m = 1; m <= 12; m++) total += prod[idx(y)][m-1];
        }
        for (int m = 1; m <= m2; m++) total += prod[idx(y2)][m-1];
    }

    cout << total << "\n";
    return 0;
}