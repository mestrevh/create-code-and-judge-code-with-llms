/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<vector<double>> a(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int r1, r2;
    cin >> r1 >> r2;
    int startRow = min(r1, r2) - 1;
    int endRow = max(r1, r2) - 1;

    int c1, c2;
    cin >> c1 >> c2;
    int startCol = min(c1, c2) - 1;
    int endCol = max(c1, c2) - 1;

    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    for (int i = startRow; i <= endRow; i++) {
        for (int j = startCol; j <= endCol; j++) {
            if (j > startCol) cout << ' ';
            cout << a[i][j];
        }
        if (i < endRow) cout << "\n";
    }

    return 0;
}