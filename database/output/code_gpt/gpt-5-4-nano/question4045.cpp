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

    vector<vector<string>> a(n, vector<string>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!(cin >> a[i][j])) return 0;
        }
    }

    string q;
    bool firstOutput = true;

    while (cin >> q) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j].find(q) != string::npos) {
                    if (!firstOutput) cout << "\n";
                    cout << "(" << i << "," << j << ")";
                    firstOutput = false;
                }
            }
        }
    }

    return 0;
}