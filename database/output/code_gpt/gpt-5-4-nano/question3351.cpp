/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A[3][3], B[3][3], C[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (!(cin >> A[i][j])) return 0;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (!(cin >> B[i][j])) return 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            long long sum = 0;
            for (int k = 0; k < 3; k++) sum += A[i][k] * B[k][j];
            C[i][j] = sum;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j) cout << ' ';
            cout << C[i][j];
        }
        if (i < 2) cout << "\n";
    }
    return 0;
}