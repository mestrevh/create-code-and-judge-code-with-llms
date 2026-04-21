/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long Ai, Aj, Bi, Bj;
    if (!(cin >> Ai >> Aj >> Bi >> Bj)) return 0;

    vector<vector<long long>> A(Ai, vector<long long>(Aj));
    vector<vector<long long>> B(Bi, vector<long long>(Bj));

    for (long long i = 0; i < Ai; i++)
        for (long long j = 0; j < Aj; j++)
            cin >> A[i][j];

    for (long long i = 0; i < Bi; i++)
        for (long long j = 0; j < Bj; j++)
            cin >> B[i][j];

    if (Aj != Bi) {
        cout << "Nao e possivel multiplicar\n";
        return 0;
    }

    vector<vector<long long>> C(Ai, vector<long long>(Bj, 0));
    for (long long i = 0; i < Ai; i++) {
        for (long long k = 0; k < Aj; k++) {
            long long aik = A[i][k];
            for (long long j = 0; j < Bj; j++) {
                C[i][j] += aik * B[k][j];
            }
        }
    }

    for (long long i = 0; i < Ai; i++) {
        for (long long j = 0; j < Bj; j++) {
            if (j) cout << ' ';
            cout << C[i][j];
        }
        cout << "\n";
    }
    return 0;
}