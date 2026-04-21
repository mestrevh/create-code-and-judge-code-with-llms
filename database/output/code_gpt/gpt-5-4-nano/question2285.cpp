/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<string>> A(3, vector<string>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!(cin >> A[i][j])) return 0;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j) cout << ' ';
            cout << A[j][i];
        }
        if (i < 2) cout << '\n';
    }
    return 0;
}