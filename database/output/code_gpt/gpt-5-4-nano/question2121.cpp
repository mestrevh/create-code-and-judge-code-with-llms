/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, C;
    if (!(cin >> L >> C)) return 0;

    vector<vector<int>> a(L, vector<int>(C, 0));
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            string s;
            cin >> s;
            if (s == "verde") a[i][j] = 0;
            else if (s == "amarelo") a[i][j] = 1;
            else a[i][j] = 2;
        }
    }

    int S;
    cin >> S;

    for (int k = 0; k < S; k++) {
        int X, Y;
        cin >> X >> Y;
        --X; --Y;
        if (X >= 0 && X < L && Y >= 0 && Y < C) {
            if (a[X][Y] == 1) a[X][Y] = 0;
            else if (a[X][Y] == 2) a[X][Y] = 1;
        }
    }

    long long excelentes = 0;
    long long repelente = 0;

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            if (a[i][j] == 0) excelentes++;
            else if (a[i][j] == 1) repelente += 3;
        }
    }

    long long lucro = excelentes * 4 - repelente;
    if (lucro <= 0) cout << "prejuizo";
    else cout << lucro;

    return 0;
}