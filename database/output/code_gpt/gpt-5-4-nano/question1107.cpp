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
    vector<vector<long long>> a(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    bool ok = true;
    for (int i = 0; i < n && ok; i++) {
        int ones = 0;
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) ones++;
            else if (a[i][j] != 0) ok = false;
        }
        if (ones != 1) ok = false;
    }

    for (int j = 0; j < n && ok; j++) {
        int ones = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][j] == 1) ones++;
            else if (a[i][j] != 0) ok = false;
        }
        if (ones != 1) ok = false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j) cout << ' ';
            cout << a[i][j];
        }
        cout << "\n";
    }
    cout << (ok ? "True" : "False") << "\n";
    return 0;
}