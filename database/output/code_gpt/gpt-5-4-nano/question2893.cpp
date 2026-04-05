/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<double> fx;
    for (double x = -5.0; x <= 5.0 + 1e-12; x += 0.5) {
        fx.push_back(sin(x + 0.5));
    }

    cout << "fx =";
    cout << "\n\n";
    cout.setf(ios::fixed);
    cout << setprecision(5);

    int n = (int)fx.size();
    int colsFirst = min(8, n);
    for (int i = 0; i < colsFirst; i++) {
        if (i == 0) cout << " ";
        cout << setw(9) << fx[i];
        if (i != colsFirst - 1) {
            cout << " ";
        } else {
            cout << "\n\n";
        }
    }

    int idx = colsFirst;
    int colInRow = 0;
    bool firstRow = false;
    while (idx < n) {
        colInRow = 0;
        for (; colInRow < 8 && idx < n; colInRow++, idx++) {
            if (colInRow == 0) cout << " Columns 1 through " << (8 + (colInRow - 0)) << ":\n\n";
            cout << setw(9) << fx[idx];
            if (colInRow != 7 && idx < n) cout << " ";
        }
        if (idx >= n) break;
        if (idx < n) {
            cout << "\n\n";
            int start = idx - colInRow;
            int end = min(n, start + 8) - 1;
            int left = end - (start) + 1;
        }
    }

    cout.flush();
    return 0;
}