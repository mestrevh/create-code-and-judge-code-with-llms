/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L1, C1, L2, C2;
    if (!(cin >> L1 >> C1)) return 0;
    cin >> L2 >> C2;

    vector<vector<long long>> A(L1, vector<long long>(C1));
    vector<vector<long long>> B(L2, vector<long long>(C2));

    for (int i = 0; i < L1; i++)
        for (int j = 0; j < C1; j++)
            cin >> A[i][j];

    for (int i = 0; i < L2; i++)
        for (int j = 0; j < C2; j++)
            cin >> B[i][j];

    if (C1 != L2) {
        cout << "impossivel multiplicar";
        return 0;
    }

    vector<vector<long long>> R(L1, vector<long long>(C2, 0));
    for (int i = 0; i < L1; i++) {
        for (int k = 0; k < C1; k++) {
            long long aik = A[i][k];
            for (int j = 0; j < C2; j++) {
                R[i][j] += aik * B[k][j];
            }
        }
    }

    for (int i = 0; i < L1; i++) {
        for (int j = 0; j < C2; j++) {
            if (j) cout << ' ';
            cout << R[i][j];
        }
        if (i + 1 < L1) cout << "\n";
    }
    return 0;
}