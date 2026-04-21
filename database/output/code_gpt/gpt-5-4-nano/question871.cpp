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

    vector<vector<long long>> a(L, vector<long long>(C));
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Matriz formada:\n";
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            if (j) cout << ' ';
            cout << a[i][j];
        }
        cout << "\n";
    }

    if (L == C) {
        long long sumMain = 0, sumSec = 0;
        for (int i = 0; i < L; i++) {
            sumMain += a[i][i];
            sumSec += a[i][C - 1 - i];
        }
        cout << "A diagonal principal e secundaria tem valor(es) " << sumMain << " e " << sumSec << " respectivamente.\n";
    } else {
        cout << "A diagonal principal e secundaria nao pode ser obtida.\n";
    }

    int menoresZero = 0, maioresZero = 0;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            if (a[i][j] < 0) menoresZero++;
            else if (a[i][j] > 0) maioresZero++;
        }
    }

    cout << "A matriz possui " << menoresZero << " numero(s) menor(es) que zero.\n";
    cout << "A matriz possui " << maioresZero << " numero(s) maior(es) que zero.\n";

    return 0;
}