/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> whiteCols(m, 0);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (a[i][j] == 1) {
                whiteCols[j] = 1;
                break;
            }
        }
    }

    vector<int> symbols;
    int j = 0;
    while (j < m) {
        while (j < m && !whiteCols[j]) j++;
        if (j >= m) break;
        int start = j;
        while (j < m && whiteCols[j]) j++;
        int end = j - 1;
        symbols.push_back(start);
        symbols.push_back(end);
    }

    int k = symbols.size() / 2;

    for (int s = 0; s < k; s++) {
        int wStart = symbols[2 * s];
        int wEnd = symbols[2 * s + 1];

        int L;
        if (s == 0) L = 0;
        else {
            int prevEnd = symbols[2 * (s - 1) + 1];
            int gapLen = wStart - prevEnd - 1;
            L = prevEnd + 1 + gapLen / 2;
        }

        int R;
        if (s == k - 1) R = m - 1;
        else {
            int nextStart = symbols[2 * (s + 1)];
            int gapLen = nextStart - wEnd - 1;
            R = wEnd + gapLen / 2;
        }

        if (s) cout << "\n";
        for (int i = 0; i < n; i++) {
            for (int col = L; col <= R; col++) {
                cout << a[i][col] << (col == R ? ' ' : ' ');
            }
            cout << "\n";
        }
        if (s != k - 1) cout << "\n";
    }

    cout << "Foram encontrados " << k << " simbolos!\n";
    return 0;
}